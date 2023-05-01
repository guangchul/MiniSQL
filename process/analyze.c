/*
 * analyze.c
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */
#include "../global/rel.h"
#include "../node/parseNodes.h"
#include "../excutor/column.h"
#include "../util/string.h"
#include "../file/file.h"
#include "process.h"
#include <stdlib.h>
#include <string.h>
#include "../util/mem.h"

List* analyzeCreateStmt(CreateStmt* node, char* schema){
	List* list = makeList();

	FileNode* talbeFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	talbeFileNode->schema = schema;
	talbeFileNode->file = "tables.tb";
	Relation* tableRelation = (Relation*) malloc_local(sizeof(Relation));
	tableRelation->fileNode = talbeFileNode;
	DB_Columns* table_columns[5] = {&(columns[0]), &(columns[1]), &(columns[2]), &(columns[3]), &(columns[4])};
	FieldNodes* tableFieldNodes = makeFieldNodes(table_columns, 5);
	int nextId = getTableNextId(tableRelation);
	char* nextIdStr = itoa_local(nextId);
	char* fileName = malloc_local(67);
	fileName[0] = 0;
	strcat(fileName, node->tableNode->tableName);
	strcat(fileName, ".tb");
	char* tabels_into_values[1][5] = {
			{nextIdStr, node->tableNode->tableName, fileName, itoa_local(node->tableElementList->length), "0"}
	};
	FieldValuesList* tableFieldValuesList = makeFieldValuesList(tableFieldNodes, (char**)tables_into_columns, (char***)tabels_into_values, 5, 1);
	free(fileName);
	tableRelation->fieldNodes = tableFieldNodes;
	tableRelation->fieldValuesList = tableFieldValuesList;
	listAppend(list, tableRelation);

	FileNode* columnsFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	columnsFileNode->schema = schema;
	columnsFileNode->file = "columns.tb";
	DB_Columns* columns_columns[5] = {&(columns[5]), &(columns[6]), &(columns[7]), &(columns[8]), &(columns[9])};
	FieldNodes* columnsFieldNodes = makeFieldNodes(columns_columns, 5);
	Relation* columnsRelation = (Relation*) malloc_local(sizeof(Relation));
	columnsRelation->fileNode = columnsFileNode;
	int columnsNextId = getTableNextId(columnsRelation);
	char* columns_into_values[node->tableElementList->length][5];
	ListNode* listNode;
	int idx = 0;
	foreach(listNode, node->tableElementList){
		ColumnNode* columnNode = (ColumnNode*)listNode->value.ptr_val;
		char* columnsNextIdStr = itoa_local(columnsNextId + idx);
		char* temp[5] = {columnsNextIdStr, nextIdStr, columnNode->fieldName, itoa_local(columnNode->length), itoa_local(columnNode->flag)};
		for(int j = 0; j < 5; j++) {
			columns_into_values[idx][j] = temp[j];
		}
		idx++;
	}
	FieldValuesList* columnsFieldValuesList = makeFieldValuesList(columnsFieldNodes, (char**)columns_into_columns, (char***)columns_into_values, 5, node->tableElementList->length);

	columnsRelation->fieldNodes = columnsFieldNodes;
	columnsRelation->fieldValuesList = columnsFieldValuesList;
	listAppend(list, columnsRelation);

	return list;
}

char** parseListToIntoColumns(List* list) {
	char** intoColumns = malloc_local(sizeof(char*) * list->length);
	ListNode* listNode;
	int idx = 0;
	foreach(listNode, list) {
		intoColumns[idx] = (char*)listNode->value.ptr_val;
		idx++;
	}
	return intoColumns;
}

char*** parseListToIntoValues(List* list, int columnCount) {
	char** intoValues = malloc_local(sizeof(char*) * list->length * columnCount);
	ListNode* listNode;
	int i = 0;
	foreach(listNode, list) {
		List* subList = (List*)listNode->value.ptr_val;
		ListNode* subListNode;
		int j = 0;
		foreach(subListNode, subList) {
			intoValues[i * columnCount + j] = (char*)subListNode->value.ptr_val;
			j++;
		}
		i++;
	}
	return (char***)intoValues;
}

List* analyzeInsertStmt(InsertStmt* node, char* schema) {
	//todo when node->columnsList->length != 0 and node->columnsList->length != node->valuesList[i]->length then throw exception.
	FileNode* fileNode = (FileNode*)malloc_local(sizeof(FileNode));
	fileNode->schema = schema;
	DB_Table* tableInfo = getTableInfo(schema, node->tableNode->tableName, (void*)0);
	fileNode->file = tableInfo->fileName;
	makeFileNode(fileNode);
	DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
	FieldNodes* fieldNodes = makeFieldNodes(columnsSet->columns, columnsSet->count);
	if(node->columnsList->length == 0) {
		for(int i = 0; i < columnsSet->count; i++) {
			listAppend(node->columnsList, columnsSet->columns[i]->fieldName);
		}
	}
	char** intoColumns = parseListToIntoColumns(node->columnsList);
	char*** intoValues = parseListToIntoValues(node->valuesList, node->columnsList->length);
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, intoColumns, intoValues, node->columnsList->length, node->valuesList->length);
	Relation* relation = malloc_local(sizeof(Relation));
	relation->fileNode = fileNode;
	relation->fieldNodes = fieldNodes;
	relation->fieldValuesList = fieldValuesList;
	List* list = makeList();
	listAppend(list, relation);
	return list;
}

List* analyze(Node* node, char* schema) {
	NodeTag type = node->type;
	List* list;
	switch(type) {
		case T_CreateStmt:
			list = analyzeCreateStmt((CreateStmt*)node, schema);
			break;
		case T_InsertStmt:
			list = analyzeInsertStmt((InsertStmt*)node, schema);
			break;
		case T_SelectStmt:
			list = analyzeSelectStmt((SelectStmt*)node, schema);
			break;
		default:
			break;
	}
	return list;
}
