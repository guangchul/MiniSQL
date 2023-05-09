/*
 * buffer.h
 *
 *  Created on: May 8, 2023
 *      Author: choi
 */

#ifndef BUFFER_H_
#define BUFFER_H_


typedef struct Buffer{
	char* data;
	unsigned int len;
	unsigned int off;
}Buffer;

extern void beginMessage(Buffer* buffer, char ch);
extern void appendInt(Buffer* buffer, int in);
extern void appendShort(Buffer* buffer, short sh);
extern void appendValue(Buffer* buffer, char* val);
extern void appendValueWithLength(Buffer* buffer, char* val);
extern void appendNameValueWithLength(Buffer* buffer, char* name, char* val);
extern void appendIntWithLength(Buffer* buffer, int count,...);
extern void appendByteWithLength(Buffer* buffer, char ch);

#endif /* BUFFER_H_ */
