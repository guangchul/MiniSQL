/*
 * fileNode.c
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */
#include <string.h>

#include "../cache/cache.h"
#include "file.h"
#include <stdlib.h>
#include "../global/machine.h"
#include "../util/mem.h"
#ifdef WIN
#include <sys/stat.h>
#endif

void makeFileNode(FileNode* fileNode) {
	if(fileNode->fd <= 0) {
		if(fileNode->schema != (void*)0 && fileNode->file != (void*) 0) {
			int len = strlen(fileNode->schema) + 1 + strlen(fileNode->file) + 1;
			char fileName[len];
			fileName[0] = 0;
			strcat(fileName, fileNode->schema);
			strcat(fileName, "/");
			strcat(fileName, fileNode->file);
			fileName[len] = 0;
			char* val = (char*)getFromHashMap(BUFFER_CACHE, (void*)&fileName);
			if(val == (void*)0) {
#ifdef WIN
				int mode = O_RDWR|O_CREAT|O_BINARY;
#endif
#ifdef LINUX
				int mode = O_RDWR|O_CREAT|FILE_BINARY;
#endif
				int perm = (S_IRUSR | S_IWUSR);
				fileNode->fd = fileOpen(fileName, mode, perm);
				char* fdStr = malloc_local(5);
				for(int i = 0; i < 4; i++){
					memset(fdStr + i, fileNode->fd >> (8 * i), 1);
				}
				putToHashMap(1, (void*)&fileName, fdStr);
			} else {
				fileNode->fd = *((int*)val);
			}
		}
	}
}
