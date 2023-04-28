/*
 * parse.h
 *
 *  Created on: Apr 20, 2023
 *      Author: choi
 */

#ifndef PARSE_H_
#define PARSE_H_
#include "../util/list.h"
#include "ptype.h"

extern List* parseQuery(char* queryString);
extern yyscan_t scanner_init(yy_extra_type *yyext, char *cmd);

#endif /* PARSE_H_ */
