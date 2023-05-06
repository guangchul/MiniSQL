/*
 * portalDeleteStmt.c
 *
 *  Created on: May 6, 2023
 *      Author: choi
 */

#include "process.h"
#include "../file/file.h"
#include "../cache/cache.h"

void runDeleteStmt(DeleteStmt* node, List* relationList) {
	Slot* slot = malloc_local(sizeof(Slot));
	DB_Columns_Set* columnsSet = makeSlotColumnsSet(relationList);
	slot->columnsSet = columnsSet;
	slot->tuple_len = 0;
	slot->tuple = (void*)0;
	slot->end = 0;
	slot->loop = 0;
	int* isOut = malloc_local(sizeof(int));
	*isOut = 1;
	for(;;) {
		makeSlot(relationList->node, slot, node->whereClause, isOut);

		if(slot->tuple != (void*)0 && fileter(slot, node->whereClause) == 1){
			deleteTuple((Relation*)relationList->node->value.ptr_val, slot->tuple);
		}
		if(slot->end == 1) {
			break;
		}
	}
	flushTable((Relation*)relationList->node->value.ptr_val);
}
