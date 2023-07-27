/*
 * FIFO.h
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
//USER CONFIGURATION

#define element_type uint8_t
//create buffer
#define width1 5
element_type uart_buffer[width1];

typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_full,
	FIFO_empty,
	FIFO_null,
	FIFO_no_error,
}FIFO_Buf_Status;

//APIs

FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf,uint32_t length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_PRINT(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
