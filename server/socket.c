/*
 * socket.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "../global/machine.h"
#ifdef WIN
#include <winsock2.h>
#include <windows.h>
#endif
#ifdef LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#include <fcntl.h>
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include "../util/mem.h"
#include "../global/config.h"

typedef struct sockaddr_in sockaddr_in;

int initServerSocket(int port) {
	int listenFd;
#ifdef LINUX
	int on = 1;
#endif
#ifdef WIN
	WSADATA data;
	WORD w = MAKEWORD(2, 0);
	WSAStartup(w, &data);
#endif
	if((listenFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		printf("create socket err\n");
		exit(0);
	}

	sockaddr_in* server_addr = malloc_local(sizeof(sockaddr_in));
	server_addr->sin_family = AF_INET;
#ifdef LINUX
	int s_addr = htonl(INADDR_ANY);
	server_addr->sin_addr.s_addr = s_addr;
#endif
#ifdef WIN
	server_addr->sin_addr.S_un.S_addr = INADDR_ANY;
#endif
	server_addr->sin_port = htons(port);
#ifdef LINUX
	if(setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
		exit(0);
	}
#endif
	if(bind(listenFd, (struct sockaddr*)server_addr, sizeof(sockaddr_in)) == -1) {
		exit(0);
	}

	if(listen(listenFd, 10) == -1) {
		exit(0);
	}
	return listenFd;
}
#ifdef LINUX
void setServerNonBlocking(int listenFd) {
	int flags;
	flags = fcntl(listenFd, F_GETFL, 0);
	fcntl(listenFd, F_SETFL, flags | O_NONBLOCK);
}
#endif

int connection(int listenFd) {
	struct sockaddr_in client_addr;
#ifdef LINUX
	socklen_t addrlen = sizeof(sockaddr_in);
#endif
#ifdef WIN
	int addrlen = sizeof(sockaddr_in);
#endif
	int connectFd = accept(listenFd, (struct sockaddr*)&client_addr, &addrlen);
	if(connectFd == -1) {
		printf("accept error\n");
		exit(0);
	}
	int on = 1;
	if(setsockopt(connectFd, IPPROTO_TCP, TCP_NODELAY, (char*)&on, sizeof(on)) < 0){
		exit(0);
	}
	on = 1;
	if(setsockopt(connectFd, SOL_SOCKET, SO_KEEPALIVE, (char*)&on, sizeof(on)) < 0) {
		exit(0);
	}
#ifdef WIN
	int oldopt;
	int optlen;
	int newopt;
	optlen = sizeof(oldopt);
	if(getsockopt(connectFd, SOL_SOCKET, SO_SNDBUF, (char*)&oldopt, &optlen) < 0) {
		exit(0);
	}
	newopt = BUFFERS_SIZE * 4;
	if(oldopt < newopt){
		if(setsockopt(connectFd, SOL_SOCKET, SO_SNDBUF, (char*)&newopt, sizeof(newopt)) < 0){
			exit(0);
		}
	}
#endif

	return connectFd;
}
