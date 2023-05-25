/*
 * string.h
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */

#ifndef STRING_H_
#define STRING_H_

typedef struct String{
	char* data;
	unsigned int length;
}String;

extern String* makeString();
extern void resetString(String* string);
extern void appendStringChar(String* string, char ch);
extern char* itoa_local(int number);
extern void appendString(String* string, char* str);
extern void appendStringOffset(String* string, char* ptr, int start, int len);
extern int isdigit_local(char* val);

#endif /* STRING_H_ */
