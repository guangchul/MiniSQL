/*
 * socket.h
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */

#ifndef SERVER_H_
#define SERVER_H_
#include "../util/string.h"
#include <stdio.h>

typedef struct Connect{
	unsigned int fd;
	unsigned int proto;
	char* schema;
	char* userName;
	char* cmdlineOptions;
	char* applicationName;
	char* clientEncoding;
	char* dateStyle;
	char* integerDatetimes;
	char* intervalStyle;
	char* isSuperuser;
	char* serverEncoding;
	char* serverVersion;
	char* sessionAuthorization;
	char* standardConfirmingString;
	char* timeZone;
} Connect;

extern int initServerSocket(int port);
extern void setServerNonBlocking(int listenFd);
extern int connection(int listenFd);
extern void start(int port);
extern int readClientBuff(String* command, Connect* connect);
extern ssize_t rawRead(int connectFd, void *ptr, int len);
extern ssize_t rawWrite(int connectFd, void *ptr, int len);

#endif /* SERVER_H_ */
