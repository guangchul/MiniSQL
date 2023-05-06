/*
 * analyzeDeleteStmt.c
 *
 *  Created on: May 5, 2023
 *      Author: choi
 */
#include "process.h"
#include "../file/file.h"

List* analyzeDeleteStmt(DeleteStmt* node, char* schema) {
	List* relationList = makeList();
	Relation* relation = malloc_local(sizeof(Relation));
	DB_Table* tableInfo = getTableInfo(schema, node->fromClause->name, node->fromClause->alias);
	DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
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
