/*
 * portal.c
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */
#include "process.h"
#include "../node/parseNodes.h"
#include "../util/list.h"
#include "../file/file.h"
#include "../global/rel.h"
#include <string.h>
#include <stdlib.h>
#include "../util/mem.h"

void runCreateStmt(CreateStmt* node, List* relationList, char* processSchema){

	FileNode* fileNode = malloc_local(sizeof(FileNode));
	fileNode->schema = processSchema;
	char fileName[67];
	fileName[0] = 0;
	strcat(fileName, node->tableNode->tableName);
	strcat(fileName, ".tb");
	fileName[strlen(node->tableNode->tableName) + 3] = 0;
	fileNode->file = fileName;
	PageHeaderData* pageHeaderData = malloc_local(sizeof(PageHeaderData));
	createTable(fileNode, pageHeaderData);

	ListNode* listNode;
	foreach(listNode, relationList) {
		Relation* relation = (Relation*)listNode->value.ptr_val;
		insert(relation);
	}
}

void runInsertStmt(List* relationList) {
	ListNode* listNode;
	foreach(listNode, relationList) {
		Relation* relation = (Relation*)listNode->value.ptr_val;
		insert(relation);
	}
}

void portalRun(Node* node, List* relationList, char* processSchema){
	NodeTag type = node->type;
	switch(type) {
		case T_CreateStmt:
			runCreateStmt((CreateStmt*)node, relationList, processSchema);
			break;
		case T_InsertStmt:
			runInsertStmt(relationList);
			break;
		case T_SelectStmt:
			runSelectStmt((SelectStmt*)node, relationList);
			break;
		case T_UpdateStmt:
			runUpdateStmt((UpdateStmt*)node, relationList);
			break;
		default:
			break;
	}
}
