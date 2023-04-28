/*
 * dirInit.c
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */
#include <sys/file.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#include "init.h"
#include "../global/global.h"

char* baseDir;

void checkDir() {
	struct stat _stat;
	if(stat(baseDir, &_stat) != 0) {
		if (errno == ENOENT) {
			printf("could not found base direction \"%s\".\n", baseDir);
		} else {
			printf("could not read permissions of directory.\n");
		}
		exit(1);
	}
}

void changeDir() {
	checkDir();
	if (chdir(baseDir) < 0){
		printf("could not change direction to \"%s\".\n", baseDir);
		exit(1);
	}
}

void setDir(int argc, char **argv) {
	int i = 0;
	int found = 0;
	for(; i < argc; i++) {
		if(strcmp(argv[i], "-D") == 0) {
			found = 1;
			break;
		}
	}
	if(found) {
		printf("base direction is \"%s\"\n", argv[i + 1]);
		baseDir = argv[i + 1];
	} else {
		printf("could not found base direction.\n");
		exit(1);
	}
}
