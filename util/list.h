/*
 * list.h
 *
 *  Created on: Apr 11, 2023
 *      Author: choi
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct ListNode{
	union{
		void *ptr_val;
		int int_val;
	} value;
	struct ListNode *next;
}ListNode;

typedef struct List{
	int length;
	ListNode *node;
	ListNode *tail;
} List;

#define foreach(cell, l) \
	for((cell) = l->node; (cell)->next != (void*)0; (cell) = cell->next)


extern List* makeList();
extern void listAppend(List* list, void* val);
extern void listAppend_int(List* list, int val);
extern void freeList(List* list);
extern int listGet_int(List* list, int i);
extern void* listGet(List* list, int i);


#endif /* LIST_H_ */
