/*
 * hash.c
 *
 *  Created on: May 14, 2023
 *      Author: choi
 */
#include "hash.h"

int hashCode(void* key, int len) {
	int h = 0;
	char* _key = (char*)key;
	for(int i = 0; i < len; i++) {
		char c = *(_key + i);
		h = 31 * h + (c & 0xff);
	}
	h = h ^ ((h & 0xffffffff) >> 16);
	return h;
}
