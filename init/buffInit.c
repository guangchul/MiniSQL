/*
 * buffInit.c
 *
 *  Created on: Apr 11, 2023
 *      Author: choi
 */
#include "../global/global.h"
#include "../global/config.h"
#include "../util/mem.h"
#include "init.h"
#include <stdlib.h>

char* BufferBlocks;
char* TempBufferBlocks;
int usingTempBufferBlocks[BLOCKS_SIZE]; //0 is free; 1 is using.


void initBuffer() {
	if(BufferBlocks == (void*)0) {
		BufferBlocks = malloc_local(BLOCKS_SIZE * BUFFERS_SIZE);
	}
}

void initTempBufferBlocks() {
	if(TempBufferBlocks == (void*)0) {
		TempBufferBlocks = malloc_local(BLOCKS_SIZE * BUFFERS_SIZE);
	}
}

void initUsingTempBufferBlocks() {
	for(int i = 0; i < BLOCKS_SIZE; i++) {
		usingTempBufferBlocks[i] = 0;
	}
}
