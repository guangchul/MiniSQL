/*
 * rel.h
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */

#ifndef REL_H_
#define REL_H_

#include <stdio.h>
#include "../util/list.h"
#include "../global/machine.h"

typedef struct FileNode{
	char* schema;
	char* file;
	int fd;
} FileNode;

typedef struct DB_Schema{
	unsigned int id;
	unsigned int perm; // wxwxwx
	char* name;
}DB_Schema;

typedef struct DB_Table{
	unsigned int id;
	char* name;
	char* alias;
	char* fileName;
	unsigned int columnCount;
	unsigned int indexCount;
}DB_Table;

typedef struct DB_Columns{
	unsigned int id;
	unsigned int tableId;
	char* fieldName;
	unsigned int length;
	unsigned char flag;
} DB_Columns;

typedef struct DB_Columns_Set{
	int count;
	DB_Columns* columns[];
}DB_Columns_Set;

typedef struct DB_Index{
	unsigned int id;
	unsigned int tableId;
	char* indexName;
	char* indexFileName;
	unsigned int columnsCount;
	char* columnIds;
}DB_Index;

typedef enum FieldType{
	CHAR = 1,
	SHORT,
	INT,
	VARCHAR,
	TEXT,
	LONG
} FieldType;

typedef struct FieldNode{
	unsigned int id;
	char* fieldName;
	char* alias;
	unsigned int length;
	unsigned char flag;  //(flag & 0x1) == 1 is flexible; (flag & 0x2) == 0x2 is nullable; (flag >> 2) is field type.
}FieldNode;

typedef struct FieldNodes{
	int length;
	FieldNode* fieldNode[];
} FieldNodes;

typedef struct FieldValue{
	char* fieldName;
	union{
		char* ptr_value;
		long long_value;
	}value;
} FieldValue;

typedef struct FieldValues{
	int length;
	FieldValue* value[];
} FieldValues;

typedef struct FieldValuesList{
	int length;
	FieldValues* fieldValues[];
}FieldValuesList;

typedef enum ExtendType{
	T_Select,
} ExtendType;

typedef struct SelectRelationExtend{
	ExtendType type;
	List* tempBlockList;
	int alreayMadeTempBlock; // 0 is not, 1 is yes.
	int nextBlockNo; // in BufferBlocks
	int nextBlockSeq; //in list
	int nextItemPos;
	int nextTempBlockNo; // in TempBufferBlocks
	int nextTempBlockSeq; // in tempBlockList
	int nextTempItemPos;
	int lastTempBlockNo;
	int isOuter; // 1 is outer; 0 is inner;
	int isLast; // 1 is last; 0 is not;
	int jump; // 1 is jump; 0 is not;
} SelectRelationExtend;

typedef struct RelationExtend{
	ExtendType type;
} RelationExtend;

typedef struct Relation{
	FileNode* fileNode;
	int indexCount;
	List* indexList;
	FieldNodes* fieldNodes;
	FieldValuesList* fieldValuesList;
	DB_Table* tableInfo;
	DB_Columns_Set* columnsSet;
	RelationExtend* ext;
} Relation;

extern unsigned char calcFieldFlag(FieldType fieldType, unsigned int* length, char nullable);
extern FieldNodes* makeFieldNodes(DB_Columns** columns, int count);
extern void freeFieldNodes(FieldNodes* fieldNodes);
extern FieldValuesList* makeFieldValuesList(FieldNodes* fieldNodes, char** into_columns, char*** into_values, int columnCount, int valuesCount);
extern void freeFieldValuesList(FieldValuesList* fieldValuesList);

#endif /* REL_H_ */
