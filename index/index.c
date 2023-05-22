/*
 * index.c
 *
 *  Created on: May 22, 2023
 *      Author: choi
 */
#include <stdlib.h>
#include <string.h>
#include "../global/rel.h"
#include "../util/mem.h"
#include "index.h"
#include "../cache/cache.h"
#include "../file/file.h"

Relation* getIndexRelation(DB_Index* dbIndex, Relation* tableRelation) {
	int len = strlen(tableRelation->fileNode->schema) + 1 + strlen(dbIndex->indexName) + 1;
	char key[len];
	key[0] = 0;
	strcat(key, tableRelation->fileNode->schema);
	strcat(key, "/");
	strcat(key, dbIndex->indexName);
	key[len - 1] = 0;
	Relation* indexRelation = (Relation*)getFromHashMap(INDEX_RELATION_CACHE, key);
	if(indexRelation != (void*)0) {
		return indexRelation;
	}
	indexRelation = (Relation*)malloc_local(sizeof(Relation));
	FileNode* indexFileNode = (FileNode*)malloc_local(sizeof(FileNode));
	indexFileNode->schema = tableRelation->fileNode->schema;
	indexFileNode->file = dbIndex->indexFileName;
	makeFileNode(indexFileNode);
	indexRelation->fileNode = indexFileNode;
	int* columnsIdx = malloc_local(sizeof(int) * dbIndex->columnsCount);
	int* columnsNo = malloc_local(sizeof(int) * dbIndex->columnsCount);
	int offset = 0;
	char* buff;
	for(int i = 0; i < dbIndex->columnsCount; i++) {
		buff = malloc_local(8192);
		int j = 0;
		for(;;) {
			char c = *(dbIndex->columnIds + offset);
			offset++;
			if(c == ' ') {
				free(buff);
				break;
			}
			*(buff + j) = c;
			j++;
			if(offset >= strlen(dbIndex->columnIds)){
				break;
			}
		}
		columnsIdx[i] = atoi(buff);
		for(int x = 0; x < tableRelation->columnsSet->count; x++){
			DB_Columns* dbColumn = tableRelation->columnsSet->columns[x];
			if(dbColumn->id == columnsIdx[i]) {
				columnsNo[i] = x;
				break;
			}
		}
	}
	free(buff);
	CreateIndexRelationExtend* extend = (CreateIndexRelationExtend*)malloc_local(sizeof(CreateIndexRelationExtend));
	extend->type = T_CreateIndex;
	extend->columnsIds = columnsIdx;
	extend->columnsIdCount = dbIndex->columnsCount;
	extend->columnsNo = columnsNo;
	indexRelation->ext = (RelationExtend*)extend;
	putToHashMap(INDEX_RELATION_CACHE, key, indexRelation);
	return indexRelation;
}
