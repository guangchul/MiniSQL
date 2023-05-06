/*
 * process.h
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include "../global/rel.h"
#include "../global/slot.h"
#include "../node/parseNodes.h"

extern void processMain(char* schema);
extern void initSingle();
extern List* analyze(Node* node, char* schema);
extern int getTableNextId(Relation* relation);
extern void portalRun(Node* node, List* relationList, char* processSchema);
extern DB_Table* getTableInfo(char* schema, char* tableName, char* alias);
extern DB_Columns_Set* getColumnsSet(char* schema, DB_Table* tableInfo);
extern List* analyzeSelectStmt(SelectStmt* node, char* schema);
extern void runSelectStmt(SelectStmt* node, List* relationList);
extern void writeResult(Slot* slot, SelectStmt* node);
extern char* getVal(HeapTupleHeaderData* tuple, DB_Columns_Set* columnsSet, int i);
extern char* getFieldVal(Slot* slot, Field field);
extern List* analyzeUpdateStmt(UpdateStmt* node, char* schema);
extern void runUpdateStmt(UpdateStmt* node, List* relationList);
extern DB_Columns_Set* makeSlotColumnsSet(List* relationList);
extern void makeSlot(ListNode* listNode, Slot* slot, List* whereClause, int* isOut);
extern int fileter(Slot* slot, List* whereClause);
extern List* analyzeDeleteStmt(DeleteStmt* node, char* schema);
extern void checkUpdateWhereClause(List* whereClause, char* alias);
extern void runDeleteStmt(DeleteStmt* node, List* relationList);

#endif /* PROCESS_H_ */
