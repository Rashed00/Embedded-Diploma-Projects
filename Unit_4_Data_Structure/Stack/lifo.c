/*
 * lifo.c
 *
 *  Created on: Jan 31, 2023
 *      Author: dell
 */
#include "lifo.h"
#include "stdlib.h"
#include "stdio.h"

LIFO_status LIFO_Add_item(unsigned int item, LIFO_Buf_t* lifo_buf)
{
	//check if lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	//check if lifo is full
	else if(lifo_buf->count >= lifo_buf->length)
		return LIFO_full;

	//Add value
	else
	{
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error;
	}



}
LIFO_status LIFO_Get_item(unsigned int* item, LIFO_Buf_t* lifo_buf)
{
	//check if lifo is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	//check lifo is empty
	else if(lifo_buf->count == 0)
		return LIFO_empty;

	//Get item
	else
	{
		lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
	}


}
LIFO_status LIFO_Init(unsigned int* buf, LIFO_Buf_t* lifo_buf, unsigned int length)
{
	if (buf == NULL)
		return LIFO_Null;
	else
	{
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
	}

}
