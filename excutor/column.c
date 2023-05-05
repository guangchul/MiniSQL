/*
 * column.c
 *
 *  Created on: Apr 21, 2023
 *      Author: choi
 */
#include "column.h"

DB_Table table[4] = {
		{1, "tables", "tables", "tables.tb", 5, 2},
		{2, "columns", "columns", "columns.tb", 5, 0},
		{3, "indices", "indices", "indices.tb", 6, 0},
		{0, "schema", "schema", "schema", 3, 0}
};

DB_Columns columns[19] = {
		{1, "id", 4, 12, &table[0]},
		{2, "name", 64, 17, &table[0]},
		{3, "fileName", 64, 17, &table[0]},
		{4, "columnCount", 4, 12, &table[0]},
		{5, "indexCount", 4, 12, &table[0]},
		{6, "id", 4, 12, &table[1]},
		{7, "tableId", 4, 12, &table[1]},
		{8, "fieldName", 64, 17, &table[1]},
		{9, "length", 4, 12, &table[1]},
		{10, "flag", 4, 12, &table[1]},
		{11, "id", 4, 12, &table[2]},
		{12, "tableId", 4, 12, &table[2]},
		{13, "indexName", 64, 17, &table[2]},
		{14, "indexFileName", 64, 17, &table[2]},
		{15, "columnsCount", 4, 12, &table[2]},
		{16, "columnIds", 64, 17, &table[2]},
		{17, "id", 4, 12, &table[3]},
		{18, "perm", 4, 12, &table[3]},
		{19, "name", 64, 17, &table[3]}
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

