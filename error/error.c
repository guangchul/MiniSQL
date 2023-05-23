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
#include "../buffer/buffer.h"
#include "../global/config.h"
#include "../server/server.h"

extern int single;
extern Connect* connect;

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
		Buffer* buffer = malloc_local(sizeof(Buffer));
		buffer->data = malloc_local(BUFFERS_SIZE);
		beginMessage(buffer, 'E');
		appendInt(buffer, 0);
		beginMessage(buffer, 'S');
		appendValue(buffer, "ERROR");
		beginMessage(buffer, 'V');
		appendValue(buffer, "ERROR");
		beginMessage(buffer, 'C');
		appendValue(buffer, "10001");
		beginMessage(buffer, 'M');
		appendValue(buffer, str);
		beginMessage(buffer, 'P');
		appendValue(buffer, "1");
		beginMessage(buffer, 'F');
		appendValue(buffer, "process.c");
		beginMessage(buffer, 'L');
		appendValue(buffer, "10");
		beginMessage(buffer, 'R');
		appendValue(buffer, "analyze");
		buffer->off++;
		buffer->len++;
		int tempOff = buffer->off;
		int tempLen = buffer->len;
		buffer->off = 1;
		appendInt(buffer, buffer->len - 1);
		buffer->off = tempOff;
		buffer->len = tempLen;
		rawWrite(connect->fd, buffer->data, buffer->len);
		buffer->off = 0;
		buffer->len = 0;
		beginMessage(buffer, 'Z');
		appendByteWithLength(buffer, 73);
		rawWrite(connect->fd, buffer->data, buffer->len);
		free(buffer->data);
		free(buffer);
	}
	free(str);
}
