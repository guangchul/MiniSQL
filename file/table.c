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

int insert(Relation* relation) {
	char buffer[BUFFERS_SIZE];
	FieldValuesList* fieldValuesList = relation->fieldValuesList;
	FieldNodes* fieldNodes = relation->fieldNodes;
	for(int i = 0; i < fieldValuesList->length; i++){
		FieldValues* fieldValues = relation->fieldValuesList->fieldValues[i];
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
		heapTupleHeaderData->un_distributed_02.un_distributed_uint48_01 = 0;
		heapTupleHeaderData->un_distributed_02.un_distributed_uint48_02 = 0;
		heapTupleHeaderData->un_distributed_02.un_distributed_uint48_03 = 0;
		heapTupleHeaderData->offset_of_data = 23 + bitCount;
		heapTupleHeaderData->flag_bits = flag_bits;
		heapTupleHeaderData->attrs_count = attrs_count;
		memcpy(heapTupleHeaderData->bits, bits, bitCount);
		memcpy(heapTupleHeaderData->bits + bitCount, buffer, bufferOffset);
		int dataSize = 23 + bitCount + bufferOffset;
		int block = getFreePageBlock(relation);
		PageHeaderData* pageHeaderData = (PageHeaderData*) (BufferBlocks + (block * BUFFERS_SIZE));
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
		free(heapTupleHeaderData);
	}
	return 0;
}

