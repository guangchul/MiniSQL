/*
 * mem.c
 *
 *  Created on: Apr 16, 2023
 *      Author: choi
 */
#include "mem.h"
#include <stdlib.h>
#include <string.h>

void* alloc(unsigned int size){
	void* ptr = malloc(size);
	for(int i = 0; i < size; i++){
		memset(ptr + 1, 0, 1);
	}
	return ptr;
}
