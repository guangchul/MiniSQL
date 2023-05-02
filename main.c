/*
 * main.c
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */
#include "init/init.h"
#include "process/process.h"
#include <string.h>
#include <stdlib.h>

void initDir(int argc, char **argv) {
	setDir(argc, argv);
	changeDir();
}


void init(int argc, char **argv){
	initDir(argc, argv);
	initBuffer();
	initTempBufferBlocks();
	initUsingTempBufferBlocks();
}

int main(int argc, char **argv) {
	init(argc, argv);
	for(int i = 0; i < argc; i++) {
		if(strcmp(argv[i], "--initDB") == 0) {
			initDB();
			exit(0);
		}
		if(strcmp(argv[i], "--single") == 0) {
			initSingle();
			processMain(argv[argc - 1]);
			exit(0);
		}
	}
	return 0;
}
