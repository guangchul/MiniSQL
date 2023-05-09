/*
 * buffer.c
 *
 *  Created on: May 8, 2023
 *      Author: choi
 */


#include "buffer.h"
#include <string.h>
#include <stdarg.h>

void beginMessage(Buffer* buffer, char ch) {
	*(buffer->data + buffer->off) = ch;
	buffer->off++;
	buffer->len = buffer->off;
}

void appendInt(Buffer* buffer, int in) {
	for(int i = 0; i < 4; i++) {
		*(buffer->data + buffer->off) = (in >> ((3 - i) * 8));
		buffer->off++;
	}
	buffer->len = buffer->off;
}

void appendShort(Buffer* buffer, short sh) {
	for(int i = 0; i < 2; i++) {
		*(buffer->data + buffer->off) = (sh >> ((1 - i) * 8));
		buffer->off++;
	}
	buffer->len = buffer->off;
}

void appendValue(Buffer* buffer, char* val) {
	memcpy(buffer->data + buffer->off, val, strlen(val));
	buffer->off = buffer->off + strlen(val) + 1;
	buffer->len = buffer->off;
}

void appendValueWithLength(Buffer* buffer, char* val) {
	int len = 4 + strlen(val) + 1;
	appendInt(buffer, len);
	memcpy(buffer->data + buffer->off, val, strlen(val));
	buffer->off = buffer->off + strlen(val) + 1;
	buffer->len = buffer->off;
}

void appendNameValueWithLength(Buffer* buffer, char* name, char* val) {
	int len = 4 + strlen(name) + 1 + strlen(val) + 1;
	appendInt(buffer, len);
	memcpy(buffer->data + buffer->off, name, strlen(name));
	buffer->off = buffer->off + strlen(name) + 1;
	memcpy(buffer->data + buffer->off, val, strlen(val));
	buffer->off = buffer->off + strlen(val) + 1;
	buffer->len = buffer->off;
}

void appendIntWithLength(Buffer* buffer, int count,...) {
	int len = (count + 1) * 4;
	appendInt(buffer, len);
	va_list valist;
	va_start(valist, count);
	int i;
	for(i = 0; i < count; i++) {
		int in = va_arg(valist, int);
		appendInt(buffer, in);
	}
	buffer->len = buffer->off;
}

void appendByteWithLength(Buffer* buffer, char ch) {
	appendInt(buffer, 5);
	*(buffer->data + buffer->off) = ch;
	buffer->off++;
	buffer->len = buffer->off;
}
