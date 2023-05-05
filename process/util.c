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
#include "../util/mem.h"


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
	FileNode* fileNode = malloc_local(sizeof(FileNode));
	fileNode->schema = schema;
	fileNode->file = "tables.tb";
	makeFileNode(fileNode);
	Relation* relation = malloc_local(sizeof(Relation));
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
			DB_Table* table = malloc_local(sizeof(DB_Table));
			table->id = id;
			char* tableName = malloc_local(len);
			memcpy(tableName, str, len - 1);
			table->name = tableName;
			bits = bits + len;
			len = *bits >> 1;
			char* fileName = malloc_local(len);
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
	DB_Columns_Set* columnsSet = malloc_local(sizeof(DB_Columns_Set) + (sizeof(DB_Columns*) * columnCount));
	columnsSet->count = columnCount;
	FileNode* fileNode = malloc_local(sizeof(FileNode));
	fileNode->schema = schema;
	fileNode->file = "columns.tb";
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
				DB_Columns* columns = malloc_local(sizeof(DB_Columns));
				columns->id = _id;
				columns->tableInfo = tableInfo;
				bits = bits + 4;
				int _len = *bits >> 1;
				char* _fieldName = malloc_local(_len);
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

char* getVal(HeapTupleHeaderData* tuple, DB_Columns_Set* columnsSet, int i) {
	char* addr = (char*)(tuple->bits) + (columnsSet->count / 8) + 1;
	for(int j = 0; j <= i; j++) {
		int bitNo = j / 8;
		int bitIndex = j % 8;
		int isNull = tuple->bits[bitNo] & (1 << bitIndex);
		if(isNull) {
			continue;
		}
		DB_Columns* columns = columnsSet->columns[j];
		int flexible = columns->flag & 0x1;
		if(flexible == 1) { //flexible
			int len = addr[0] >> 1;
			if(j == i) {
				char* val = malloc_local(len);
				memcpy(val, addr + 1, len - 1);
				return val;
			}
			addr = addr + len;
		} else {
			int len = columns->length;
			if(j == i) {
				int type = columns->flag >> 2;
				switch(type) {
					case CHAR:
					case SHORT:
					case INT:
					{
						int val = *((int*)addr);
						return itoa_local(val);
					}
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
	for(; i < slot->columnsSet->count; i++) {
		DB_Columns* columns = slot->columnsSet->columns[i];
		if(field.tableAlias == (void*)0 && strcmp(columns->fieldName, field.field) == 0) {
			break;
		}
		if(field.tableAlias != (void*)0 && strcmp(columns->tableInfo->alias, field.tableAlias) == 0 && strcmp(columns->fieldName, field.field) == 0) {
			break;
		}
	}
	return getVal(slot->tuple, slot->columnsSet, i);
}
