/*
 * error.c
 *
 *  Created on: May 11, 2023
 *      Author: choi
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"
#include "../util/string.h"
#include "../util/mem.h"

extern int single;

void printError(char* format, ...) {
	char* str = malloc_local(8192);
	int offset = 0;
	va_list args;
	va_start(args, format);
	for(int i = 0; i < strlen(format); i++) {
		char c = *(format + i);
		if(c == '%') {
			if(i + 1 < strlen(format)) {
				char _c = *(format + i + 1);
				if(_c == 'd' || _c == 'D') {
					int ival = va_arg(args, int);
					char* itoaVal = itoa_local(ival);
					int len = strlen(itoaVal);
					memcpy(str + offset, itoaVal, len);
					free(itoaVal);
					offset += len;
					i++;
					continue;
				}
				if(_c == 's' || _c == 'S') {
					char* val = va_arg(args, char*);
					int len = strlen(val);
					memcpy(str + offset, val, len);
					offset += len;
					i++;
					continue;
				}
			}
		}
		*(str + offset) = c;
		offset++;
	}
	if(single == 1) {
		printf("%s\n", str);
	} else {

	}
	free(str);
}
