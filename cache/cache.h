/*
 * catch.h
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */

#ifndef CACHE_H_
#define CACHE_H_

#define CACHE_SIZE 8192

#define SYSTEM_CACHE 0
#define BUFFER_CACHE 1
#define BLOCKS_CACHE 2
#define TABLE_INFO 3
#define COLUMN_INFO 4
#define INDEX_INFO 5

#define MAPS_SIZE 6

#include "../global/rel.h"

extern void* getFromHashMap(int cacheId, void* key);
extern int putToHashMap(int cacheId, void* key, void* val);
extern List* getPageBlocks(FileNode* fileNode);
extern int getFreePageBlock(Relation* relation);
extern void blockWriteToFile(Relation* relation, int blockNo, int offset);
extern int getFreeTempBufferBlockNo();
extern void freeTempBufferBlock(int blockNo);
extern void flushTable(Relation* relation);

#endif /* CACHE_H_ */
