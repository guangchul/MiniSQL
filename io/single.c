/*
 * single.c
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */


#include "io.h"
#include "../util/list.h"
#include "../util/string.h"
#include "../process/process.h"
#include <stdio.h>
#include <stdlib.h>

int getChar() {
	return getc(stdin);
}

void readSingleCommand(String* command) {
	printf("sql> ");
	fflush(stdout);
	int c;
	while((c = getChar()) != -1) {
		if(c == '\n'){
			if(command->length > 1 && command->data[command->length - 1] == ';') {
				break;
			}
		}
		appendStringChar(command, (char)c);
	}
}

void writeSingle(Slot* slot, SelectStmt* node) {
	if(node->optTargetList->length == 1) {
		OptTarget* optTarget = (OptTarget*)listGet(node->optTargetList, 0);
		if(optTarget->isAll) {
			FieldNodes* fieldNodes = slot->fieldNodes;
			for(int i = 0; i < fieldNodes->length; i++) {
				Field field;
				field.tableAlias = slot->fieldNodes->fieldNode[i]->alias;
				field.field = slot->fieldNodes->fieldNode[i]->fieldName;
				char* val = getFieldVal(slot, field);
				printf("%10s", val);
			}
			printf("\n-------------------------------------------------------------\n");
			return;
		}
	}
	List* optTargetList = node->optTargetList;
	ListNode* listNode;
	foreach(listNode, optTargetList) {
		OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
		Field field;
		field.tableAlias = optTarget->tableAlias;
		field.field = optTarget->name;
		char* val = getFieldVal(slot, field);
		printf("%10s", val);
	}
	printf("\n-------------------------------------------------------------\n");
}
