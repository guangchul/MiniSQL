/*
 * ptype.h
 *
 *  Created on: Apr 20, 2023
 *      Author: choi
 */

#ifndef PTYPE_H_
#define PTYPE_H_

#include <stddef.h>

typedef struct yy_extra_type {
	char *scanbuf;
	size_t scanbuflen;
	void* list;
} yy_extra_type;

typedef union core_YYSTYPE
{
	int			ival;			/* for integer literals */
	char	   *str;			/* for identifiers and non-integer literals */
	const char *keyword;		/* canonical spelling of keywords */
} core_YYSTYPE;

typedef void * yyscan_t;

#endif /* PTYPE_H_ */
