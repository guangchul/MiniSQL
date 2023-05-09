/*
 * string.c
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */
#include "string.h"
#include <stdlib.h>
#include "../util/mem.h"
#include <string.h>

String* makeString() {
	String* string = malloc_local(sizeof(String));
	string->data = malloc_local(1024);
	string->length = 0;
	return string;
}

void resetString(String* string) {
	string->length = 0;
}

void appendStringChar(String* string, char ch) {
	string->data[string->length] = ch;
	string->length++;
	string->data[string->length + 1] = 0;
}

void appendString(String* string, char* str) {
	for(int i = 0; i < strlen(str); i++) {
		char ch = *(str + i);
		appendStringChar(string, ch);
	}
}

void appendStringOffset(String* string, char* ptr, int start, int len) {
	for(int i = start; i < len; i++) {
		char ch = *(ptr + i);
		appendStringChar(string, ch);
	}
}

char* itoa_local(int number) {
	int _number = number;
	int len = 0;
	for(;;) {
		len++;
		if((_number = _number / 10) == 0){
			break;
		}
	}
	_number = number;
	char* buff = malloc(len + 1);
	*(buff + len) = 0;
	for(;len > 0; len--) {
		int i = _number % 10;
		*(buff + (len - 1)) = i + 0x30;
		_number = _number / 10;
	}
	return buff;
}
