#include "stdio.h"

unsigned char string [100] = "learn-in-depth: Rashed" ;

void main(void)
{
	Uart_Send_string(string);

}