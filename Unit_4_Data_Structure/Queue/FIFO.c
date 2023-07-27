/*
 * FIFO.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */

#include "FIFO.h"

FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf,uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type item)
{
	if(!fifo->head || !fifo->base || !fifo->tail )
		return FIFO_null;
	else if(FIFO_IS_FULL(fifo) == FIFO_full)
		return FIFO_full;
	else
	{
		*(fifo->head) = item;
		fifo->count++;
		if(fifo->head == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			fifo->head = fifo->base;
		else
			fifo->head++;

		return FIFO_no_error;
	}
}
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->head || !fifo->base || !fifo->tail )
		return FIFO_null;
	else if(fifo->count == 0)
		return FIFO_empty;
	else
	{
		*item = *(fifo->tail);
		fifo->count--;
		if(fifo->tail == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
		return FIFO_no_error;
	}

}

FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if(fifo->count == fifo->length)
		return FIFO_full;
	else
		return FIFO_no_error;
}
void FIFO_PRINT(FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count==0)
		printf("FIFO is Empty\n");
	temp = fifo->tail;
	printf("\n======FIFO_Print======\n");
	for(i=0; i<fifo->count; i++)
	{
		printf("\t %X \n",*temp);
		if(temp == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			temp = fifo->base;
		else
			temp++;
	}
	printf("==========\n");
}
