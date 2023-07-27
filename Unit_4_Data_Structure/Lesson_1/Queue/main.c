/*
 * main.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */


#include "FIFO.h"

int main()
{
	element_type i , temp=0;

	FIFO_Buf_t FIFO_UART;
	if(FIFO_Init(&FIFO_UART, uart_buffer, 5) == FIFO_no_error)
		printf("FIFO Initialization ===> Done\n");

	for(i=0; i<7; i++)
	{
		if(FIFO_Enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\tFIFO Enqueue ===> Done\n"	);
		else
			printf("\tFIFO Enqueue ===> Failed\n");
	}
	FIFO_PRINT(&FIFO_UART);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\tFIFO Dequeue %x ===> Done\n",temp	);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\tFIFO Dequeue %x ===> Done\n",temp	);
	FIFO_PRINT(&FIFO_UART);
	if(FIFO_Enqueue(&FIFO_UART, 100) == FIFO_no_error)
				printf("\tFIFO Enqueue ===> Done\n"	);
	if(FIFO_Enqueue(&FIFO_UART, 64) == FIFO_no_error)
				printf("\tFIFO Enqueue ===> Done\n"	);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
			printf("\tFIFO Dequeue %x ===> Done\n",temp	);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
			printf("\tFIFO Dequeue %x ===> Done\n",temp	);

	FIFO_PRINT(&FIFO_UART);
	return 0;
}
