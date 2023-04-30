/*
 * cache.c
 *
 *  Created on: Apr 15, 2023
 *      Author: choi
 */


#include "../util/list.h"
#include "cache.h"
#include "../global/config.h"
#include "../global/global.h"
#include "../file/file.h"
#include <string.h>

int cacheBlockSeq = 0;

List* getPageBlocks(FileNode* fileNode) {
	int len = strlen(fileNode->schema) + 1 + strlen(fileNode->file) + 1;
	char key[len];
	key[0] = 0;
	strcat(key, fileNode->schema);
	strcat(key, "/");
	strcat(key, fileNode->file);
	key[strlen(fileNode->schema) + 1 + strlen(fileNode->file) + 1] = 0;
	List* list = getFromHashMap(BLOCKS_CACHE, key);
	if(list == (void*)0) {
		list = makeList();
		int pageNo = 0;
		for(;;) {
			char buffer[BUFFERS_SIZE];
			int read = fileRead(fileNode->fd, buffer, pageNo * BUFFERS_SIZE, BUFFERS_SIZE);
			if(read == -1) {
				break;
			}
			memcpy(BufferBlocks + (cacheBlockSeq * BUFFERS_SIZE), buffer, BUFFERS_SIZE);
			listAppend_int(list, cacheBlockSeq);
			cacheBlockSeq++;
			pageNo++;
		}
		putToHashMap(BLOCKS_CACHE, key, list);
	}
	return list;
}

int getFreePageBlock(Relation* relation) {
	List* list = getPageBlocks(relation->fileNode);
	if(list->length == 0) {
		return -1;
	}
	ListNode* listNode;
	int block;
	foreach(listNode, list) {
		block = listNode->value.int_val;
		PageHeaderData* pageHeaderData = (PageHeaderData*) (BufferBlocks + (block * BUFFERS_SIZE));
		if((pageHeaderData->page_flags & 0x02) != 0x02) {
			return block;
		}
	}
	return block;
}

void blockWriteToFile(Relation* relation, int blockNo, int offset) {
	//char buffer[8192];
	char* page = (char*) (BufferBlocks + (BUFFERS_SIZE * blockNo));
	//memcpy(buffer, page, BUFFERS_SIZE);
	fileWrite(relation->fileNode->fd, page, offset, BUFFERS_SIZE);
}

int getFreeTempBufferBlockNo() {
	for(int i = 0; i < BLOCKS_SIZE; i++) {
		if(usingTempBufferBlocks[i] == 0) {
			usingTempBufferBlocks[i] = 1;
			return i;
		}
	}
	return -1;
}

void freeTempBufferBlock(int blockNo) {
	usingTempBufferBlocks[blockNo] = 0;
}
