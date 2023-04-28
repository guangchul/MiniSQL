/*
 * initDB.c
 *
 *  Created on: Apr 15, 2023
 *      Author: choi
 */
#include "../global/global.h"
#include "../global/rel.h"
#include "../util/list.h"
#include "../file/file.h"
#include "../excutor/column.h"
#include <stdlib.h>
#include <string.h>

#define SCHEMA "base"


char* schema_into_values[1][3] = {
		{"1", "48", SCHEMA}
};



char* tables_into_values[3][5] = {
		{"1", "tables", "tables.tb", "5", "2"},
		{"2", "columns", "columns.tb", "5", "0"},
		{"3", "indices", "indices.tb", "6", "0"}
};


char* columns_into_values[16][5] = {
		{"1", "1", "id", "4", "12"},
		{"2", "1", "name", "64", "17"},
		{"3", "1", "fileName", "64", "17"},
		{"4", "1", "columnCount", "4", "12"},
		{"5", "1", "indexCount", "4", "12"},
		{"6", "2", "id", "4", "12"},
		{"7", "2", "tableId", "4", "12"},
		{"8", "2", "fieldName", "64", "17"},
		{"9", "2", "length", "4", "12"},
		{"10", "2", "flag", "4", "12"},
		{"11", "3", "id", "4", "12"},
		{"12", "3", "tableId", "4", "12"},
		{"13", "3", "indexName", "64", "17"},
		{"14", "3", "indexFileName", "64", "17"},
		{"15", "3", "columnsCount", "4", "12"},
		{"16", "3", "columnIds", "256", "17"},
};


char* indices_into_values[2][6] = {
		{"1", "1", "tables_idx_id", "tables_idx_id.idx", "1", "1"},
		{"2", "1", "tables_idx_name", "tables_idx_name.idx", "1", "2"}
};

void initSchema() {
	char* fileName = "schema";
	int columnCount = sizeof(schema_into_columns) / sizeof(char*);
	int valuesCount = sizeof(schema_into_values) / sizeof(char*) / columnCount;
	DB_Columns* _columns[3] = {&(columns[16]), &(columns[17]), &(columns[18])};
	FieldNodes* fieldNodes = makeFieldNodes(_columns, 3);
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, (char**)schema_into_columns, (char***)schema_into_values, columnCount, valuesCount);
	Relation* relation = malloc(sizeof(Relation));
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = ".";
	fileNode->file = fileName;
	PageHeaderData* pageHeaderData = malloc(sizeof(PageHeaderData));
	createTable(fileNode, pageHeaderData);
	relation->fileNode = fileNode;
	relation->fieldNodes = fieldNodes;
	relation->fieldValuesList = fieldValuesList;
	insert(relation);
	makeDir(SCHEMA, 0755);
	freeFieldNodes(fieldNodes);
	freeFieldValuesList(fieldValuesList);
}

void initTables() {
	char* fileName = "tables.tb";
	int columnCount = sizeof(tables_into_columns) / sizeof(char*);
	int valuesCount = sizeof(tables_into_values) / sizeof(char*) / columnCount;
	DB_Columns* _columns[5] = {&(columns[0]), &(columns[1]), &(columns[2]), &(columns[3]), &(columns[4])};
	FieldNodes* fieldNodes = makeFieldNodes(_columns, 5);
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, (char**)tables_into_columns, (char***)tables_into_values, columnCount, valuesCount);
	Relation* relation = malloc(sizeof(Relation));
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = SCHEMA;
	fileNode->file = fileName;
	PageHeaderData* pageHeaderData = malloc(sizeof(PageHeaderData));
	createTable(fileNode, pageHeaderData);
	relation->fileNode = fileNode;
	relation->fieldNodes = fieldNodes;
	relation->fieldValuesList = fieldValuesList;
	insert(relation);
	freeFieldNodes(fieldNodes);
	freeFieldValuesList(fieldValuesList);
}

void initColumns() {
	char* fileName = "columns.tb";
	int columnCount = sizeof(columns_into_columns) / sizeof(char*);
	int valuesCount = sizeof(columns_into_values) / sizeof(char*) / columnCount;
	DB_Columns* _columns[5] = {&(columns[5]), &(columns[6]), &(columns[7]), &(columns[8]), &(columns[9])};
	FieldNodes* fieldNodes = makeFieldNodes(_columns, 5);
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, (char**)columns_into_columns, (char***)columns_into_values, columnCount, valuesCount);
	Relation* relation = malloc(sizeof(Relation));
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = SCHEMA;
	fileNode->file = fileName;
	PageHeaderData* pageHeaderData = malloc(sizeof(PageHeaderData));
	createTable(fileNode, pageHeaderData);
	relation->fileNode = fileNode;
	relation->fieldNodes = fieldNodes;
	relation->fieldValuesList = fieldValuesList;
	insert(relation);
	freeFieldNodes(fieldNodes);
	freeFieldValuesList(fieldValuesList);
}

void initIndices() {
	char* fileName = "indices.tb";
	int columnCount = sizeof(indices_into_columns) / sizeof(char*);
	int valuesCount = sizeof(indices_into_values) / sizeof(char*) / columnCount;
	DB_Columns* _columns[6] = {&(columns[10]), &(columns[11]), &(columns[12]), &(columns[13]), &(columns[14]), &(columns[15])};
	FieldNodes* fieldNodes = makeFieldNodes(_columns, 6);
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, (char**)indices_into_columns, (char***)indices_into_values, columnCount, valuesCount);
	Relation* relation = malloc(sizeof(Relation));
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = SCHEMA;
	fileNode->file = fileName;
	PageHeaderData* pageHeaderData = malloc(sizeof(PageHeaderData));
	createTable(fileNode, pageHeaderData);
	relation->fileNode = fileNode;
	relation->fieldNodes = fieldNodes;
	relation->fieldValuesList = fieldValuesList;
	insert(relation);
	freeFieldNodes(fieldNodes);
	freeFieldValuesList(fieldValuesList);
}


void initDB() {
	initSchema();
	initTables();
	initColumns();
	initIndices();
}
