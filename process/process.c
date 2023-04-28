/*
 * process.c
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */
#include "process.h"
#include "../util/string.h"
#include "../io/io.h"
#include "../parse/parse.h"
#include "../util/list.h"
#include "../node/parseNodes.h"
#include "../global/rel.h"
#include <stdlib.h>

static int single = 0;

char* processSchema;

void initSingle() {
	single = 1;
}

int readCommand(String* command) {
	if(single == 1) {
		readSingleCommand(command);
	} else {

	}
	return 1;
}

void writeResult(Slot* slot, SelectStmt* node) {
	if(single == 1) {
		writeSingle(slot, node);
	} else {

	}
}

//todo
void freeRelationList(List* relationList) {

}

void executeSql(char* queryString) {
	List* list = parseQuery(queryString);
	if(list == (void*)0) {
		return;
	}
	ListNode* listNode;
	foreach(listNode, list) {
		Node* node = (Node*)(listNode->value.ptr_val);
		List* relationList = analyze(node, processSchema);
		portalRun(node, relationList, processSchema);
		freeRelationList(relationList);
	}
}


void processMain(char* schema) {
	processSchema = schema;
	String* command = makeString();
	for(;;) {
		resetString(command);
		int readType = readCommand(command);
		if(readType == 1) {
			executeSql(command->data);
		}
	}
}
