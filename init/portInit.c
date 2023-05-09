/*
 * portInit.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */
#include "init.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getPort(int argc, char **argv) {
	int i = 0;
	int found = 0;
	for(; i < argc; i++) {
		if(strcmp(argv[i], "-P") == 0) {
			found = 1;
			break;
		}
	}
	if(found) {
		printf("server port is \"%s\"\n", argv[i + 1]);
		char* portStr = argv[i + 1];
		return atoi(portStr);
	}
	return 30001;
}
