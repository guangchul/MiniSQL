/*
 * analyzeSelectStmt.c
 *
 *  Created on: Apr 25, 2023
 *      Author: choi
 */


#include "process.h"
#include "../util/list.h"
#include "../global/rel.h"
#include "../file/file.h"
#include <stdlib.h>
#include <string.h>
#include "../util/mem.h"

DB_Columns* getColumnsFromSet(DB_Columns_Set* columnsSet, char* fieldName) {
	for(int i = 0; i < columnsSet->count; i++) {
		DB_Columns* column = columnsSet->columns[i];
		if(strcmp(column->fieldName, fieldName) == 0) {
			return column;
		}
	}
	return (void*)0;
}

FieldNodes* remakeFieldNodes(List* optTargetList, DB_Columns_Set* columnsSet, char* alias, char* name) {
	List* tempList = makeList();
	if(alias != (void*)0) {
		ListNode* listNode;
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(optTarget->tableAlias == (void*)0) {
				//todo error;
			}
			if(strcmp(optTarget->tableAlias, alias) == 0) {
				if(optTarget->isAll == 1) {
					FieldNodes* fieldNodes = malloc(sizeof(FieldNodes) + (sizeof(FieldNode*) * columnsSet->count));
					fieldNodes->length = columnsSet->count;
					for(int i = 0; i < columnsSet->count; i++) {
						DB_Columns* column = columnsSet->columns[i];
						FieldNode* fieldNode = malloc(sizeof(FieldNode));
						fieldNode->id = column->id;
						fieldNode->fieldName = column->fieldName;
						fieldNode->length = column->length;
						fieldNode->flag = column->flag;
						fieldNodes->fieldNode[i] = fieldNode;
					}
					return fieldNodes;
				}
				DB_Columns* column = getColumnsFromSet(columnsSet, optTarget->name);
				if(column == (void*)0) {
					//todo error;
				}
				listAppend(tempList, column);
			}
		}
	} else {
		ListNode* listNode;
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(optTarget->tableAlias == (void*)0) {
				optTarget->tableAlias = name;
			}
			if(optTarget->isAll == 1) {
				FieldNodes* fieldNodes = malloc(sizeof(FieldNodes) + (sizeof(FieldNode*) * columnsSet->count));
				fieldNodes->length = columnsSet->count;
				for(int i = 0; i < columnsSet->count; i++) {
					DB_Columns* column = columnsSet->columns[i];
					FieldNode* fieldNode = malloc(sizeof(FieldNode));
					fieldNode->id = column->id;
					fieldNode->fieldName = column->fieldName;
					fieldNode->length = column->length;
					fieldNode->flag = column->flag;
					fieldNode->alias = name;
					fieldNodes->fieldNode[i] = fieldNode;
				}
				return fieldNodes;
			}
			DB_Columns* column = getColumnsFromSet(columnsSet, optTarget->name);
			if(column == (void*)0) {
				//todo error;
			}
			listAppend(tempList, column);
		}
	}
	ListNode* listNode;
	FieldNodes* fieldNodes = malloc(sizeof(FieldNodes) + (sizeof(FieldNode*) * tempList->length));
	fieldNodes->length = tempList->length;
	int idx = 0;
	foreach(listNode, tempList) {
		DB_Columns* column = (DB_Columns*)listNode->value.ptr_val;
		FieldNode* fieldNode = malloc(sizeof(FieldNode));
		fieldNode->id = column->id;
		fieldNode->fieldName = column->fieldName;
		fieldNode->length = column->length;
		fieldNode->flag = column->flag;
		fieldNodes->fieldNode[idx] = fieldNode;
		idx++;
	}
	freeList(tempList);
	return fieldNodes;
}

//todo
void checkWhereClause(List* whereClause, char* alias, char* tableName) {
	if(whereClause == (void*)0) {
		return;
	}
	if(alias == (void*)0) {
		ListNode* listNode;
		foreach(listNode, whereClause) {
			WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
			if(whereCondition->isList == 1) {
				checkWhereClause(whereCondition->list, alias, tableName);
			} else {
				if(whereCondition->whereSingle == (void*)0) {
					return;
				}
				whereCondition->whereSingle->left.tableAlias = tableName;
			}
		}
	}
}

List* analyzeSelectStmt(SelectStmt* node, char* schema) {
	List* relationList = makeList();
	List* fromClause = node->fromClause;
	List* optTargetList = node->optTargetList;
	ListNode* listNode;
	foreach(listNode, fromClause) {
		FromClause* fromClause = (FromClause*)listNode->value.ptr_val;
		DB_Table* tableInfo = getTableInfo(schema, fromClause->name, fromClause->alias);
		DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
		FieldNodes* fieldNodes = remakeFieldNodes(optTargetList, columnsSet, fromClause->alias, fromClause->name);
		//todo index stuff

		checkWhereClause(node->whereClause, fromClause->alias, fromClause->name);

		FileNode* fileNode = (FileNode*)malloc_local(sizeof(FileNode));
		fileNode->schema = schema;
		fileNode->file = tableInfo->fileName;
		makeFileNode(fileNode);

		Relation* relation = malloc(sizeof(Relation));
		relation->fileNode = fileNode;
		relation->fieldNodes = fieldNodes;
		relation->tableInfo = tableInfo;
		relation->columnsSet = columnsSet;

		listAppend(relationList, relation);
	}
	return relationList;
}
