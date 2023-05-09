/*
 * init.h
 *
 *  Created on: Apr 9, 2023
 *      Author: choi
 */

#ifndef INIT_H_
#define INIT_H_

extern void changeDir();
extern void setDir(int argc, char **argv);
extern void initBuffer();
extern void initDB();
extern void initTempBufferBlocks();
extern void initUsingTempBufferBlocks();
extern int getPort(int argc, char **argv);

#endif /* INIT_H_ */
