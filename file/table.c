/*
 * createTable.c
 *
 *  Created on: Apr 12, 2023
 *      Author: choi
 */
#include "../global/rel.h"
#include "../global/page.h"
#include "../global/config.h"
#include "../global/global.h"
#include "file.h"
#include "../util/list.h"
#include "../util/mem.h"
#include "../cache/cache.h"
#include "../process/process.h"
#include "../index/index.h"
#include <stdlib.h>
#include <string.h>

int createTable(FileNode* fileNode, PageHeaderData* pageHeaderData){
	if(fileNode->fd <= 0) {
		if(fileNode->schema == (void*)0 || fileNode->file == (void*)0) {
			return -1;
		}
		makeFileNode(fileNode);
	}
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
	char* buffer = malloc_local(0x2000);

	memcpy(buffer, pageHeaderData, sizeof(PageHeaderData));
	int result = fileWrite(fileNode->fd, buffer, 0, BUFFERS_SIZE);
	free(buffer);
	return result;
}

int createIndex(FileNode* fileNode) {
	if(fileNode->fd <= 0) {
		if(fileNode->schema == (void*)0 || fileNode->file == (void*)0) {
			return -1;
		}
		makeFileNode(fileNode);
	}
	PageHeaderData* pageHeaderData = malloc_local(sizeof(PageHeaderData));
	pageHeaderData->un_distributed_1.xlogid = 0;
	pageHeaderData->un_distributed_1.xrecoff = 0;
	pageHeaderData->un_distributed_2 = 0;
	pageHeaderData->un_distributed_4 = 0;
	pageHeaderData->un_distributed_5 = 0;
	pageHeaderData->un_distributed_6 = 0;
	pageHeaderData->page_flags = 0;
	pageHeaderData->start_of_free_space = 28;
	pageHeaderData->end_of_free_space = BUFFERS_SIZE - 16;
	pageHeaderData->page_no = 0;
	IndexRange* indexRange = malloc_local(sizeof(IndexRange));
	indexRange->indexCount = 0;
	indexRange->max = 0;
	indexRange->min = 0;
	char* buffer = malloc_local(0x2000);

	memcpy(buffer, pageHeaderData, sizeof(PageHeaderData));
	memcpy(buffer + INDEX_RANGE_OFFSET, indexRange, sizeof(IndexRange));
	int result = fileWrite(fileNode->fd, buffer, 0, BUFFERS_SIZE);
	free(buffer);
	free(pageHeaderData);
	free(indexRange);
	return result;
}

int insert(Relation* relation) {
	char buffer[BUFFERS_SIZE];
	InsertRelationExtend* extend = (InsertRelationExtend*)relation->ext;
	FieldValuesList* fieldValuesList = extend->fieldValuesList;
	FieldNodes* fieldNodes = extend->fieldNodes;
	for(int i = 0; i < fieldValuesList->length; i++){
		FieldValues* fieldValues = extend->fieldValuesList->fieldValues[i];
		int bitCount = (fieldValues->length - 1) / 8 + 1;
		char bits[bitCount];
		memset(bits, 0, bitCount);
		int bufferOffset = 0;
		uint16 flag_bits = 0;
		uint16 attrs_count = 0;
		for(int j = 0; j < fieldValues->length; j++){
			FieldValue* fieldValue = fieldValues->value[j];
			FieldNode* attr = fieldNodes->fieldNode[j];
			if(((attr->flag & 0x02) == 0x02) && (fieldValue->value.ptr_value == (void*)0)) {
				flag_bits |= 0x01;
				int bitSeq = attrs_count / 8;
				int bitOff = attrs_count % 8;
				int flag = 1 << bitOff;
				bits[bitSeq] |= flag;
			} else {
				if((attr->flag & 0x01) == 1) {
					short len = strlen(fieldValue->value.ptr_value);
					short _len = ((len + 1) << 1) + 1;
					memcpy(buffer + bufferOffset, &_len, 1);
					bufferOffset += 1;
					memcpy(buffer + bufferOffset, fieldValue->value.ptr_value, len);
					bufferOffset += len;
				} else {
					for(int seq = 0; seq < attr->length; seq++){
						*(buffer + bufferOffset + seq) = 0;
					}
					int l = 0;
					for(;;) {
						if((fieldValue->value.long_value >> (sizeof(long) * l)) > 0) {
							*(buffer + bufferOffset + l) = fieldValue->value.long_value >> (l * 8);
						} else {
							break;
						}
						l++;
					}
					bufferOffset += attr->length;
				}
			}
			attrs_count++;
		}
		HeapTupleHeaderData* heapTupleHeaderData = malloc_local(sizeof(HeapTupleHeaderData) + bitCount + bufferOffset);
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_01 = 0;
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_02 = 0;
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_03 = 0;
		heapTupleHeaderData->offset_of_data = 23 + bitCount;
		heapTupleHeaderData->flag_bits = flag_bits;
		heapTupleHeaderData->attrs_count = attrs_count;
		memcpy(heapTupleHeaderData->bits, bits, bitCount);
		memcpy(heapTupleHeaderData->bits + bitCount, buffer, bufferOffset);
		int dataSize = 23 + bitCount + bufferOffset;
		int block = getFreePageBlock(relation);
		PageHeaderData* pageHeaderData = (PageHeaderData*) (BufferBlocks + (block * BUFFERS_SIZE));
		heapTupleHeaderData->item_desc.page_hi = pageHeaderData->page_no >> 16;
		heapTupleHeaderData->item_desc.page_low = pageHeaderData->page_no & 0xFFFF;
		heapTupleHeaderData->item_desc.pos_id = (pageHeaderData->start_of_free_space - 28) / 4;
		int endOfFreeSpace = (pageHeaderData->end_of_free_space - dataSize) / 8 * 8;
		int startOfFreeSpace = pageHeaderData->start_of_free_space + 4;
		if(startOfFreeSpace > endOfFreeSpace) {

		} else {
			char* page = (char*)(BufferBlocks + (BUFFERS_SIZE * block));
			memcpy(page + endOfFreeSpace, heapTupleHeaderData, dataSize);
			ItemIdData* itemData = malloc_local(sizeof(ItemIdData));
			itemData->lp_flag = 1;
			itemData->lp_len = dataSize;
			itemData->lp_off = endOfFreeSpace;
			memcpy(page + pageHeaderData->start_of_free_space, itemData, sizeof(ItemIdData));
			pageHeaderData->start_of_free_space = startOfFreeSpace;
			pageHeaderData->end_of_free_space = endOfFreeSpace;
			memcpy(page, pageHeaderData, sizeof(PageHeaderData));
			blockWriteToFile(relation, block, pageHeaderData->page_no * BUFFERS_SIZE);
			free(itemData);
		}
		DB_Index_Set* indexSet = getIndexSet(relation->tableInfo, relation->fileNode->schema);
		for(int i = 0; i < indexSet->count; i++) {
			DB_Index* dbIndex = indexSet->index[i];
			Relation* indexRelation = getIndexRelation(dbIndex, relation);
			btreeInsert(heapTupleHeaderData, dataSize, relation, indexRelation);
			flushTable(indexRelation);
		}
		free(heapTupleHeaderData);
	}
	return 0;
}

void updateOriginTuple(Relation* relation, HeapTupleHeaderData* originTuple, int tupleLen, char* buffer, int bufferLen){
	List* list = getPageBlocks(relation->fileNode);
	int pageNo = originTuple->item_desc.page_hi << 16 | originTuple->item_desc.page_low;
	int posId = originTuple->item_desc.pos_id;
	int pageId = listGet_int(list, pageNo);
	char* page = BufferBlocks + (pageId * BUFFERS_SIZE);
	PageHeaderData* pageHeaderData = (PageHeaderData*)page;
	ItemIdData itemIdData = pageHeaderData->tuple_desc[posId];
	memset(page + itemIdData.lp_off + 23, 0, itemIdData.lp_len - 23);
	memcpy(page + itemIdData.lp_off + 23, buffer, bufferLen);
	itemIdData.lp_len = 23 + bufferLen;
	memcpy(page + 28 + (posId * 4), &itemIdData, 4);
}

void updateNewTuple(Relation* relation, HeapTupleHeaderData* originTuple, int tupleLen, int attrCount, char* buffer, int bufferLen, unsigned short flag_bits) {
	int block = getFreePageBlock(relation);
	PageHeaderData* pageHeaderData = (PageHeaderData*) (BufferBlocks + (block * BUFFERS_SIZE));
	int endOfFreeSpace = (pageHeaderData->end_of_free_space - (bufferLen + 23)) / 8 * 8;
	int startOfFreeSpace = pageHeaderData->start_of_free_space + 4;
	int freeSpaceCount = endOfFreeSpace - startOfFreeSpace;
	int pageNo = pageHeaderData->page_no;
	int posId = 0;
	if(freeSpaceCount >= 0) {
		HeapTupleHeaderData* heapTupleHeaderData = malloc_local(sizeof(HeapTupleHeaderData) + bufferLen);
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_01 = 0;
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_02 = 0;
		heapTupleHeaderData->un_distributed_01.un_distributed_uint96_03 = 0;
		heapTupleHeaderData->offset_of_data = 23 + ((attrCount - 1) / 8 + 1) ;
		heapTupleHeaderData->flag_bits = flag_bits;
		heapTupleHeaderData->attrs_count = attrCount | 0x8000;
		heapTupleHeaderData->item_desc.page_hi = pageHeaderData->page_no >> 16;
		heapTupleHeaderData->item_desc.page_low = pageHeaderData->page_no & 0xFFFF;
		heapTupleHeaderData->item_desc.pos_id = (pageHeaderData->start_of_free_space - 28) / 4;
		memcpy(heapTupleHeaderData->bits, buffer, bufferLen);
		char* page = (char*)(BufferBlocks + (BUFFERS_SIZE * block));
		memcpy(page + endOfFreeSpace, heapTupleHeaderData, 23 + bufferLen);
		ItemIdData* itemData = malloc_local(sizeof(ItemIdData));
		itemData->lp_flag = 1;
		itemData->lp_len = 23 + bufferLen;
		itemData->lp_off = endOfFreeSpace;
		posId = (pageHeaderData->start_of_free_space - 28) / 4;
		memcpy(page + pageHeaderData->start_of_free_space, itemData, sizeof(ItemIdData));
		pageHeaderData->start_of_free_space = startOfFreeSpace;
		pageHeaderData->end_of_free_space = endOfFreeSpace;
		memcpy(page, pageHeaderData, sizeof(PageHeaderData));
		free(itemData);
		free(heapTupleHeaderData);
	} else {

	}
	List* list = getPageBlocks(relation->fileNode);
	int _pageNo = originTuple->item_desc.page_hi << 16 | originTuple->item_desc.page_low;
	int _posId = originTuple->item_desc.pos_id;
	int _pageId = listGet_int(list, _pageNo);
	char* _page = BufferBlocks + (_pageId * BUFFERS_SIZE);
	PageHeaderData* _pageHeaderData = (PageHeaderData*)_page;
	ItemIdData itemIdData = _pageHeaderData->tuple_desc[_posId];
	HeapTupleHeaderData* heapTupleHeaderData = (HeapTupleHeaderData*)(_page + itemIdData.lp_off);
	heapTupleHeaderData->item_desc.page_hi = pageNo >> 16;
	heapTupleHeaderData->item_desc.page_low = pageNo & 0xFFFF;
	heapTupleHeaderData->item_desc.pos_id = posId;
	heapTupleHeaderData->attrs_count |= 0x4000;
}

void deleteTuple(Relation* relation, HeapTupleHeaderData* tuple) {
	List* list = getPageBlocks(relation->fileNode);
	int pageNo = tuple->item_desc.page_hi << 16 | tuple->item_desc.page_low;
	int posId = tuple->item_desc.pos_id;
	int pageId = listGet_int(list, pageNo);
	char* page = BufferBlocks + (pageId * BUFFERS_SIZE);
	PageHeaderData* pageHeaderData = (PageHeaderData*)page;
	ItemIdData itemIdData = pageHeaderData->tuple_desc[posId];
	HeapTupleHeaderData* heapTupleHeaderData = (HeapTupleHeaderData*)(page + itemIdData.lp_off);
	heapTupleHeaderData->attrs_count |= 0x2000;
}

