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
#include "../global/config.h"
#include "../server/server.h"
#include <stdlib.h>
#include <unistd.h>

int single = 0;

char* processSchema;
Connect* connect;
Buffer* buffer;

void initSingle() {
	single = 1;
}

void setConnect(Connect* _connect) {
	connect = _connect;
}

int readCommand(String* command) {
	int type;
	if(single == 1) {
		type = readSingleCommand(command);
	} else {
		type = readClientBuff(command, connect);
	}
	return type;
}

void writeResultHeader(Slot* slot, Node* node) {
	if(single == 1) {
		return;
	}
	Buffer* _buffer = malloc_local(sizeof(Buffer));
	_buffer->data = malloc_local(BUFFERS_SIZE);
	if(slot == (void*)0 || node == (void*)0) {
		buffer = _buffer;
		return;
	}
	if(node->type == T_SelectStmt) {
		SelectStmt* selectStmt = (SelectStmt*)node;
		writeSelectStmtHeader(slot, selectStmt, _buffer);
		buffer = _buffer;
	}
}

void writeResult(Slot* slot, Node* node) {
	if(single == 1) {
		writeSingle(slot, (SelectStmt*)node);
	} else {
		if(node->type == T_SelectStmt) {
			writeSelectResult(slot, (SelectStmt*)node, buffer);
		}
	}
}

void endWrite(Node* node) {
	switch(node->type) {
		case T_SelectStmt:
			beginMessage(buffer, 'C');
			appendValueWithLength(buffer, "SELECT 4");
			break;
		case T_CreateStmt:
			beginMessage(buffer, 'C');
			appendValueWithLength(buffer, "CREATE TABLE");
			break;
		case T_InsertStmt:
			beginMessage(buffer, 'C');
			appendValueWithLength(buffer, "INSERT 0 1");
			break;
		case T_UpdateStmt:
			beginMessage(buffer, 'C');
			appendValueWithLength(buffer, "UPDATE 1");
			break;
		case T_DeleteStmt:
			beginMessage(buffer, 'C');
			appendValueWithLength(buffer, "DELETE 1");
			break;
		default:
			break;
	}

	beginMessage(buffer, 'Z');
	appendByteWithLength(buffer, 73);
	rawWrite(connect->fd, buffer->data, buffer->len);
	free(buffer->data);
	free(buffer);
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
		if(relationList == (void*)0 || relationList->length == 0) {
			return;
		}
		portalRun(node, relationList, processSchema);
		if(single != 1){
			endWrite(node);
		}
		freeRelationList(relationList);
	}
}


void processMain(char* schema) {
	processSchema = schema;
	String* command = makeString();
	for(;;) {
		resetString(command);
		int readType = readCommand(command);
		if(readType == 'Q') {
			executeSql(command->data);
		}
	}
}
