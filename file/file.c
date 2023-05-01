/*
 * file.c
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../global/machine.h"

#include "file.h"

void makeDir(const char* pathname, mode_t mode) {
#ifdef WIN
	mkdir(pathname);
#endif
#ifdef LINUX
	mkdir(pathname, mode);
#endif
}

int fileOpen(const char *file, int mode, int perm) {
	int fd;
	if((fd = open(file, mode, perm)) == 0) {
		printf("cannot open file \"%s\".\n", file);
	}
	return fd;
}

int fileRead(int fd, void* buff, off_t offset, size_t size) {
	if(lseek(fd, offset, SEEK_SET) != offset) {
		return -1;
	}
	if(read(fd, buff, size) != size) {
		return -1;
	}
	return 0;
}

int fileWrite(int fd, char *ptr, off_t offset, size_t size) {
	if(lseek(fd, offset, SEEK_SET) != offset){
		return -1;
	}
	if(write(fd, ptr, size) != size) {
		return -1;
	}
	return 0;
}

int fileClose() {

	return 0;
}
