/*
 * portalUpdateStmt.c
 *
 *  Created on: May 4, 2023
 *      Author: choi
 */

#include "process.h"
#include "../util/mem.h"
#include "../global/config.h"
#include "../file/file.h"
#include "../cache/cache.h"
#include <string.h>
#include <stdlib.h>

char* getUpdateValue(List* updateValueList, char* fieldName, int* flag) {
	ListNode* listNode;
	foreach(listNode, updateValueList) {
		UpdateValue* updateValue = (UpdateValue*)listNode->value.ptr_val;
		if(strcmp(updateValue->filed, fieldName) == 0) {
			*flag = 1;
			if(updateValue->val == (void*)0) {
				return (void*)0;
			}
			int len = strlen(updateValue->val) + 1;
			char* val = malloc_local(len);
			memcpy(val, updateValue->val, len - 1);
			return val;
		}
	}
	return (void*)0;
}

void update(Relation* relation, List* updateValueList, Slot* slot) {
	char* buffer = malloc_local(BUFFERS_SIZE);
	DB_Columns_Set* columnsSet = slot->columnsSet;
	int bitCount = (columnsSet->count - 1) / 8 + 1;
	int offset = bitCount;
	uint16 flag_bits = 0;
	for(int i = 0; i < columnsSet->count; i++){
		DB_Columns* columns = columnsSet->columns[i];
		int flag = 0;
		char* updateValue = getUpdateValue(updateValueList, columns->fieldName, &flag);
		if(flag == 0) {
			updateValue = getVal(slot->tuple, slot->columnsSet, i);
		}
		if(((columns->flag & 0x02) == 0x02) && (updateValue == (void*)0)){
			flag_bits |= 0x01;
			int bitSeq = columnsSet->count / 8;
			int bitOff = columnsSet->count % 8;
			int flag = 1 << bitOff;
			buffer[bitSeq] |= flag;
		}else {
			if((columns->flag & 0x01) == 1) {
				short len = strlen(updateValue);
				short _len = ((len + 1) << 1) + 1;
				memcpy(buffer + offset, &_len, 1);
				offset += 1;
				memcpy(buffer + offset, updateValue, len);
				offset += len;
			} else {
				for(int seq = 0; seq < columns->length; seq++){
					*(buffer + offset + seq) = 0;
				}
				int l = 0;
				for(;;) {
					if((atoi(updateValue) >> (sizeof(long) * l)) > 0) {
						*(buffer + offset + l) = atoi(updateValue) >> (l * 8);
					} else {
						break;
					}
					l++;
				}
				offset += columns->length;
			}
		}
	}
	if(offset > (slot->tuple_len / 8 + 1) * 8 - 23){
		updateNewTuple(relation, slot->tuple, slot->tuple_len, slot->columnsSet->count, buffer, offset, flag_bits);
	} else {
		updateOriginTuple(relation, slot->tuple, slot->tuple_len, buffer, offset);
	}
}

void runUpdateStmt(UpdateStmt* node, List* relationList){
	Slot* slot = malloc_local(sizeof(Slot));
	DB_Columns_Set* columnsSet = makeSlotColumnsSet(relationList);
	slot->columnsSet = columnsSet;
	slot->tuple_len = 0;
	slot->tuple = (void*)0;
	slot->end = 0;
	slot->loop = 0;
	int* isOut = malloc_local(sizeof(int));
	*isOut = 1;
	for(;;) {
		makeSlot(relationList->node, slot, node->whereClause, isOut);

		if(slot->tuple != (void*)0 && fileter(slot, node->whereClause) == 1){
			update((Relation*)relationList->node->value.ptr_val, node->updateValueList, slot);
		}
		if(slot->end == 1) {
			break;
		}
	}
	flushTable((Relation*)relationList->node->value.ptr_val);
}
