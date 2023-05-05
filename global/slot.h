/*
 * slot.h
 *
 *  Created on: Apr 26, 2023
 *      Author: choi
 */

#ifndef SLOT_H_
#define SLOT_H_

#include "rel.h"
#include "page.h"

typedef struct Slot{
	DB_Columns_Set* columnsSet;
	unsigned int tuple_len;
	HeapTupleHeaderData* tuple;
	int end; // 1 is end, 0 is not
	int loop;
}Slot;

#endif /* SLOT_H_ */
