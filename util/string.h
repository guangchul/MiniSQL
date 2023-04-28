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
extern char* itoa(int number);

#endif /* STRING_H_ */
