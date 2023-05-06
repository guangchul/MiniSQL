/*
 * file.h
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */

#ifndef FILE_H_
#define FILE_H_

#define FILE_BINARY 0

#include <fcntl.h>
#include <stddef.h>
#include "../global/rel.h"
#include "../global/page.h"
#include "../global/machine.h"
#include <sys/types.h>

extern void makeDir(const char* pathname, mode_t mode);
extern int fileOpen(const char *file, int mode, int perm);
extern int fileRead(int fd, void* buff, off_t offset, size_t size);
extern int fileWrite(int fd, char *ptr, off_t offset, size_t size);
extern void makeFileNode(FileNode* fileNode);
extern int createTable(FileNode* fileNode, PageHeaderData* pageHeaderData);
extern int insert(Relation* relation);
extern void updateOriginTuple(Relation* relation, HeapTupleHeaderData* originTuple, int tupleLen, char* buffer, int bufferLen);
extern void updateNewTuple(Relation* relation, HeapTupleHeaderData* originTuple, int tupleLen, int attrCount, char* buffer, int bufferLen, unsigned short flag_bits);
extern void deleteTuple(Relation* relation, HeapTupleHeaderData* tuple);

#endif /* FILE_H_ */
