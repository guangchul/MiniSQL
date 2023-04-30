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

#ifdef WIN
FILE*
#endif
#ifdef LINUX
int
#endif
fileOpen(const char *file, int mode, int perm) {
#ifdef WIN
	FILE* fd = fopen(file, "wb+");
	if(fd->_file <= 0){
#endif
#ifdef LINUX
	int fd;
	if((fd = open(file, mode, perm)) == 0) {
#endif
		printf("cannot open file \"%s\".\n", file);
	}
	return fd;
}

#ifdef WIN
int fileRead(FILE* fd, void* buff, off_t offset, size_t size) {
	if(fseek(fd, offset, SEEK_SET) != offset){
		return -1;
	}
	if(fread(buff, sizeof(char), size, fd) != size) {
		return 0;
	}
#endif
#ifdef LINUX
int fileRead(int fd, void* buff, off_t offset, size_t size) {
	if(lseek(fd, offset, SEEK_SET) != offset) {
		return -1;
	}
	if(read(fd, buff, size) != size) {
		return -1;
	}
#endif


	return 0;
}

#ifdef WIN
int fileWrite(FILE* fd, char *ptr, off_t offset, size_t size) {
	if(fseek(fd, offset, SEEK_SET) != offset){
		return -1;
	}
#endif
#ifdef LINUX
int fileWrite(int fd, char *ptr, off_t offset, size_t size) {
	if(lseek(fd, offset, SEEK_SET) != offset){
		return -1;
	}
#endif
#ifdef WIN
	if(fwrite((void*)ptr, sizeof(char), size, fd) != size) {
#endif
#ifdef LINUX
	if(write(fd, ptr, size) != size) {
#endif
		return -1;
	}
	return 0;
}

int fileClose() {

	return 0;
}
