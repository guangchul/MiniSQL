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

extern void makeDir(const char* pathname, mode_t mode);
extern
#ifdef WIN
FILE*
#endif
#ifdef LINUX
int
#endif
fileOpen(const char *file, int mode, int perm);
#ifdef WIN
extern int fileRead(FILE* fd, void* buff, off_t offset, size_t size);
#endif
#ifdef LINUX
extern int fileRead(int fd, void* buff, off_t offset, size_t size);
#endif
#ifdef WIN
extern int fileWrite(FILE* fd, char *ptr, off_t offset, size_t size);
#endif
#ifdef LINUX
extern int fileWrite(int fd, char *ptr, off_t offset, size_t size);
#endif
extern void makeFileNode(FileNode* fileNode);
extern int createTable(FileNode* fileNode, PageHeaderData* pageHeaderData);
extern int insert(Relation* relation);

#endif /* FILE_H_ */
