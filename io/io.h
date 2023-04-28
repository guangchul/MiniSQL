/*
 * io.h
 *
 *  Created on: Apr 19, 2023
 *      Author: choi
 */

#ifndef IO_H_
#define IO_H_

#include "../util/string.h"
#include "../global/slot.h"
#include "../node/parseNodes.h"

extern void readSingleCommand(String* command);
extern void writeSingle(Slot* slot, SelectStmt* node);

#endif /* IO_H_ */
