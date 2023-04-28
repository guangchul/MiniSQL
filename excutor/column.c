/*
 * column.c
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */
#include "column.h"

DB_Columns columns[25] = {
		{1, 1, "id", 4, 12},
		{2, 1, "name", 64, 17},
		{3, 1, "fileName", 64, 17},
		{4, 1, "columnCount", 4, 12},
		{5, 1, "indexCount", 4, 12},
		{6, 2, "id", 4, 12},
		{7, 2, "tableId", 4, 12},
		{8, 2, "fieldName", 64, 17},
		{9, 2, "length", 4, 12},
		{10, 2, "flag", 4, 12},
		{11, 3, "id", 4, 12},
		{12, 3, "tableId", 4, 12},
		{13, 3, "indexName", 64, 17},
		{14, 3, "indexFileName", 64, 17},
		{15, 3, "columnsCount", 4, 12},
		{16, 3, "columnIds", 64, 17},
		{17, 0, "id", 4, 12},
		{18, 0, "perm", 4, 12},
		{19, 0, "name", 64, 17},
		{20, 4, "id", 4, 12},
		{21, 4, "tableId", 4,12},
		{22, 4, "indexName", 64, 17},
		{23, 4, "indexFileName", 64, 17},
		{24, 4, "columnsCount", 4, 12},
		{25, 4, "columnIds", 256, 17}
};

char* tables_into_columns[5] = {
		"id", "name", "fileName", "columnCount", "indexCount"
};

char* columns_into_columns[5] = {
		"id", "tableId", "fieldName", "length", "flag"
};

char* indices_into_columns[6] = {
		"id", "tableId", "indexName", "indexFileName", "columnsCount", "columnIds"
};

char* schema_into_columns[3] = {
		"id", "perm", "name"
};

