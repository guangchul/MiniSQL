/*
 * analyzeSelectStmt.c
 *
 *  Created on: Apr 25, 2023
 *      Author: choi
 */


#include "process.h"
#include "../util/list.h"
#include "../global/rel.h"
#include "../file/file.h"
#include <stdlib.h>
#include <string.h>
#include "../util/mem.h"
#include "../error/error.h"

DB_Columns* getColumnsFromSet(DB_Columns_Set* columnsSet, char* fieldName) {
	for(int i = 0; i < columnsSet->count; i++) {
		DB_Columns* column = columnsSet->columns[i];
		if(strcmp(column->fieldName, fieldName) == 0) {
			return column;
		}
	}
	return (void*)0;
}

FieldNodes* remakeFieldNodes(List* optTargetList, DB_Columns_Set* columnsSet, char* alias, char* name) {
	List* tempList = makeList();
	if(alias != (void*)0) {
		ListNode* listNode;
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(optTarget->tableAlias == (void*)0) {
				//todo error;
			}
			if(strcmp(optTarget->tableAlias, alias) == 0) {
				if(optTarget->isAll == 1) {
					FieldNodes* fieldNodes = malloc_local(sizeof(FieldNodes) + (sizeof(FieldNode*) * columnsSet->count));
					fieldNodes->length = columnsSet->count;
					for(int i = 0; i < columnsSet->count; i++) {
						DB_Columns* column = columnsSet->columns[i];
						FieldNode* fieldNode = malloc_local(sizeof(FieldNode));
						fieldNode->id = column->id;
						fieldNode->fieldName = column->fieldName;
						fieldNode->length = column->length;
						fieldNode->flag = column->flag;
						fieldNodes->fieldNode[i] = fieldNode;
					}
					return fieldNodes;
				}
				DB_Columns* column = getColumnsFromSet(columnsSet, optTarget->name);
				if(column == (void*)0) {
					//todo error;
				}
				listAppend(tempList, column);
			}
		}
	} else {
		ListNode* listNode;
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(optTarget->tableAlias == (void*)0) {
				optTarget->tableAlias = name;
			}
			if(optTarget->isAll == 1) {
				FieldNodes* fieldNodes = malloc_local(sizeof(FieldNodes) + (sizeof(FieldNode*) * columnsSet->count));
				fieldNodes->length = columnsSet->count;
				for(int i = 0; i < columnsSet->count; i++) {
					DB_Columns* column = columnsSet->columns[i];
					FieldNode* fieldNode = malloc_local(sizeof(FieldNode));
					fieldNode->id = column->id;
					fieldNode->fieldName = column->fieldName;
					fieldNode->length = column->length;
					fieldNode->flag = column->flag;
					fieldNode->alias = name;
					fieldNodes->fieldNode[i] = fieldNode;
				}
				return fieldNodes;
			}
			DB_Columns* column = getColumnsFromSet(columnsSet, optTarget->name);
			if(column == (void*)0) {
				//todo error;
			}
			listAppend(tempList, column);
		}
	}
	ListNode* listNode;
	FieldNodes* fieldNodes = malloc_local(sizeof(FieldNodes) + (sizeof(FieldNode*) * tempList->length));
	fieldNodes->length = tempList->length;
	int idx = 0;
	foreach(listNode, tempList) {
		DB_Columns* column = (DB_Columns*)listNode->value.ptr_val;
		FieldNode* fieldNode = malloc_local(sizeof(FieldNode));
		fieldNode->id = column->id;
		fieldNode->fieldName = column->fieldName;
		fieldNode->length = column->length;
		fieldNode->flag = column->flag;
		fieldNodes->fieldNode[idx] = fieldNode;
		idx++;
	}
	freeList(tempList);
	return fieldNodes;
}

int foundTableAlias(OptTarget* optTarget, List* fromClauseList) {
	ListNode* listNode;
	foreach(listNode, fromClauseList) {
		FromClause* fromClause = (FromClause*)listNode->value.ptr_val;
		if(strcmp(fromClause->alias, optTarget->tableAlias) == 0) {
			return 1;
		}
	}
	return -1;
}

int foundColumn(char* name, DB_Columns_Set* columnsSet) {
	for(int i = 0; i < columnsSet->count; i++) {
		if(strcmp(name, columnsSet->columns[i]->fieldName) == 0) {
			return 1;
		}
	}
	return -1;
}

char* checkWhereClause(List* whereClauseList, DB_Table* tableInfo, DB_Columns_Set* columnsSet) {
	if(whereClauseList == (void*)0 || whereClauseList->length == 0) {
		return (void*)0;
	}
	ListNode* listNode;
	foreach(listNode, whereClauseList) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			return checkWhereClause(whereCondition->list, tableInfo, columnsSet);
		} else {
			if(whereCondition->whereSingle->left.isVal == 0 && strcmp(whereCondition->whereSingle->left.tableAlias, tableInfo->alias) == 0) {
				char* columnName = whereCondition->whereSingle->left.field;
				if(foundColumn(columnName, columnsSet) == -1) {
					return columnName;
				}
			}
			if(whereCondition->whereSingle->right.isVal == 0 && strcmp(whereCondition->whereSingle->right.tableAlias, tableInfo->alias) == 0){
				char* columnName = whereCondition->whereSingle->right.field;
				if(foundColumn(columnName, columnsSet) == -1) {
					return columnName;
				}
			}
		}
	}
	return (void*)0;
}

int* parseIndexColumnIds(char* columnIds, int count) {
	char* buffer = malloc_local(11);
	int idx = 0;
	int j = 0;
	int* ids = malloc_local(sizeof(int) * count);
	for(int i = 0; i < strlen(columnIds); i++) {
		char c = *(columnIds + i);
		if(c == ' ') {
			ids[idx] = atoi(buffer);
			idx++;
			memset(buffer, 0, 11);
			j = 0;
			continue;
		}
		*(buffer + j) = c;
		j++;
	}
	ids[idx] = atoi(buffer);
	free(buffer);
	return ids;
}

DB_Columns* getDBColumnsFromColumnsSet(DB_Columns_Set* columnsSet, int id) {
	for(int i = 0; i < columnsSet->count; i++) {
		DB_Columns* column = columnsSet->columns[i];
		if(column->id == id) {
			return column;
		}
	}
	return (void*)0;
}

char* getColumnNameFromColumnsSet(DB_Columns_Set* columnsSet, int id) {
	DB_Columns* dbColumns = getDBColumnsFromColumnsSet(columnsSet, id);
	if(dbColumns != (void*)0) {
		return dbColumns->fieldName;
	}
	return (void*)0;
}

int indexStrategyMatch(List* whereClauseList, DB_Index* index, DB_Columns_Set* columnsSet, char* alias, int* flag) {
	ListNode* listNode;
	int matchCount = 0;
	int* ids = parseIndexColumnIds(index->columnIds, index->columnsCount);
	for(int i = 0; i < index->columnsCount; i++) {
		int id = ids[i];
		char* columnName = getColumnNameFromColumnsSet(columnsSet, id);
		foreach(listNode, whereClauseList) {
			WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
			if(whereCondition->isList == 0 && whereCondition->condition == 1) {
				if(whereCondition->whereSingle->right.isVal == 1){
					if(alias == (void*)0){
						if(strcmp(whereCondition->whereSingle->left.field, columnName) == 0){
							if(*(whereCondition->whereSingle->op) == '=') {
								*flag = 0;
							}
							matchCount++;
							break;
						}
					} else {
						if(strcmp(whereCondition->whereSingle->left.tableAlias, alias) == 0 && strcmp(whereCondition->whereSingle->left.field, columnName) == 0){
							if(*(whereCondition->whereSingle->op) == '=') {
								*flag = 0;
							}
							matchCount++;
							break;
						}
					}
				}
			}
		}
	}
	free(ids);
	return matchCount == index->columnsCount ? 1 : 0;
}

Index* indexStrategy(DB_Table* tableInfo, List* whereClauseList, char* schema, DB_Columns_Set* columnsSet, char* alias) {
	if(whereClauseList == (void*)0 || whereClauseList->length == 0) {
		return (void*)0;
	}
	DB_Index_Set* indexSet = getIndexSet(tableInfo, schema);
	for(int i = 0; i < indexSet->count; i++) {
		DB_Index* dbindex = indexSet->index[i];
		int flag = 0;
		if(indexStrategyMatch(whereClauseList, dbindex, columnsSet, alias, &flag) == 1) {
			Index* index = malloc_local(sizeof(Index));
			FileNode* fileNode = malloc_local(sizeof(FileNode));
			fileNode->schema = schema;
			fileNode->file = dbindex->indexFileName;
			makeFileNode(fileNode);
			index->fileNode = fileNode;
			DB_Columns_Set* _columnsSet = malloc_local(sizeof(DB_Columns_Set) + (sizeof(DB_Columns*) * dbindex->columnsCount));
			_columnsSet->count = dbindex->columnsCount;
			int* ids = parseIndexColumnIds(dbindex->columnIds, dbindex->columnsCount);
			for(int j = 0; j < dbindex->columnsCount; j++) {
				int id = ids[j];
				DB_Columns* _dbColumns = getDBColumnsFromColumnsSet(columnsSet, id);
				_columnsSet->columns[j] = _dbColumns;
			}
			index->columnsSet = _columnsSet;
			index->flag = flag;
			return index;
		}
	}
	return (void*)0;
}

char* validateWhereClause(List* whereClauseList, List* fromClauseList) {
	ListNode* listNode;
	foreach(listNode, whereClauseList) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			return validateWhereClause(whereCondition->list, fromClauseList);
		} else {

			if(whereCondition->whereSingle->left.isVal == 0){
				int found = 0;
				ListNode* subListNode;
				foreach(subListNode, fromClauseList) {
					FromClause* fromClause = (FromClause*)subListNode->value.ptr_val;
					if(strcmp(fromClause->alias, whereCondition->whereSingle->left.tableAlias) == 0) {
						found = 1;
						break;
					}
				}
				if(found == 0) {
					return whereCondition->whereSingle->left.tableAlias;
				}
			}
			if(whereCondition->whereSingle->right.isVal == 0) {
				int found = 0;
				ListNode* subListNode;
				foreach(subListNode, fromClauseList) {
					FromClause* fromClause = (FromClause*)subListNode->value.ptr_val;
					if(strcmp(fromClause->alias, whereCondition->whereSingle->right.tableAlias) == 0) {
						found = 1;
						break;
					}
				}
				if(found == 0) {
					return whereCondition->whereSingle->right.tableAlias;
				}
			}

		}
	}
	return (void*)0;
}

char* validateSingleTableWhereClause(List* whereClauseList, char* tableName){
	ListNode* listNode;
	foreach(listNode, whereClauseList) {
		WhereCondition* whereCondition = (WhereCondition*)listNode->value.ptr_val;
		if(whereCondition->isList == 1) {
			return validateSingleTableWhereClause(whereCondition->list, tableName);
		}else {
			if(whereCondition->whereSingle->left.isVal == 0) {
				if(whereCondition->whereSingle->left.tableAlias != (void*)0) {
					return whereCondition->whereSingle->left.tableAlias;
				} else {
					whereCondition->whereSingle->left.tableAlias = tableName;
				}
			}
			if(whereCondition->whereSingle->right.isVal == 0) {
				if(whereCondition->whereSingle->right.tableAlias != (void*)0) {
					return whereCondition->whereSingle->right.tableAlias;
				} else {
					whereCondition->whereSingle->right.tableAlias = tableName;
				}
			}
		}
	}
	return (void*)0;
}

List* analyzeSelectStmt(SelectStmt* node, char* schema) {
	List* relationList = makeList();
	List* fromClauseList = node->fromClause;
	List* optTargetList = node->optTargetList;
	List* whereClauseList = node->whereClause;
	ListNode* listNode;
	if(fromClauseList->length > 1) {
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(optTarget->isAll != 1) {
				if(optTarget->tableAlias == (void*)0) {
					printError("Undefined table alias at column \"%s\"", optTarget->name);
					return (void*)0;
				}
				if(foundTableAlias(optTarget, fromClauseList) == -1) {
					printError("Unknown table alias \"%s\".", optTarget->tableAlias);
					return (void*)0;
				}
			}
		}
		if(whereClauseList != 0 && whereClauseList->length > 0){
			char* tableAlias = validateWhereClause(whereClauseList, fromClauseList);
			if(tableAlias != (void*)0) {
				printError("Unknown table alias \"%s\" in where clause.", tableAlias);
				return (void*)0;
			}
		}
	}
	if(fromClauseList->length == 1 && whereClauseList != 0 && whereClauseList->length > 0) {
		FromClause* fromClause = (FromClause*)listGet(fromClauseList, 0);
		if(fromClause->alias == (void*)0) {
			char* tableAlias = validateSingleTableWhereClause(whereClauseList, fromClause->name);
			if(tableAlias != 0){
				printError("Unknown table alias \"%s\" in where clause.", tableAlias);
				return (void*)0;
			}
		}else {
			char* tableAlias = validateWhereClause(whereClauseList, fromClauseList);
			if(tableAlias != (void*)0) {
				printError("Unknown table alias \"%s\" in where clause.", tableAlias);
				return (void*)0;
			}
		}
	}
	if(fromClauseList->length == 1) {
		FromClause* fromClause = listGet(fromClauseList, 0);
		listNode = (void*)0;
		foreach(listNode, optTargetList) {
			OptTarget* optTarget = (OptTarget*)listNode->value.ptr_val;
			if(fromClause->alias == (void*)0){
				if(optTarget->tableAlias != (void*)0) {
					printError("Unknown table alias \"%s\".", optTarget->tableAlias);
					return (void*)0;
				}
			} else {
				if(optTarget->tableAlias == (void*)0 && optTarget->isAll != 1){
					printError("Undefined table alias in column \"%s\".", optTarget->name);
					return (void*)0;
				} else if(optTarget->isAll != 1 && strcmp(optTarget->tableAlias, fromClause->alias) != 0) {
					printError("Unknown table alias \"%s\".", optTarget->tableAlias);
					return (void*)0;
				}
			}
		}
	}
	listNode = (void*)0;
	foreach(listNode, fromClauseList) {
		FromClause* fromClause = (FromClause*)listNode->value.ptr_val;
		DB_Table* tableInfo = getTableInfo(schema, fromClause->name, fromClause->alias);
		if(tableInfo == (void*)0) {
			printError("table name \"%s\" not exists!", fromClause->name);
			return (void*)0;
		}
		DB_Columns_Set* columnsSet = getColumnsSet(schema, tableInfo);
		ListNode* subListNode;
		foreach(subListNode, optTargetList){
			OptTarget* optTarget = (OptTarget*)subListNode->value.ptr_val;
			if(optTarget->isAll == 1){
				continue;
			}
			if(foundColumn(optTarget->name, columnsSet) == -1) {
				printError("could not found column \"%s\" in table \"%s\"", optTarget->name, tableInfo->name);
				return (void*)0;
			}
		}

		char* columnName = checkWhereClause(whereClauseList, tableInfo, columnsSet);
		if(columnName != (void*)0) {
			printError("column name \"%s\" not exists in table \"%s\"", columnName, tableInfo->name);
			return (void*)0;
		}

		Index* index = indexStrategy(tableInfo, node->whereClause, schema, columnsSet, fromClause->alias);

		//checkWhereClause(node->whereClause, fromClause->alias, fromClause->name);

		FileNode* fileNode = (FileNode*)malloc_local(sizeof(FileNode));
		fileNode->schema = schema;
		fileNode->file = tableInfo->fileName;
		makeFileNode(fileNode);

		Relation* relation = malloc_local(sizeof(Relation));
		relation->fileNode = fileNode;
		relation->tableInfo = tableInfo;
		relation->columnsSet = columnsSet;
		if(index != (void*)0) {
			relation->index = index;
		}

		listAppend(relationList, relation);
	}
	return relationList;
}
