/*
 * LIFO.c
 *
 *  Created on: Jan 31, 2023
 *      Author: dell
 */
#include <stdio.h>
#include "lifo.h"
#include "stdlib.h"

unsigned int buffer1[5];	//stored in Data Memory


int main()
{
	unsigned int i, temp =0;
	LIFO_Buf_t UART_lifo, I2C_lifo;
	//Static alloctaion
	LIFO_Init(buffer1, &UART_lifo, 5);
	//Dynamic allocation
	unsigned int* buffer2 = (unsigned int*) malloc(5 * sizeof(unsigned int));	//stored in heap
	LIFO_Init(buffer2, &I2C_lifo, 5);

	for(i=0; i<7; i++)
	{
		if(LIFO_Add_item(i,&UART_lifo) == LIFO_no_error )
			printf("item Added in element (%d) = %d\n", i,i);

		else if(LIFO_Add_item(i,&UART_lifo) == LIFO_full)
			printf("Stack is full!\n");

		else if(LIFO_Add_item(i,&UART_lifo) == LIFO_Null)
			printf("Stack Doesn't exist\n");
	}
	for(i=0; i<7; i++)
		{
			if(LIFO_Get_item(&temp,&UART_lifo) == LIFO_no_error)
				printf("item got from element (%d) = %d\n", i,temp);

			else if(LIFO_Get_item(&temp,&UART_lifo) == LIFO_empty)
				printf("Stack is empty\n");

			else if(LIFO_Get_item(&temp,&UART_lifo) == LIFO_Null)
				printf("Stack Doesn't exist\n");
		}

	return 0;

}

