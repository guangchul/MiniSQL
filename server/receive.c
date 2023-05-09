/*
 * receive.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "../util/string.h"
#include "server.h"
#include <sys/socket.h>
#include <stdio.h>
#include "../util/mem.h"
#include "../global/config.h"
#include <stdlib.h>


ssize_t rawRead(int connectFd, void *ptr, int len) {
	ssize_t n;
	n = recv(connectFd, ptr, len, 0);
	return n;
}



int readClientBuff(String* command, Connect* connect) {
	char* buff = malloc_local(BUFFERS_SIZE);
	ssize_t size = rawRead(connect->fd, buff, BUFFERS_SIZE);
	int type = *((int*)buff);
	if(size >= BUFFERS_SIZE) {
		appendStringOffset(command, buff, 5, size);
		for(;;) {
			size = rawRead(connect->fd, buff, BUFFERS_SIZE);
			appendStringOffset(command, buff, 0, size);
			if(size < BUFFERS_SIZE) {
				break;
			}
		}
	} else {
		appendString(command, buff + 5);
	}
	free(buff);
	return type;
}
