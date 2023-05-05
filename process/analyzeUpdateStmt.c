/*
 * analyzeUpdateStmt.c
 *
 *  Created on: May 4, 2023
 *      Author: choi
 */


#include "process.h"
#include "../util/mem.h"
#include "../file/file.h"

int checkColumnsValue() {

	return -1;
}

int checkColumns(UpdateValue* updateValue, DB_Columns_Set* columnsSet) {

	return -1;
}

void checkUpdateWhereClause(List* whereClause, char* alias) {
	if(whereClause == (void*)0) {
		return;
	}
	ListNode* listNode;
	foreach(listNode, whereClause) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			checkUpdateWhereClause(whereCondition->list, alias);
		} else {
			if(whereCondition->whereSingle == (void*)0) {
				return;
			}
			whereCondition->whereSingle->left.tableAlias = alias;
		}
	}
}

List* analyzeUpdateStmt(UpdateStmt* node, char* schema) {
	List* relationList = makeList();
	Relation* relation = malloc_local(sizeof(Relation));
	DB_Table* tableInfo = getTableInfo(schema, node->fromClause->name, node->fromClause->alias);
	DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
	List* updateValueList = node->updateValueList;
	ListNode* listNode;
	foreach(listNode, updateValueList) {
		UpdateValue* updateValue = (UpdateValue*)listNode->value.ptr_val;
		if(checkColumns(updateValue, columnsSet) == -1) {
			//todo error
		}
	}
	checkUpdateWhereClause(node->whereClause, tableInfo->alias);
	FileNode* fileNode = (FileNode*)malloc_local(sizeof(FileNode));
	fileNode->schema = schema;
	fileNode->file = tableInfo->fileName;
	makeFileNode(fileNode);
	relation->fileNode = fileNode;
	relation->tableInfo = tableInfo;
	relation->columnsSet = columnsSet;
	listAppend(relationList, relation);
	return relationList;
}
