/*
 * parsenodes.h
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */

#ifndef PARSENODES_H_
#define PARSENODES_H_
#include "../util/list.h"

typedef enum NodeTag{
	T_CreateStmt,
	T_TableNode,
	T_ColumnNode,
	T_InsertStmt,
	T_OptTarget,
	T_SelectStmt,
	T_FromClause,
	T_WhereSingle,
	T_WhereCondition,
} NodeTag;

typedef struct Node{
	NodeTag type;
} Node;

typedef struct TableNode{
	NodeTag type;
	char* schema;
	char* tableName;
} TableNode;

typedef struct ColumnNode{
	NodeTag type;
	char* fieldName;
	unsigned int length;
	unsigned char flag;
} ColumnNode;

typedef struct CreateStmt{
	NodeTag type;
	TableNode* tableNode;
	List* tableElementList;
}CreateStmt;

typedef struct InsertStmt{
	NodeTag type;
	TableNode* tableNode;
	List* columnsList;
	List* valuesList;
}InsertStmt;

typedef struct OptTarget{
	NodeTag type;
	int isAll;
	char* tableAlias;
	char* name;
	char* alias;
} OptTarget;

typedef struct FromClause{
	NodeTag type;
	char* name;
	char* alias;
} FromClause;

typedef struct SelectStmt{
	NodeTag type;
	List* optTargetList;
	List* fromClause;
	List* whereClause;
}SelectStmt;

typedef struct Field{
	int isVal; // 0: field // 1:val
	char* tableAlias;
	char* field;
	char* val;
}Field;

typedef struct WhereSingle{
	NodeTag type;
	char* op;
	Field left;
	Field right;
} WhereSingle;

typedef struct WhereCondition{
	NodeTag type;
	int condition; // 1:AND; 2:OR
	int isList; // 0: whereSingle; 1: list
	WhereSingle* whereSingle;
	List* list;
} WhereCondition;

#define makeNode(NodeTag) newNode(sizeof(NodeTag), T_##NodeTag)


#define newNode(size, nodeTage) ({ \
	Node* node = malloc(size); \
	node->type = nodeTage; \
	node; \
})

#define newList() makeList()

#define lappend(list, val) listAppend(list, val)

#endif /* PARSENODES_H_ */
