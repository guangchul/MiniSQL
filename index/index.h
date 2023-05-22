/*
 * index.h
 *
 *  Created on: May 14, 2023
 *      Author: choi
 */

#ifndef INDEX_H_
#define INDEX_H_

#include "../global/page.h"
#include "../global/rel.h"

extern void btreeInsert(HeapTupleHeaderData* tuple, int tupleLength, Relation* tableRelation, Relation* indexRelation);
extern IndexSet* collectIndexSet(Index* index, List* whereClause);
extern Relation* getIndexRelation(DB_Index* dbIndex, Relation* tableRelation);

#endif /* INDEX_H_ */
