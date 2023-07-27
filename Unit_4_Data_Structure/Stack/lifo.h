/*
 * lifo.h
 *
 *  Created on: Jan 31, 2023
 *      Author: dell
 */

#ifndef LIFO_H_
#define LIFO_H_

//Type definitions
typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIs

LIFO_status LIFO_Add_item(unsigned int item, LIFO_Buf_t* lifo_buf);
LIFO_status LIFO_Get_item(unsigned int* item, LIFO_Buf_t* lifo_buf);
LIFO_status LIFO_Init(unsigned int* buf, LIFO_Buf_t* lifo_buf, unsigned int length);

#endif /* LIFO_H_ */
