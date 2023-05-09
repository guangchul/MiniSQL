/*
 * socket.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */


#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include "../util/mem.h"

typedef struct sockaddr_in sockaddr_in;

int initServerSocket(int port) {
	int listenFd;
	int on = 1;

	if((listenFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		printf("create socket err\n");
		exit(0);
	}

	sockaddr_in* server_addr = malloc_local(sizeof(sockaddr_in));
	server_addr->sin_family = AF_INET;
	int s_addr = htonl(INADDR_ANY);
	server_addr->sin_addr.s_addr = s_addr;
	server_addr->sin_port = htons(port);

	if(setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
		exit(0);
	}

	if(bind(listenFd, (struct sockaddr*)server_addr, sizeof(sockaddr_in)) == -1) {
		exit(0);
	}

	if(listen(listenFd, 10) == -1) {
		exit(0);
	}
	return listenFd;
}

void setServerNonBlocking(int listenFd) {
	int flags;
	flags = fcntl(listenFd, F_GETFL, 0);
	fcntl(listenFd, F_SETFL, flags | O_NONBLOCK);
}

int connection(int listenFd) {
	struct sockaddr_in client_addr;
	socklen_t addrlen = sizeof(sockaddr_in);
	int connectFd = accept(listenFd, (struct sockaddr*)&client_addr, &addrlen);
	if(connectFd == -1) {
		printf("accept error\n");
		exit(0);
	}
	return connectFd;
}
