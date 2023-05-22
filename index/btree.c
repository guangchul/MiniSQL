/*
 * btree.c
 *
 *  Created on: May 14, 2023
 *      Author: choi
 */

#include "index.h"
#include "../global/page.h"
#include "../global/rel.h"
#include "../global/config.h"
#include "../global/global.h"
#include "../util/mem.h"
#include "../util/hash.h"
#include "../cache/cache.h"
#include "../node/parseNodes.h"
#include <string.h>
#include <stdlib.h>

void appendTupleToBuff(HeapTupleHeaderData* tuple, Relation* tableRelation, int columnNo, char* buff, int* offset) {
	char* addr = (char*)(tuple->bits) + (tableRelation->columnsSet->count / 8) + 1;
	for(int j = 0; j <= columnNo; j++) {
		int bitNo = j / 8;
		int bitIndex = j % 8;
		int isNull = tuple->bits[bitNo] & (1 << bitIndex);
		if(isNull) {
			if(j == columnNo) {
				char c = *(buff + ((columnNo - 1) / 8));
				c |= 1 << (columnNo % 8);
				*(buff + ((columnNo - 1) / 8)) = c;
				break;
			}
			continue;
		}
		DB_Columns* columns = tableRelation->columnsSet->columns[j];
		int flexible = columns->flag & 0x1;
		if(flexible == 1) { //flexible
			int len = addr[0] >> 1;
			if(j == columnNo) {
				memcpy(buff + *offset, addr, len);
				*offset = *offset + len;
				break;
			}
			addr = addr + len;
		} else {
			int len = columns->length;
			if(j == columnNo) {
				int type = columns->flag >> 2;
				switch(type) {
					case F_CHAR:
					case F_SHORT:
					case F_INT:
					{
						int val = *((int*)addr);
						for(int i = 0; i < 4; i++) {
							memset(buff + *offset + i, val >> ((3 - i) * 8), 1);
						}
						*offset = *offset + 4;
						break;
					}
					case F_LONG:

						break;
					default:
						break;

				}
				break;
			}
			addr = addr + len;
		}
	}
}

int getPos(Relation* indexRelation, int hash, int tupleLength, int bitCount) {
	int blockNo = getFreePageBlock(indexRelation);
	char* page = (BufferBlocks + (blockNo * BUFFERS_SIZE));
	PageHeaderData* pageHeaderData = (PageHeaderData*) page;
	if(pageHeaderData->end_of_free_space - (((8 + tupleLength) / 8 + 1) * 8) - pageHeaderData->start_of_free_space - 4 < 0) {
		return -1;
	}
	int count = (pageHeaderData->start_of_free_space - 28) / 4;
	if(count == 0) {
		return 0;
	}
	IndexRange* indexRange = (IndexRange*)(page + INDEX_RANGE_OFFSET);
	if(hash <= indexRange->min) {
		return -2;
	}
	if(hash >= indexRange->max) {
		return indexRange->indexCount;
	}
	for(int i = 0; i < count; i++) {
		ItemIdData itemIdData = pageHeaderData->tuple_desc[i];
		IndexTupleData* indexTupleData = (IndexTupleData*)(page + itemIdData.lp_off);
		int len = indexTupleData->bits & INDEX_SIZE_MASK;
		int _hash = hashCode((char*)indexTupleData + 8 + bitCount, len);
		if(_hash > hash){
			return i;
		}
	}
	return -1;
}

void writeToIndex(Relation* indexRelation, IndexTupleData* indexTupleData, char* buff, int tupleLength, int pos, int hash) {
	if(pos == -1) {
		//TODO make new page
		return;
	}
	int blockNo = getFreePageBlock(indexRelation);
	char* page = (BufferBlocks + (blockNo * BUFFERS_SIZE));
	PageHeaderData* pageHeaderData = (PageHeaderData*) page;
	IndexRange* indexRange = (IndexRange*)(page + INDEX_RANGE_OFFSET);
	pageHeaderData->end_of_free_space = pageHeaderData->end_of_free_space - (((8 + tupleLength) / 8 + 1) * 8);
	memcpy(page + pageHeaderData->end_of_free_space, indexTupleData, 8);
	memcpy(page + pageHeaderData->end_of_free_space + 8, buff, tupleLength);
	if(pos == 0 || pos == indexRange->indexCount) {
		pageHeaderData->tuple_desc[pos].lp_flag = 1;
		pageHeaderData->tuple_desc[pos].lp_len = 8 + tupleLength;
		pageHeaderData->tuple_desc[pos].lp_off = pageHeaderData->end_of_free_space;
		pageHeaderData->start_of_free_space += 4;
		indexRange->indexCount++;
		if(pos == 0) {
			indexRange->min = hash;
		}
		indexRange->max = hash;
	} else {
		if(pos == -2) {
			pos = 0;
			indexRange->min = hash;
		}
		int start = 28 + (4 * pos);
		char* tempBuff = malloc_local(pageHeaderData->start_of_free_space - start);
		memcpy(tempBuff, page + start, pageHeaderData->start_of_free_space - start);
		memcpy(page + start + 4, tempBuff, pageHeaderData->start_of_free_space - start);
		free(tempBuff);
		pageHeaderData->tuple_desc[pos].lp_flag = 1;
		pageHeaderData->tuple_desc[pos].lp_len = 8 + tupleLength;
		pageHeaderData->tuple_desc[pos].lp_off = pageHeaderData->end_of_free_space;
		pageHeaderData->start_of_free_space += 4;
		indexRange->indexCount++;
	}

}

void btreeInsert(HeapTupleHeaderData* tuple, int tupleLength, Relation* tableRelation, Relation* indexRelation) {
	CreateIndexRelationExtend* extend = (CreateIndexRelationExtend*)indexRelation->ext;
	char* buff = malloc_local(BUFFERS_SIZE);
	int offset = (extend->columnsIdCount - 1) / 8 + 1;
	int bitCount = offset;
	for(int i = 0; i < extend->columnsIdCount; i++){
		int columnNo = extend->columnsNo[i];
		appendTupleToBuff(tuple, tableRelation, columnNo, buff, &offset);
	}
	int hash = hashCode(buff + bitCount, offset - bitCount);
	int pos = getPos(indexRelation, hash, offset, bitCount);
	IndexTupleData* indexTupleData = malloc_local(sizeof(IndexTupleData));
	indexTupleData->item_desc.page_hi = tuple->item_desc.page_hi;
	indexTupleData->item_desc.page_low = tuple->item_desc.page_low;
	indexTupleData->item_desc.pos_id = tuple->item_desc.pos_id;
	indexTupleData->bits = offset - bitCount;
	writeToIndex(indexRelation, indexTupleData, buff, offset, pos, hash);
	free(buff);
}

void btreeSearch(IndexData* indexData, char* page, int hash, int offset) {
	PageHeaderData* pageHeaderData = (PageHeaderData*)page;
	int count = (pageHeaderData->start_of_free_space - 28) / 4;
	if(count == 0) {
		return;
	}
	if(count == 1) {
		ItemIdData itemIdData = pageHeaderData->tuple_desc[0];
		IndexTupleData* indexTuple = (IndexTupleData*)(page + itemIdData.lp_off);
		int len = indexTuple->bits & INDEX_SIZE_MASK;
		int _hash = hashCode(((char*)indexTuple) + 8 + offset, len);
		if(_hash == hash) {
			indexData->min = 0;
		}
		return;
	}
	int mid = (count - 1) / 2;
	int max = count - 1;
	int min = 0;
	//search left
	int sig = 0;
	while(mid < max) {
		ItemIdData itemIdData = pageHeaderData->tuple_desc[mid];
		IndexTupleData* indexTuple = (IndexTupleData*)(page + itemIdData.lp_off);
		int len = indexTuple->bits & INDEX_SIZE_MASK;
		int _hash = hashCode(((char*)indexTuple) + 8 + offset, len);
		if(hash == _hash){
			if(indexData->start == mid) {
				break;
			}
			indexData->start = mid;
		}
		if(_hash >= hash) {
			max = mid;
			mid = (max - min) / 2 + min;
		} else {
			min = mid;
			mid = (max - min + 1) / 2 + min;
		}
		sig++;
		if(sig >= count){
			break;
		}

	}
	mid = (count - 1) / 2;
	max = count - 1;
	min = 0;
	sig = 0;
	//search right
	while(min < mid) {
		ItemIdData itemIdData = pageHeaderData->tuple_desc[mid];
		IndexTupleData* indexTuple = (IndexTupleData*)(page + itemIdData.lp_off);
		int len = indexTuple->bits & INDEX_SIZE_MASK;
		int _hash = hashCode(((char*)indexTuple) + 8 + offset, len);
		if(hash == _hash){
			if(indexData->end == mid) {
				break;
			}
			indexData->end = mid;
		}
		if(_hash <= hash) {
			min = mid;
			mid = (max - min + 1) / 2 + min;
		} else {
			max = mid;
			mid = (max - min) / 2 + min;
		}
		sig++;
		if(sig >= count){
			break;
		}
	}
}

IndexSet* collectIndexSet(Index* index, List* whereClause) {
	DB_Columns_Set* columnsSet = index->columnsSet;
	ListNode* listNode;
	char* buff = malloc_local(BUFFERS_SIZE);
	int len = 0;
	for(int i = 0; i < columnsSet->count; i++) {
		DB_Columns* columns = columnsSet->columns[i];
		listNode = (void*)0;
		foreach(listNode, whereClause) {
			WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
			if(whereCondition->isList == 0 && whereCondition->condition == 1) {
				if(whereCondition->whereSingle->right.isVal == 1){
					if(strcmp(whereCondition->whereSingle->left.tableAlias, columns->tableInfo->alias) == 0 && strcmp(whereCondition->whereSingle->left.field, columns->fieldName) == 0){
						int flexible = columns->flag & 0x1;
						if(flexible == 1) { //flexible
							int size = strlen(whereCondition->whereSingle->right.val);
							memset(buff + len, ((size + 1) << 1) + 1, 1);
							len += 1;
							memcpy(buff + len, whereCondition->whereSingle->right.val, size);
							len += size;
						} else {
							int type = columns->flag >> 2;
							switch(type) {
								case F_CHAR:
								case F_SHORT:
								case F_INT:
								{
									char* cVal = whereCondition->whereSingle->right.val;
									int val = atoi(cVal);
									for(int i = 0; i < 4; i++) {
										memset(buff + len + i, val >> ((3 - i) * 8), 1);
									}
									len += 4;
									break;
								}
								case F_LONG:

									break;
								default:
									break;

							}
						}
						break;
					}
				}
			}
		}
	}
	int hash = hashCode(buff, len);
	free(buff);
	List* blocks = getPageBlocks(index->fileNode);
	IndexSet* indexSet = malloc_local(sizeof(IndexSet) + (sizeof(IndexData*) * blocks->length));
	indexSet->pageCount = blocks->length;
	listNode = (void*)0;
	int idx = 0;
	int offset = (columnsSet->count - 1) / 8 + 1;
	foreach(listNode, blocks) {
		int blockNo = listNode->value.int_val;
		char* page = BufferBlocks + (blockNo * BUFFERS_SIZE);
		IndexRange* indexRange = (IndexRange*)(page + INDEX_RANGE_OFFSET);
		IndexData* indexData = malloc_local(sizeof(IndexData));
		indexData->min = indexRange->min;
		indexData->max = indexRange->max;
		indexData->indexCount = indexRange->indexCount;
		indexData->pageNo = blockNo;
		indexData->start = -1;
		indexData->end = -1;
		indexSet->data[idx] = indexData;
		idx++;
		if(hash < indexRange->min || hash > indexRange->max) {
			continue;
		}
		btreeSearch(indexData, page, hash, offset);
	}
	return indexSet;
}
