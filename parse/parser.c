/*
 * parser.c
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */


#include "../util/list.h"
#include "../node/parseNodes.h"
#include "ptype.h"
#include "bison.h"
#include "parse.h"

List* parseQuery(char* queryString) {
	yy_extra_type yyext;
	yyscan_t scanner = scanner_init(&yyext, queryString);
	yyparse(scanner);
	List* list = (List*)yyext.list;
	return list;
}
