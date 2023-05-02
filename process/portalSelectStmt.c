/*
 * portalSelectStmt.c
 *
 *  Created on: Apr 26, 2023
 *      Author: choi
 */
#include <stdlib.h>
#include "process.h"
#include "../global/slot.h"
#include "../global/config.h"
#include "../global/global.h"
#include "../util/list.h"
#include "../cache/cache.h"
#include "../util/string.h"
#include "../util/mem.h"
#include <string.h>

int match(char* left, char* op, char* right) {
	switch(*op) {
		case '=':
			if(left == (void*)0 && right == (void*)0) return 1;
			if((left == (void*)0 && right != (void*)0) || (left != (void*)0 && right == (void*)0)) return 0;
			return strcmp(left, right) == 0 ? 1 : 0;
			break;
		default:
			break;
	}
	return 0;
}

char* getValFromTuple(HeapTupleHeaderData* tuple, char* field, FieldNodes* fieldNodes) {
	int i = 0;
	for( ;i < fieldNodes->length; i++) {
		FieldNode* fieldNode = fieldNodes->fieldNode[i];
		if(strcmp(field, fieldNode->fieldName) == 0) {
			break;
		}
	}
	return getVal(tuple, fieldNodes, i);
}

int compareConditionSingle(HeapTupleHeaderData* tuple, unsigned int len, WhereSingle* whereSingle, char* tableAlias, FieldNodes* fieldNodes) {
	int isVal = whereSingle->left.isVal;
	if(isVal == 1) {
		return match(whereSingle->left.val, whereSingle->op, whereSingle->right.val);
	} else {
		if(strcmp(whereSingle->left.tableAlias, tableAlias) != 0){
			return 1;
		} else {
			if(whereSingle->right.tableAlias != (void*)0){
				return 1;
			}
			char* field = whereSingle->left.field;
			char* val = getValFromTuple(tuple, field, fieldNodes);
			return match(val, whereSingle->op, whereSingle->right.val);
		}
	}
	return 1;
}

int matchCondition(int result, int condition, int _result) {
	if(condition == 1) { // AND
		return result & _result;
	} else if(condition == 2) { // OR
		return result | _result;
	}
	return 1;
}

//return 0 is not match, 1 is match.
int compare(HeapTupleHeaderData* tuple, unsigned int len, List* whereClause, char* tableAlias, FieldNodes* fieldNodes) {
	if(whereClause == (void*)0) {
		return 1;
	}
	if(whereClause->length == 0) {
		return 1;
	}
	ListNode* listNode;
	int result = 1;
	foreach(listNode, whereClause) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			int _result = compare(tuple, len, whereCondition->list, tableAlias, fieldNodes);
			result = matchCondition(result, whereCondition->condition, _result);
		} else {
			if(whereCondition->whereSingle == (void*)0) {
				return result;
			}
			int _result = compareConditionSingle(tuple, len, whereCondition->whereSingle, tableAlias, fieldNodes);
			result = matchCondition(result, whereCondition->condition, _result);
		}
	}
	return result;
}

int next(Relation* relation) {
	SelectRelationExtend* extend = (SelectRelationExtend*)relation->ext;
	if(extend->alreayMadeTempBlock == 0) {
		char* page = BufferBlocks + (extend->nextBlockNo * BUFFERS_SIZE);
		PageHeaderData* pageHeaderData = (PageHeaderData*)page;
		int itemCount = (pageHeaderData->start_of_free_space - 28) / 4;
		if(extend->nextItemPos == itemCount - 1) { //next page
			extend->nextBlockSeq++;
			List* list = getPageBlocks(relation->fileNode);
			int nextBlockNo = listGet_int(list, extend->nextBlockSeq);
			if(nextBlockNo == -1){ // read complete
				extend->nextBlockSeq = 0;
				extend->nextBlockNo = 0;
				extend->nextItemPos = 0;
				extend->alreayMadeTempBlock = 1;
				return -1;
			} else {
				extend->nextBlockNo = nextBlockNo;
				extend->nextItemPos = 0;
				return 1;
			}
		} else {
			extend->nextItemPos++;
			return 1;
		}
	} else {
		char* page = TempBufferBlocks + (extend->nextBlockNo * BUFFERS_SIZE);
		PageHeaderData* pageHeaderData = (PageHeaderData*)page;
		int itemCount = (pageHeaderData->start_of_free_space - 28) / 4;
		if(extend->nextTempItemPos == itemCount - 1) { //next page
			extend->nextTempBlockSeq++;
			int nextTempBlockNo = listGet_int(extend->tempBlockList, extend->nextTempBlockSeq);
			if(nextTempBlockNo == -1) {
				extend->nextTempBlockSeq = 0;
				extend->nextBlockNo = 0;
				extend->alreayMadeTempBlock = 1;
				return -1;
			} else {
				extend->nextTempBlockNo = nextTempBlockNo;
				extend->nextTempItemPos = 0;
				return 1;
			}
		} else {
			extend->nextTempItemPos++;
			return 1;
		}
	}
	return -1;
}

PageHeaderData* initPageHeaderData() {
	PageHeaderData* pageHeaderData = malloc_local(sizeof(PageHeaderData));
	pageHeaderData->un_distributed_1.xlogid = 0;
	pageHeaderData->un_distributed_1.xrecoff = 0;
	pageHeaderData->un_distributed_2 = 0;
	pageHeaderData->un_distributed_4 = 0;
	pageHeaderData->un_distributed_5 = 0;
	pageHeaderData->un_distributed_6 = 0;
	pageHeaderData->page_flags = 0;
	pageHeaderData->start_of_free_space = 28;
	pageHeaderData->end_of_free_space = BUFFERS_SIZE;
	pageHeaderData->page_no = 0;
	return pageHeaderData;
}

void writeToTempBufferBlocks(SelectRelationExtend* extend, HeapTupleHeaderData* tuple, int len) {
	List* list = extend->tempBlockList;
	if(list->length == 0) {
		int blockNo = getFreeTempBufferBlockNo();
		extend->nextTempBlockSeq = 0;
		extend->nextTempBlockNo = blockNo;
		extend->nextTempItemPos = 0;
		extend->lastTempBlockNo = blockNo;
		listAppend_int(extend->tempBlockList, blockNo);
		PageHeaderData* pageHeaderData = initPageHeaderData();
		memcpy(TempBufferBlocks + (blockNo * BUFFERS_SIZE), pageHeaderData, sizeof(PageHeaderData));
		free(pageHeaderData);
	}
	char* page = TempBufferBlocks + (extend->lastTempBlockNo * BUFFERS_SIZE);
	PageHeaderData* pageHeaderData = (PageHeaderData*)page;
	if(((pageHeaderData->end_of_free_space - len) / 8 * 8) - pageHeaderData->start_of_free_space - 4 < len) {
		int blockNo = getFreeTempBufferBlockNo();
		listAppend_int(extend->tempBlockList, blockNo);
		PageHeaderData* pageHeaderData = initPageHeaderData();
		memcpy(TempBufferBlocks + (blockNo * BUFFERS_SIZE), pageHeaderData, sizeof(PageHeaderData));
		free(pageHeaderData);
		extend->lastTempBlockNo = blockNo;
		page = TempBufferBlocks + (extend->lastTempBlockNo * BUFFERS_SIZE);
		pageHeaderData = (PageHeaderData*)page;
	}
	int offset = (pageHeaderData->end_of_free_space - len) / 8 * 8;
	memcpy(TempBufferBlocks + (extend->lastTempBlockNo * BUFFERS_SIZE) + offset, tuple, len);
	ItemIdData* itemIdData = malloc_local(sizeof(ItemIdData));
	itemIdData->lp_off = offset;
	itemIdData->lp_len = len;
	itemIdData->lp_flag = 1;
	memcpy(TempBufferBlocks + (extend->lastTempBlockNo * BUFFERS_SIZE) + pageHeaderData->start_of_free_space, itemIdData, 4);
	pageHeaderData->start_of_free_space = pageHeaderData->start_of_free_space + 4;
	pageHeaderData->end_of_free_space = offset;
}

void appendSlot(Slot* slot, HeapTupleHeaderData* tuple, int len) {
	HeapTupleHeaderData* _tuple = slot->tuple;
	int attrs_count = _tuple->attrs_count + tuple->attrs_count;
	int bits_count = attrs_count / 8 + 1;

	int slot_len = (slot->tuple_len - slot->tuple->offset_of_data) + (len - tuple->offset_of_data);
	slot->tuple = malloc_local(sizeof(HeapTupleHeaderData) + bits_count + slot_len);
	for(int i = 0; i < _tuple->attrs_count / 8 + 1; i++) {
		memset(slot->tuple->bits + i, _tuple->bits[i], 1);
	}
	int j = 0;
	for(int i = _tuple->attrs_count / 8; i < bits_count; i++) {
		memset(slot->tuple->bits + i, (slot->tuple->bits[i]) | (tuple->bits[j] << (_tuple->attrs_count % 8)), 1);
		if(i + 1 < bits_count) {
			memset(slot->tuple->bits + i + 1, tuple->bits[j] << (_tuple->attrs_count % 8), 1);
		}
		j++;
	}
	memcpy(slot->tuple->bits + bits_count, ((char*)_tuple) + _tuple->offset_of_data, slot->tuple_len - _tuple->offset_of_data);
	memcpy(slot->tuple->bits + bits_count + slot->tuple_len - _tuple->offset_of_data, ((char*)tuple) + tuple->offset_of_data, len - tuple->offset_of_data);
	slot->tuple->attrs_count = attrs_count;
	slot->tuple->flag_bits = _tuple->flag_bits | tuple->flag_bits;
	slot->tuple->offset_of_data = 23 + bits_count;
	slot->tuple_len = sizeof(HeapTupleHeaderData) + bits_count + slot_len;
	free(_tuple);
}

void readBlock(Relation* relation, Slot* slot, List* whereClause) {
	SelectRelationExtend* extend = (SelectRelationExtend*)relation->ext;
	if(extend->isLast == 1 && slot->loop == 1) {
		slot->loop = 0;
	}
	if(extend->alreayMadeTempBlock == 0) {
		for(;;) {
			char* page = BufferBlocks + (extend->nextBlockNo * BUFFERS_SIZE);
			PageHeaderData* pageHeaderData = (PageHeaderData*)page;
			if(pageHeaderData->start_of_free_space == 28) {
				return;
			}
			ItemIdData itemIdData = pageHeaderData->tuple_desc[extend->nextItemPos];
			HeapTupleHeaderData* tuple = (HeapTupleHeaderData*)(page + itemIdData.lp_off);
			int result = compare(tuple, itemIdData.lp_len, whereClause, relation->tableInfo->alias, relation->fieldNodes);
			if(result == 1) {
				if(extend->isOuter == 0) {
					writeToTempBufferBlocks(extend, tuple, itemIdData.lp_len);
					appendSlot(slot, tuple, itemIdData.lp_len);
				}else if(extend->isOuter == 1) {
					slot->tuple = malloc_local(itemIdData.lp_len);
					memcpy(slot->tuple, tuple, itemIdData.lp_len);
					slot->tuple_len = itemIdData.lp_len;
				}
				return;
			} else {
				if(next(relation) == -1) {
					extend->jump = 1;
					slot->loop = 1;
					return;
				}
			}
		}

	} else {
		char* page = TempBufferBlocks + (extend->nextTempBlockNo * BUFFERS_SIZE);
		PageHeaderData* pageHeaderData = (PageHeaderData*)page;
		if(pageHeaderData->start_of_free_space == 28) {
			return;
		}
		ItemIdData itemIdData = pageHeaderData->tuple_desc[extend->nextTempItemPos];
		HeapTupleHeaderData* tuple = (HeapTupleHeaderData*)(page + itemIdData.lp_off);
		appendSlot(slot, tuple, itemIdData.lp_len);
	}
}


void makeSlot(ListNode* listNode, Slot* slot, List* whereClause, int* isOut) {
	Relation* relation = (Relation*)listNode->value.ptr_val;
	if(relation->ext == (void*)0) {
		SelectRelationExtend* extend = malloc_local(sizeof(SelectRelationExtend));
		extend->type = T_Select;
		extend->alreayMadeTempBlock = 0;
		extend->tempBlockList = makeList();
		List* list = getPageBlocks(relation->fileNode);
		extend->nextBlockSeq = 0;
		int nextBlockNo = listGet_int(list, extend->nextBlockSeq);
		extend->nextBlockNo = nextBlockNo;
		extend->nextItemPos = 0;
		extend->isOuter = *isOut;
		*isOut = 0;
		extend->isLast = listNode->next->value.ptr_val != (void*)0 ? 0 : 1;
		relation->ext = (RelationExtend*)extend;
	}
	SelectRelationExtend* extend = (SelectRelationExtend*)relation->ext;
	if(extend->isOuter == 1) {
		if(slot->tuple != (void*)0){
			free(slot->tuple);
			slot->tuple = (void*)0;
			slot->tuple_len = 0;
		}
	}
	readBlock(relation, slot, whereClause);

	if(listNode->next != (void*)0 && listNode->next->value.ptr_val != (void*)0) {
		makeSlot(listNode->next, slot, whereClause, isOut);
	}
	if(extend->isLast == 1 || slot->loop == 1) {
		if(extend->jump == 0){
			if(next(relation) == -1){
				slot->loop = 1;
			}
		} else {
			extend->jump = 0;
		}
	}
	if(extend->isOuter == 1 && extend->alreayMadeTempBlock == 1) {
		slot->end = 1;
	}
}

FieldNodes* makeSlotFieldNodes(List* relationList) {
	List* tempList = makeList();
	ListNode* listNode;
	foreach(listNode, relationList) {
		Relation* relation = (Relation*)listNode->value.ptr_val;
		DB_Columns_Set* colSet = relation->columnsSet;
		for(int i = 0; i < colSet->count; i++) {
			FieldNode* fieldNode = malloc_local(sizeof(FieldNode));
			fieldNode->alias = relation->tableInfo->alias;
			fieldNode->id = colSet->columns[i]->id;
			fieldNode->fieldName = colSet->columns[i]->fieldName;
			fieldNode->flag = colSet->columns[i]->flag;
			fieldNode->length = colSet->columns[i]->length;
			listAppend(tempList, fieldNode);
		}
	}
	FieldNodes* fieldNodes = malloc_local(sizeof(FieldNodes) + (sizeof(FieldNode*) * tempList->length));
	fieldNodes->length = tempList->length;

	int idx = 0;
	foreach(listNode, tempList) {
		FieldNode* fieldNode = (FieldNode*)listNode->value.ptr_val;
		fieldNodes->fieldNode[idx] = fieldNode;
		idx++;
	}
	freeList(tempList);
	return fieldNodes;
}

int fileterConditionSingle(Slot* slot, WhereSingle* whereSingle) {
	int isVal = whereSingle->left.isVal;
	if(isVal == 1) {
		return match(whereSingle->left.val, whereSingle->op, whereSingle->right.val);
	} else {
		char* leftVal = getFieldVal(slot, whereSingle->left);

		char* rightVal;
		if(whereSingle->right.isVal == 1) {
			rightVal = whereSingle->right.val;
		} else {
			rightVal = getFieldVal(slot, whereSingle->right);
		}
		return match(leftVal, whereSingle->op, rightVal);
	}
	return 1;
}

int fileter(Slot* slot, List* whereClause) {
	ListNode* listNode;
	int result = 1;
	if(whereClause == (void*)0) {
		return result;
	}
	foreach(listNode, whereClause) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			int _result = fileter(slot, whereCondition->list);
			result = matchCondition(result, whereCondition->condition, _result);
		} else {
			if(whereCondition->whereSingle == (void*)0) {
				return result;
			}
			int _result = fileterConditionSingle(slot, whereCondition->whereSingle);
			result = matchCondition(result, whereCondition->condition, _result);
		}
	}
	return result;
}

void runSelectStmt(SelectStmt* node, List* relationList){
	Slot* slot = malloc_local(sizeof(Slot));
	FieldNodes* fieldNodes = makeSlotFieldNodes(relationList);
	slot->fieldNodes = fieldNodes;
	slot->tuple_len = 0;
	slot->tuple = (void*)0;
	slot->end = 0;
	slot->loop = 0;
	int* isOut = malloc_local(sizeof(int));
	*isOut = 1;
	for(;;) {
		makeSlot(relationList->node, slot, node->whereClause, isOut);
		if(slot->end == 1) {
			break;
		}
		if(fileter(slot, node->whereClause) == 1){
			writeResult(slot, node);
		}
	}
}
