/*
 * send.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "server.h"
#include <stdio.h>
#include <sys/socket.h>

ssize_t rawWrite(int connectFd, void *ptr, int len) {
	ssize_t n;
	n = send(connectFd, ptr, len, 0);
	return n;
}


