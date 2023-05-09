/*
 * send.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "../global/machine.h"
#include "server.h"
#include <stdio.h>
#ifdef LINUX
#include <sys/socket.h>
#endif
#ifdef WIN
#include <winsock2.h>
#endif

ssize_t rawWrite(int connectFd, void *ptr, int len) {
	ssize_t n;
	n = send(connectFd, ptr, len, 0);
	return n;
}


