/*
 * writeSelectStmt.c
 *
 *  Created on: May 8, 2023
 *      Author: choi
 */

#include "process.h"
#include "../buffer/buffer.h"
#include <string.h>

DB_Columns* getColumns(DB_Columns_Set* columnsSet, OptTarget* optTarget) {
	for(int i = 0; i < columnsSet->count; i++) {
		DB_Columns* columns = columnsSet->columns[i];
		if(optTarget->tableAlias == (void*)0 && strcmp(columns->fieldName, optTarget->name) == 0) {
			return columns;
		}
		if(optTarget->tableAlias != (void*)0 && strcmp(columns->tableInfo->alias, optTarget->tableAlias) == 0 && strcmp(columns->fieldName, optTarget->name) == 0) {
			return columns;
		}
	}
	return (void*)0;
}

int writeSelectStmtHeaderAll(DB_Columns_Set* columnsSet, OptTarget* optTarget, Buffer* buffer, int idx) {
	if(optTarget->tableAlias == (void*)0){
		for(int i = 0; i < columnsSet->count; i++) {
			DB_Columns* columns = columnsSet->columns[i];
			appendValue(buffer, columns->fieldName);
			appendInt(buffer, 0x8000);
			appendShort(buffer, idx);
			idx++;
			appendInt(buffer, columns->id);
			appendShort(buffer, (columns->flag & 0x1) == 0x1 ? 0xFFFF : columns->length);
			appendInt(buffer, 0xFFFFFFFF);
			appendShort(buffer, 0);
		}
	} else {
		for(int i = 0; i < columnsSet->count; i++) {
			DB_Columns* columns = columnsSet->columns[i];
			if(strcmp(columns->tableInfo->alias, optTarget->tableAlias) == 0){
				appendValue(buffer, columns->fieldName);
				appendInt(buffer, 0x8000);
				appendShort(buffer, idx);
				idx++;
				appendInt(buffer, columns->id);
				appendShort(buffer, (columns->flag & 0x1) == 0x1 ? 0xFFFF : columns->length);
				appendInt(buffer, 0xFFFFFFFF);
				appendShort(buffer, 0);
			}
		}
	}
	return idx;
}

void writeSelectStmtHeader(Slot* slot, SelectStmt* selectStmt, Buffer* buffer) {
	beginMessage(buffer, 'T');
	appendInt(buffer, 0);
	List* list = selectStmt->optTargetList;
	appendShort(buffer, 0);
	ListNode* listNode;
	short idx = 1;
	foreach(listNode, list) {
		OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
		if(optTarget->isAll == 1) {
			idx = writeSelectStmtHeaderAll(slot->columnsSet, optTarget, buffer, idx);
			continue;
		}
		DB_Columns* columns = getColumns(slot->columnsSet, optTarget);
		appendValue(buffer, optTarget->alias == (void*)0 ? optTarget->name : optTarget->alias);
		appendInt(buffer, optTarget->alias == (void*)0 ? 0x8000 : 0);
		appendShort(buffer, idx);
		idx++;
		appendInt(buffer, columns->id);
		appendShort(buffer, (columns->flag & 0x1) == 0x1 ? 0xFFFF : columns->length);
		appendInt(buffer, 0xFFFFFFFF);
		appendShort(buffer, 0);
	}
	int tempOff = buffer->off;
	buffer->off = 1;
	appendInt(buffer, buffer->len - 1);
	appendShort(buffer, idx - 1);
	buffer->off = tempOff;
}

void writeSelectResult(Slot* slot, SelectStmt* selectStmt, Buffer* buffer) {
	List* optTargetList = selectStmt->optTargetList;
	ListNode* listNode;
	int len = 0;
	int startOff = buffer->off;
	beginMessage(buffer, 'D');
	appendInt(buffer, 0);
	appendShort(buffer, 0);
	foreach(listNode, optTargetList) {
		OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
		if(optTarget->isAll == 1) {
			for(int i = 0; i < slot->columnsSet->count; i++) {
				if(optTarget->tableAlias != (void*)0) {
					if(slot->columnsSet->columns[i]->tableInfo->alias != optTarget->tableAlias){
						continue;
					}
				}
				char* val = getVal(slot->tuple, slot->columnsSet, i);
				len++;
				if(val == (void*)0) {
					appendInt(buffer, -1);
					continue;
				}
				appendInt(buffer, strlen(val));
				appendValue(buffer, val);
				buffer->off--;
			}
			continue;
		}
		Field field;
		field.tableAlias = optTarget->tableAlias;
		field.field = optTarget->name;
		char* val = getFieldVal(slot, field);
		len++;
		if(val == (void*)0) {
			appendInt(buffer, -1);
			continue;
		}
		appendInt(buffer, strlen(val));
		appendValue(buffer, val);
		buffer->off--;
	}
	int tempOff = buffer->off;
	buffer->off = startOff + 1;
	appendInt(buffer, buffer->len - startOff - 1 - 1);
	appendShort(buffer, len);
	buffer->off = tempOff;
}
