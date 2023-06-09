/*
 * attrNode.c
 *
 *  Created on: Apr 12, 2023
 *      Author: choi
 */


#include "../global/rel.h"
#include <stdlib.h>
#include <string.h>
#include "../util/mem.h"

unsigned char calcFieldFlag(FieldType fieldType, unsigned int* length, char nullable){
	unsigned short type;
	unsigned short flexible = 0;
	switch(fieldType) {
		case F_CHAR:
			type = F_CHAR;
			*length = *length == 0 ? 1 : *length;
			break;
		case F_SHORT:
			type = F_SHORT;
			*length = 2;
			break;
		case F_INT:
			type = F_INT;
			*length = 4;
			break;
		case F_LONG:
			type = F_LONG;
			*length = 8;
			break;
		case F_VARCHAR:
			type = F_VARCHAR;
			flexible = 1;
			*length = *length == 0 ? 1 : *length;
			break;
		case F_TEXT:
			type = F_TEXT;
			flexible = 1;

	}
	return type << 2 | nullable << 1 | flexible;
}

FieldNodes* makeFieldNodes(DB_Columns** columns, int count) {
	FieldNodes* fieldNodes = malloc_local(sizeof(FieldNodes) + (sizeof(FieldNode) * count));
	fieldNodes->length = count;
	for(int i = 0; i < count; i++) {
		DB_Columns* column = columns[i];
		FieldNode* node = malloc_local(sizeof(FieldNode));
		node->id = column->id;
		node->fieldName = column->fieldName;
		node->length = column->length;
		node->flag = column->flag;
		fieldNodes->fieldNode[i] = node;
	}
	return fieldNodes;
}

void freeFieldNodes(FieldNodes* fieldNodes) {
	for(int i = 0; i < fieldNodes->length; i++) {
		free(fieldNodes->fieldNode[i]);
	}
	free(fieldNodes);
}

int getColumnsNo(char** into_columns, int columnCount, char* fieldName) {
	int i = 0;
	for(; i < columnCount; i++) {
		if(strcmp(into_columns[i], fieldName) == 0) {
			return i;
		}
	}
	return -1;
}

FieldValuesList* makeFieldValuesList(FieldNodes* fieldNodes, char** into_columns, char*** into_values, int columnCount, int valuesCount) {
	FieldValuesList* fieldValuesList = malloc_local(sizeof(FieldValuesList) + (sizeof(FieldValues*) * valuesCount));
	fieldValuesList->length = valuesCount;
	for(int seq = 0; seq < valuesCount; seq++) {
		char** into_value = (char**)(((char*)into_values) + (sizeof(char*) * columnCount * seq));
		int i = 0;
		FieldValues* fieldValues = malloc_local(sizeof(FieldValues) + (sizeof(FieldValue*) * fieldNodes->length));
		fieldValues->length = fieldNodes->length;
		for(;;) {
			if(i == fieldNodes->length) {
				break;
			}
			FieldNode* fieldNode = fieldNodes->fieldNode[i];
			int columnNo = getColumnsNo(into_columns, columnCount, fieldNode->fieldName);
			FieldValue* fieldValue = malloc_local(sizeof(FieldValue));
			if(columnNo == -1) {//when columnNo == -1,then throws a exception.
				fieldValues->value[i] = fieldValue;
				i++;
				continue;
			}
			char* value = into_value[columnNo];
			fieldValue->fieldName = fieldNode->fieldName;
			FieldType fieldType = fieldNode->flag >> 2;
			switch(fieldType) {
				case F_SHORT:
				case F_INT:
				case F_LONG:
					fieldValue->value.long_value = atoi(value);
					break;
				default:
				{
					char* ptr = (char*)malloc_local(strlen(value) + 1);
					memcpy(ptr, value, strlen(value));
					fieldValue->value.ptr_value = ptr;
					break;
				}
			}
			fieldValues->value[i] = fieldValue;
			i++;
		}
		fieldValuesList->fieldValues[seq] = fieldValues;
	}
	return fieldValuesList;
}

void freeFieldValuesList(FieldValuesList* fieldValuesList) {
	for(int i = 0; i < fieldValuesList->length; i++) {
		for(int j = 0; j < fieldValuesList->fieldValues[i]->length; j++) {
			free(fieldValuesList->fieldValues[i]->value[j]);
		}
		free(fieldValuesList->fieldValues[i]);
	}
}
