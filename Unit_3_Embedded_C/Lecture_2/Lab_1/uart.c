#include "uart.h"
#define UART0DR 	*((volatile unsigned int* const)((unsigned int*)0x101f1000))

void Uart_Send_string(unsigned char *Ptr_tx_string)
{
	while(*Ptr_tx_string != '\0')
	{
		UART0DR = (unsigned int)(*Ptr_tx_string) ;
		Ptr_tx_string++ ;	
	}
}