/*
 * hashmap.c
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */
#include "cache.h"
#include <stdlib.h>
#include "../global/machine.h"
#include "../util/mem.h"

#define NODES_SIZE 32


typedef struct HashMapNode{
	unsigned int key;
	void* value;
	struct HashMapNode* next;
} HashMapNode;

typedef struct HashMap{
	HashMapNode* nodes[NODES_SIZE];
} HashMap;

HashMap* hashMaps[MAPS_SIZE];

unsigned int calHashCode(void* key) {
	unsigned int h = 0;
	int i = 0;
	char* _key = (char*)key;
	for(;;) {
		char c = *(_key + i);
		if(c == 0) {
			break;
		}
		i++;
		h = 31 * h + (c & 0xff);
	}
	h = h ^ ((h & 0xffffffff) >> 16);
	return h;
}

void* getFromHashMap(int cacheId, void* key) {
	HashMap* hashMap = hashMaps[cacheId];
	if(hashMap != (void*)0) {
		unsigned int hashCode = calHashCode(key);
		int hashIndex = hashCode & (NODES_SIZE - 1);
		HashMapNode* node = hashMap->nodes[hashIndex];
		if(node != (void*)0) {
			for(;;) {
				if(node->key == hashCode) {
					return node->value;
				}
				node = node->next;
			}
		}
	}
	return (void*)0;
}

int putToHashMap(int cacheId, void* key, void* val) {
	if(hashMaps[cacheId] == (void*) 0) {
		hashMaps[cacheId] = malloc_local(sizeof(HashMap));
	}
	HashMap* hashMap = hashMaps[cacheId];
	unsigned int hashCode = calHashCode(key);
	int hashIndex = hashCode & (NODES_SIZE - 1);
	HashMapNode* node = hashMap->nodes[hashIndex];
	if(node == (void*)0) {
		hashMap->nodes[hashIndex] = malloc(sizeof(HashMapNode));
		hashMap->nodes[hashIndex]->key = hashCode;
		hashMap->nodes[hashIndex]->value = val;
	} else {
		for(;;) {
			if(node->key == hashCode) {
				node->value = val;
				break;
			}
			if(node->next == (void*)0){
				HashMapNode* _node = malloc(sizeof(HashMapNode));
				_node->key = hashCode;
				_node->value = val;
				node->next = _node;
				break;
			}
			node = node->next;
		}
	}
	return 0;
}
