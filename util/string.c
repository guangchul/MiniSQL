/*
 * string.c
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */
#include "string.h"
#include <stdlib.h>

String* makeString() {
	String* string = malloc(sizeof(String));
	string->data = malloc(1024);
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

char* itoa(int number) {
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
