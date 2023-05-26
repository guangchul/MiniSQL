/*
 * portalCreateIndexStmt.c
 *
 *  Created on: May 13, 2023
 *      Author: choi
 */

#include "process.h"
#include "../util/mem.h"
#include "../util/string.h"
#include <string.h>
#include "../file/file.h"
#include <stdlib.h>
#include "../excutor/column.h"
#include "../global/config.h"
#include "../global/page.h"
#include "../index/index.h"
#include "../cache/cache.h"
#include "../global/global.h"

int getColumnsCount(Relation* relation, char* buff) {
	CreateIndexRelationExtend* extend = (CreateIndexRelationExtend*)relation->ext;
	for(int i = 0; i < extend->columnsIdCount; i++) {
		if(i == 0) {
			strcat(buff, itoa_local(extend->columnsIds[i]));
		}else{
			strcat(buff, " ");
			strcat(buff, itoa_local(extend->columnsIds[i]));
		}
	}
	return extend->columnsIdCount;
}

void insertIntoIndeces(CreateIndexStmt* node, Relation* tableRelation, Relation* indicesRelation, Relation* indexRelation) {
	int columnCount = 6;
	int valuesCount = 1;
	DB_Columns* _columns[6] = {&(columns[10]), &(columns[11]), &(columns[12]), &(columns[13]), &(columns[14]), &(columns[15])};
	FieldNodes* fieldNodes = makeFieldNodes(_columns, 6);
	char** intoValues = malloc_local(sizeof(char*) * columnCount);
	int nextId = getTableNextId(indicesRelation);
	intoValues[0] = itoa_local(nextId);
	intoValues[1] = itoa_local(tableRelation->tableInfo->id);
	intoValues[2] = node->indexName;
	intoValues[3] = indexRelation->fileNode->file;
	char* columnsIds = malloc_local(1024);
	int count = getColumnsCount(indexRelation, columnsIds);
	intoValues[4] = itoa_local(count);
	intoValues[5] = columnsIds;
	FieldValuesList* fieldValuesList = makeFieldValuesList(fieldNodes, (char**)indices_into_columns, (char***)intoValues, columnCount, valuesCount);
	free(intoValues);
	free(columnsIds);
	InsertRelationExtend* extend = (InsertRelationExtend*)malloc_local(sizeof(InsertRelationExtend));
	extend->type = T_Insert;
	extend->fieldNodes = fieldNodes;
	extend->fieldValuesList = fieldValuesList;
	indicesRelation->ext = (RelationExtend*)extend;
	insert(indicesRelation);
}

void insertIntoIndex(Relation* tableRelation, Relation* indexRelation) {
	List* list = getPageBlocks(tableRelation->fileNode);
	ListNode* listNode;
	foreach(listNode, list) {
		int blockNo = listNode->value.int_val;
		char* page = BufferBlocks + (blockNo * BUFFERS_SIZE);
		PageHeaderData* pageHeaderData = (PageHeaderData*)page;
		int count = (pageHeaderData->start_of_free_space - 28) / 4;
		for(int i = 0; i < count; i++) {
			ItemIdData itemIdData = pageHeaderData->tuple_desc[i];
			HeapTupleHeaderData* tuple = (HeapTupleHeaderData*)(page + itemIdData.lp_off);
			if((tuple->attrs_count & 0x8000) > 0 || (tuple->attrs_count & 0x2000) > 0) {
				continue;
			}
			if((tuple->attrs_count & 0x4000) > 0){
				tuple = getTupleRecursion(tableRelation, tuple);
				if(tuple == (void*)0) {
					continue;
				}
				int pageNo = tuple->item_desc.page_hi << 16 | tuple->item_desc.page_low;
				int posId = tuple->item_desc.pos_id;
				List* list = getPageBlocks(tableRelation->fileNode);
				int blockNo = listGet_int(list, pageNo);
				char* page = BufferBlocks + (blockNo * BUFFERS_SIZE);
				PageHeaderData* pageHeaderData = (PageHeaderData*)page;
				itemIdData = pageHeaderData->tuple_desc[posId];
			}
			btreeInsert(tuple, itemIdData.lp_len, tableRelation, indexRelation);
		}
	}
}

void runCreateIndexStmt(CreateIndexStmt* node, List* relationList) {
	Relation* tableRelation = (Relation*)listGet(relationList, 0);
	Relation* indicesRelation = (Relation*)listGet(relationList, 1);
	Relation* indexRelation = (Relation*)listGet(relationList, 2);

	createIndex(indexRelation->fileNode);
	insertIntoIndeces(node, tableRelation, indicesRelation, indexRelation);
	insertIntoIndex(tableRelation, indexRelation);
	flushTable(indexRelation);
	writeResultHeader((void*)0, (void*)0);
	resetIndexSet(tableRelation->tableInfo, tableRelation->fileNode->schema);
}
