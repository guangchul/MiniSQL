/*
 * portalUpdateStmt.c
 *
 *  Created on: May 4, 2023
 *      Author: choi
 */

#include "process.h"

void runUpdateStmt(UpdateStmt* node, List* relationList){
//	Slot* slot = malloc_local(sizeof(Slot));
//	FieldNodes* fieldNodes = makeSlotFieldNodes(relationList);
//	slot->fieldNodes = fieldNodes;
//	slot->tuple_len = 0;
//	slot->tuple = (void*)0;
//	slot->end = 0;
//	slot->loop = 0;
//	int* isOut = malloc_local(sizeof(int));
//	*isOut = 1;
//	for(;;) {
//		makeSlot(relationList->node, slot, node->whereClause, isOut);
//		if(slot->end == 1) {
//			break;
//		}
//		if(fileter(slot, node->whereClause) == 1){
//			writeResult(slot, node);
//		}
//	}
}
