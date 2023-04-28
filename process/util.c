/*
 * util.c
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */

#include "process.h"
#include "../global/rel.h"
#include <stdlib.h>
#include <string.h>
#include "../file/file.h"
#include "../cache/cache.h"
#include "../global/page.h"
#include "../global/config.h"
#include "../global/global.h"
#include "../util/string.h"


int getTableNextId(Relation* relation) {
	makeFileNode(relation->fileNode);
	int block = getFreePageBlock(relation);
	PageHeaderData* pageHeaderData = (PageHeaderData*) (BufferBlocks + (block * BUFFERS_SIZE));
	ItemIdData* itemIdData = (ItemIdData*)(((void*)pageHeaderData) + pageHeaderData->start_of_free_space - 4);
	HeapTupleHeaderData* heapTupleHeaderData = (HeapTupleHeaderData*)((void*)pageHeaderData + itemIdData->lp_off);
	int* id = (int*)(((void*)heapTupleHeaderData) + heapTupleHeaderData->offset_of_data);
	return *id + 1;
}

DB_Table* getTableInfo(char* schema, char* tableName, char* alias) {//todo refresh when table has changed.
	char key[1024];
	key[0] = 0;
	strcat(key, schema);
	strcat(key, "/");
	strcat(key, tableName);
	key[strlen(schema) + 1 + strlen(tableName) + 1] = 0;
	void* val = getFromHashMap(TABLE_INFO, key);
	if(val != (void*)0){
		return (DB_Table*)val;
	}
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = schema;
	fileNode->file = "tables.tb";
	makeFileNode(fileNode);
	Relation* relation = malloc(sizeof(Relation));
	relation->fileNode = fileNode;
	int block = getFreePageBlock(relation);
	void* page = (void*)(BufferBlocks + (block * BUFFERS_SIZE));
	PageHeaderData* pageHeaderData = (PageHeaderData*) page;
	int descCount = (pageHeaderData->start_of_free_space - 28) / 4;
	for(int i = 0; i < descCount; i++) {
		HeapTupleHeaderData* heapTupleHeaderData = (HeapTupleHeaderData*)(page + pageHeaderData->tuple_desc[i].lp_off);
		uint8 off = heapTupleHeaderData->offset_of_data;
		char* bits = ((char*)heapTupleHeaderData) + off;
		int id = *((int*)bits);
		bits = bits + 4;
		int len = *bits >> 1;
		char str[len];
		memcpy(str, bits + 1, len - 1);
		str[len - 1] = 0;
		if(strcmp(str, tableName) == 0) {
			DB_Table* table = malloc(sizeof(DB_Table));
			table->id = id;
			char* tableName = malloc(sizeof(len - 1));
			memcpy(tableName, str, len - 1);
			table->name = tableName;
			bits = bits + len;
			len = *bits >> 1;
			char* fileName = malloc(sizeof(len - 1));
			memcpy(fileName, bits + 1, len - 1);
			table->fileName = fileName;
			bits = bits + len;
			table->columnCount = *((int*)bits);
			bits = bits + 4;
			table->indexCount = *((int*)bits);
			table->alias = alias == (void*)0 ? tableName : alias;
			free(fileNode);
			free(relation);
			putToHashMap(TABLE_INFO, key, table);
			return table;
		}
	}
	free(fileNode);
	free(relation);
	return (void*)0;
}

DB_Columns_Set* getColumnsSet(char* schema, DB_Table* tableInfo) {//todo refresh when column has changed.
	char* tableName = tableInfo->name;
	char key[1024];
	key[0] = 0;
	strcat(key, schema);
	strcat(key, "/");
	strcat(key, tableName);
	key[strlen(schema) + 1 + strlen(tableName) + 1] = 0;
	void* val = getFromHashMap(COLUMN_INFO, key);
	if(val != (void*)0){
		return (DB_Columns_Set*)val;
	}

	int columnCount = tableInfo->columnCount;
	int tableId = tableInfo->id;
	DB_Columns_Set* columnsSet = malloc(sizeof(DB_Columns_Set) + (sizeof(DB_Columns*) * columnCount));
	columnsSet->count = columnCount;
	FileNode* fileNode = malloc(sizeof(FileNode));
	fileNode->schema = schema;
	fileNode->file = "columns.tb";
	fileNode->fd = -1;
	makeFileNode(fileNode);
	List* blockList = getPageBlocks(fileNode);
	ListNode* listNode;
	int idx = 0;
	foreach(listNode, blockList) {
		int block = listNode->value.int_val;
		void* page = (void*)(BufferBlocks + (block * BUFFERS_SIZE));
		PageHeaderData* pageHeaderData = (PageHeaderData*) page;
		int descCount = (pageHeaderData->start_of_free_space - 28) / 4;
		for(int i = 0; i < descCount; i++) {
			HeapTupleHeaderData* heapTupleHeaderData = (HeapTupleHeaderData*)(page + pageHeaderData->tuple_desc[i].lp_off);
			uint8 off = heapTupleHeaderData->offset_of_data;
			char* bits = ((char*)heapTupleHeaderData) + off;
			int _id = *((int*)bits);
			bits = bits + 4;
			int _tableId = *((int*)bits);
			if(_tableId == tableId){
				DB_Columns* columns = malloc(sizeof(DB_Columns));
				columns->id = _id;
				columns->tableId = _tableId;
				bits = bits + 4;
				int _len = *bits >> 1;
				char* _fieldName = malloc(_len - 1);
				memcpy(_fieldName, bits + 1, _len - 1);
				columns->fieldName = _fieldName;
				bits = bits + _len;
				columns->length = *((int*)bits);
				bits = bits + 4;
				columns->flag = *bits;
				columnsSet->columns[idx] = columns;
				idx++;
			}
		}
	}
	free(fileNode);
	putToHashMap(COLUMN_INFO, key, columnsSet);
	return columnsSet;
}

char* getVal(HeapTupleHeaderData* tuple, FieldNodes* fieldNodes, int i) {
	char* addr = (char*)(tuple->bits) + (fieldNodes->length / 8) + 1;
	for(int j = 0; j <= i; j++) {
		int bitNo = j / 8;
		int bitIndex = j % 8;
		int isNull = tuple->bits[bitNo] & (1 << bitIndex);
		if(isNull) {
			continue;
		}
		FieldNode* fieldNode = fieldNodes->fieldNode[j];
		int flexible = fieldNode->flag & 0x1;
		if(flexible == 1) { //flexible
			int len = addr[0] >> 1;
			if(j == i) {
				char* val = malloc(len - 1);
				memcpy(val, addr + 1, len - 1);
				return val;
			}
			addr = addr + len;
		} else {
			int len = fieldNode->length;
			if(j == i) {
				int type = fieldNode->flag >> 2;
				switch(type) {
					case CHAR:
					case SHORT:
					case INT:
						int val = *((int*)addr);
						return itoa(val);
					case LONG:

						break;
					default:
						break;

				}
			}
			addr = addr + len;
		}
	}
	return (void*)0;
}

char* getFieldVal(Slot* slot, Field field) {
	int i = 0;
	for(; i < slot->fieldNodes->length; i++) {
		FieldNode* fieldNode = slot->fieldNodes->fieldNode[i];
		if(strcmp(fieldNode->alias, field.tableAlias) == 0 && strcmp(fieldNode->fieldName, field.field) == 0) {
			break;
		}
	}
	return getVal(slot->tuple, slot->fieldNodes, i);
}
