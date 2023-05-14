/*
 * analyzeCreateIndexStmt.c
 *
 *  Created on: May 11, 2023
 *      Author: choi
 */

#include "process.h"
#include "../error/error.h"
#include <string.h>
#include "../util/mem.h"
#include "../file/file.h"

List* analyzeCreateIndexStmt(CreateIndexStmt* node, char* schema) {
	DB_Table* tableInfo = getTableInfo(schema, node->tableName, (void*)0);
	if(tableInfo == (void*)0) {
		printError("table not exists!");
		return (void*)0;
	}
	DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
	List* columnList = node->columnList;
	int* columnsIdx = malloc_local(sizeof(int) * columnList->length);
	int* columnsNo = malloc_local(sizeof(int) * columnList->length);
	int idx = 0;
	ListNode* listNode;
	foreach(listNode, columnList) {
		int found = 0;
		char* columnName = (char*)listNode->value.ptr_val;
		for(int i = 0; i < columnsSet->count; i++) {
			if(strcmp(columnName, columnsSet->columns[i]->fieldName) == 0) {
				columnsIdx[idx] = columnsSet->columns[i]->id;
				columnsNo[idx] = i;
				idx++;
				found = 1;
				break;
			}
		}
		if(found == 0) {
			printError("column not exists!");
			return (void*)0;
		}
	}
	CreateIndexRelationExtend* extend = (CreateIndexRelationExtend*)malloc_local(sizeof(CreateIndexRelationExtend));
	extend->type = T_CreateIndex;
	extend->columnsIds = columnsIdx;
	extend->columnsIdCount = idx;
	extend->columnsNo = columnsNo;
	DB_Index_Set* indexSet = getIndexSet(tableInfo, schema);
	for(int i = 0; i < indexSet->count; i++) {
		DB_Index* index = indexSet->index[i];
		if(strcmp(index->indexName, node->indexName) == 0) {
			printf("column name already exists!\n");
			return (void*)0;
		}
		//TODO compare all columns.
	}
	Relation* tableRelation = (Relation*)malloc_local(sizeof(Relation));
	FileNode* tableFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	tableFileNode->schema = schema;
	tableFileNode->file = tableInfo->fileName;
	makeFileNode(tableFileNode);
	tableRelation->fileNode = tableFileNode;
	tableRelation->tableInfo = tableInfo;
	tableRelation->columnsSet = columnsSet;

	Relation* indicesRelation = (Relation*)malloc_local(sizeof(Relation));
	FileNode* indicesFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	DB_Table* indicesTableInfo = getTableInfo(schema, "indices", (void*)0);
	DB_Columns_Set* indicesColumnsSet = getColumnsSet(schema, indicesTableInfo);
	indicesFileNode->schema = schema;
	indicesFileNode->file = indicesTableInfo->fileName;
	makeFileNode(indicesFileNode);
	indicesRelation->fileNode = indicesFileNode;
	indicesRelation->tableInfo = indicesTableInfo;
	indicesRelation->columnsSet = indicesColumnsSet;

	Relation* indexRelation = (Relation*)malloc_local(sizeof(Relation));
	FileNode* indexFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	indexFileNode->schema = schema;
	int len = strlen(node->indexName) + 4 + 1;
	char* fileName = malloc_local(len);
	strcat(fileName, node->indexName);
	strcat(fileName, ".idx");
	indexFileNode->file = fileName;
	indexRelation->fileNode = indexFileNode;
	indexRelation->ext = (RelationExtend*)extend;



	List* list = makeList();
	listAppend(list, tableRelation);
	listAppend(list, indicesRelation);
	listAppend(list, indexRelation);
	return list;
}
