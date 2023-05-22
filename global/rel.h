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
	char* fieldName;
	unsigned int length;
	unsigned char flag;
	DB_Table* tableInfo;
} DB_Columns;

typedef struct DB_Columns_Set{
	int count;
	DB_Columns* columns[];
}DB_Columns_Set;

typedef struct DB_Index{
	unsigned int id;
	char* indexName;
	char* indexFileName;
	unsigned int columnsCount;
	char* columnIds;
	DB_Table* tableInfo;
}DB_Index;

typedef struct DB_Index_Set{
	int count;
	DB_Index* index[];
} DB_Index_Set;

typedef enum FieldType{
	F_CHAR = 1,
	F_SHORT,
	F_INT,
	F_VARCHAR,
	F_TEXT,
	F_LONG
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
	T_Insert,
	T_CreateIndex,
} ExtendType;

typedef struct IndexData{
	int pageNo;
	int start;
	int end;
	int max;
	int min;
	int indexCount;
}IndexData;

typedef struct IndexSet{
	int nextPageSeq;
	int nextItemPos;
	int pageCount;
	IndexData* data[];
}IndexSet;

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
	IndexSet* indexSet;
} SelectRelationExtend;

typedef struct InsertRelationExtend{
	ExtendType type;
	FieldNodes* fieldNodes;
	FieldValuesList* fieldValuesList;
}InsertRelationExtend;

typedef struct CreateIndexRelationExtend{
	ExtendType type;
	int* columnsIds;
	int* columnsNo;
	int columnsIdCount;
} CreateIndexRelationExtend;

typedef struct RelationExtend{
	ExtendType type;
} RelationExtend;

typedef struct Index{
	int flag; //flag == 0 is equals; flag == 1 not equal; flag == 2 more than; flag == 3 less than;
	FileNode* fileNode;
	DB_Columns_Set* columnsSet;
}Index;

typedef struct Relation{
	FileNode* fileNode;
	DB_Table* tableInfo;
	DB_Columns_Set* columnsSet;
	Index* index;
	RelationExtend* ext;
} Relation;

extern unsigned char calcFieldFlag(FieldType fieldType, unsigned int* length, char nullable);
extern FieldNodes* makeFieldNodes(DB_Columns** columns, int count);
extern void freeFieldNodes(FieldNodes* fieldNodes);
extern FieldValuesList* makeFieldValuesList(FieldNodes* fieldNodes, char** into_columns, char*** into_values, int columnCount, int valuesCount);
extern void freeFieldValuesList(FieldValuesList* fieldValuesList);

#endif /* REL_H_ */
