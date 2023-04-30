/*
 * mem.c
 *
 *  Created on: Apr 16, 2023
 *      Author: choi
 */
#include "mem.h"
#include <stdlib.h>
#include <string.h>

void* malloc_local(unsigned int size){
	void* ptr = malloc(size);
	for(int i = 0; i < size; i++){
		memset(ptr + i, 0, 1);
	}
	return ptr;
}
