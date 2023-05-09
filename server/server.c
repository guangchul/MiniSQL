/*
 * server.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "../global/machine.h"
#include "server.h"
#ifdef WIN
#include <winsock2.h>
#include <windows.h>
#endif
#ifdef LINUX
#include <sys/select.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../process/process.h"
#include "../util/mem.h"
#include "../global/config.h"
#include <string.h>
#include <stddef.h>
#include "../buffer/buffer.h"

#define CONFIG_GENERIC_COUNT 11

typedef struct ConfigGeneric{
	char* name;
	char* val;
} ConfigGeneric;

ConfigGeneric configGenerics[CONFIG_GENERIC_COUNT] = {
		{"application_name", NULL},
		{"client_encoding", NULL},
		{"DateStyle", NULL},
		{"integer_datetimes", NULL},
		{"IntervalStyle", NULL},
		{"is_superuser", NULL},
		{"server_encoding", NULL},
		{"server_version", NULL},
		{"session_authorization", NULL},
		{"standard_conforming_strings", NULL},
		{"TimeZone", NULL}
};

void setConfigGenerics(Connect* connect) {
	(&configGenerics[0])->val = connect->applicationName;
	(&configGenerics[1])->val = connect->clientEncoding;
	(&configGenerics[2])->val = connect->dateStyle;
	(&configGenerics[3])->val = connect->integerDatetimes;
	(&configGenerics[4])->val = connect->intervalStyle;
	(&configGenerics[5])->val = connect->isSuperuser;
	(&configGenerics[6])->val = connect->serverEncoding;
	(&configGenerics[7])->val = connect->serverVersion;
	(&configGenerics[8])->val = connect->sessionAuthorization;
	(&configGenerics[9])->val = connect->standardConfirmingString;
	(&configGenerics[10])->val = connect->timeZone;
}

int validateConnection(Connect* connect) {
	char* _buff = malloc_local(BUFFERS_SIZE);
	ssize_t size = rawRead(connect->fd, _buff, BUFFERS_SIZE);
	char* buff = malloc_local(size);
	memcpy(buff, _buff, size);
	free(_buff);
	unsigned int proto = 0;//(unsigned int)(*(unsigned int*)(buff + 4));
	for(int i = 0; i < 4; i++){
		proto |= ((unsigned char)(*(buff + 7 - i)) << (i * 8));
	}
	if(proto == ((1234 << 16) | 5679)){
		free(buff);
		char SSLok = 'N';
		if(rawWrite(connect->fd, &SSLok, 1) != 1){
			exit(0);
		}
		return validateConnection(connect);
	}
	connect->proto = proto;
	int result = -1;
	if(proto >> 16 >= 3){
		int offset = 8;
		while(size > offset) {
			char* name = buff + offset;
			if(*name == 0) {
				result = 1;
				break;
			}
			offset = offset + strlen(name) + 1;
			char* val = buff + offset;
			offset = offset + strlen(val) + 1;
			if (strcmp(name, "database") == 0)
				connect->schema = val;
			else if (strcmp(name, "user") == 0)
				connect->userName = val;
			else if (strcmp(name, "options") == 0)
				connect->cmdlineOptions = val;
			else if (strcmp(name, "application_name") == 0)
				connect->applicationName = val;
			else if (strcmp(name, "client_encoding") == 0)
				connect->clientEncoding = val;
		}
		if(result == 1) {
			connect->dateStyle = "ISO, YMD";
			connect->integerDatetimes = "on";
			connect->intervalStyle = "postgres";
			connect->isSuperuser = "on";
			connect->serverEncoding = "UTF8";
			connect->serverVersion = "12.14";
			connect->sessionAuthorization = "postgres";
			connect->standardConfirmingString = "on";
			connect->timeZone = "Asia/Shanghai";
		}
	}
	return result;
}

void makeReplyBuff(Buffer* buffer){
	beginMessage(buffer, 'R');
	appendInt(buffer, 8);
	appendInt(buffer, 0);
	for(int i = 0; i < CONFIG_GENERIC_COUNT; i++) {
		beginMessage(buffer, 'S');
		appendNameValueWithLength(buffer, (&configGenerics[i])->name, (&configGenerics[i])->val);
	}
	beginMessage(buffer, 'K');
	appendIntWithLength(buffer, 2, 30685, 555413388);
	beginMessage(buffer, 'Z');
	appendByteWithLength(buffer, 73);
}

void replyClient(Connect* connect, Buffer* buffer) {
	rawWrite(connect->fd, buffer->data, buffer->len);
	free(buffer->data);
	free(buffer);
}
#ifdef WIN
DWORD APIENTRY newThread(LPVOID threadArg) {
	Connect* connect = (Connect*)threadArg;
	int validate = validateConnection(connect);
	if(validate == 1) {
		setConfigGenerics(connect);
		Buffer* buffer = malloc_local(sizeof(Buffer));
		buffer->data = malloc_local(BUFFERS_SIZE);
		makeReplyBuff(buffer);
		replyClient(connect, buffer);
		setConnect(connect);
		processMain(connect->schema);
	}
	return 0;
}
#endif
void serverLoop(int listenFd) {
	fd_set rdset, tmp;
	FD_ZERO(&rdset);
	FD_SET(listenFd, &rdset);
	int maxFd = listenFd;
	for(;;){
		tmp = rdset;
		int ret = select(maxFd + 1, &tmp, (void *)0, (void *)0, (void *)0);
		if(ret == -1) {
			printf("select error\n");
			exit(0);
		} else if(ret == 0) {
			continue;
		} else if(ret > 0) {
			int connectFd = connection(listenFd);
#ifdef LINUX
			pid_t pid = fork();
			if(pid == 0) {
				Connect* connect = malloc_local(sizeof(Connect));
				connect->fd = connectFd;
				int validate = validateConnection(connect);
				if(validate == 1) {
					setConfigGenerics(connect);
					Buffer* buffer = malloc_local(sizeof(Buffer));
					buffer->data = malloc_local(BUFFERS_SIZE);
					makeReplyBuff(buffer);
					replyClient(connect, buffer);
					setConnect(connect);
					processMain(connect->schema);
				}
			}
#endif
#ifdef WIN
			HANDLE hThread;
			DWORD ThreadID;
			Connect* connect = malloc_local(sizeof(Connect));
			connect->fd = connectFd;
			hThread = CreateThread(NULL, 0L, newThread, connect, 0L, &ThreadID);
			if(hThread == NULL) {
				exit(0);
			}
#endif
		}
	}
}


void start(int port) {
	int listenFd = initServerSocket(port);
#ifdef LINUX
	setServerNonBlocking(listenFd);
#endif
	serverLoop(listenFd);
}
