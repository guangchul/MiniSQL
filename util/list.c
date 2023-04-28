/*
 * list.c
 *
 *  Created on: Apr 11, 2023
 *      Author: choi
 */


#include "list.h"
#include <stdlib.h>

List* makeList() {
	List* list;
	list = malloc(sizeof(List));
	ListNode* listNode = malloc(sizeof(ListNode));
	listNode->next = (void*)0;
	listNode->value.ptr_val = (void*)0;
	listNode->value.int_val = 0;
	list->node = listNode;
	list->tail = list->node;
	list->length = 0;
	return list;
}

void listAppend(List* list, void* val) {
	list->tail->value.ptr_val = val;
	ListNode* next = malloc(sizeof(ListNode));
	next->next = (void*)0;
	next->value.ptr_val = (void*)0;
	list->tail->next = next;
	list->tail = next;
	list->length++;
}

void listAppend_int(List* list, int val) {
	list->tail->value.int_val = val;
	ListNode* next = malloc(sizeof(ListNode));
	next->next = (void*)0;
	next->value.ptr_val = (void*)0;
	list->tail->next = next;
	list->tail = next;
	list->length++;
}

int listGet_int(List* list, int i){
	int idx = 0;
	ListNode* listNode;
	foreach(listNode, list) {
		if(i == idx) {
			return listNode->value.int_val;
		}
		idx++;
	}
	return -1;
}

void* listGet(List* list, int i) {
	int idx = 0;
	ListNode* listNode;
	foreach(listNode, list) {
		if(i == idx) {
			return listNode->value.ptr_val;
		}
		idx++;
	}
	return (void*)0;
}

void freeList(List* list) {
	ListNode* listNode = list->node;
	for(;;) {
		ListNode* next = listNode->next;
		free(listNode);
		if(next == (void*)0) {
			break;
		}
		listNode = next;
	}
	free(list);
}
