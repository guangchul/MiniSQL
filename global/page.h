/*
 * tuple.h
 *
 *  Created on: Apr 12, 2023
 *      Author: choi
 */

#ifndef PAGE_H_
#define PAGE_H_

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct PageXLogRecPtr{
	uint32 xlogid;
	uint32 xrecoff;
} PageXLogRecPtr;

typedef struct ItemIdData{
	unsigned lp_off:15,
			lp_flag:2,
			lp_len:15;
} ItemIdData;

typedef struct PageHeaderData{
	PageXLogRecPtr un_distributed_1; //offset 0
	uint16 un_distributed_2; //offset 8
	uint16 page_flags; //offset 10    when (page_flags & 0x02) == 0x02 then not enough free space for new tuple;
	uint16 start_of_free_space; //offset 12
	uint16 end_of_free_space; //offset 14
	uint16 un_distributed_4; //offset 16
	uint16 un_distributed_5; //offset 18
	uint32 un_distributed_6; //offset 20
	uint32 page_no; //offset 24
	ItemIdData tuple_desc[]; //offset 28
}PageHeaderData;

typedef struct uint96 {
	uint32 un_distributed_uint96_01;
	uint32 un_distributed_uint96_02;
	uint32 un_distributed_uint96_03;
}uint96;

typedef struct ItemDesc {
	uint16 page_hi;
	uint16 page_low;
	uint16 pos_id;
} ItemDesc;

typedef struct HeapTupleHeaderData{
	uint96 un_distributed_01; //offset 0
	ItemDesc item_desc; //offset 12
	uint16 attrs_count; //offset 18 attrs_count = attrs_count & 0x7ff; attr_count & 0x4000 == 0x4000 is updated; attr_count & 0x2000 == 0x2000 is deleted.
	uint16 flag_bits; //offset 20 when (flag_bits & 0x01) == 0x01 then nullable
	uint8 offset_of_data; //offset 22
	uint8 bits[]; //offset 23
} HeapTupleHeaderData;

#endif /* PAGE_H_ */
