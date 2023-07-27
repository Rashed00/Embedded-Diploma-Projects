/*
 * main.c
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */

#include "CA.h"
#include "UltraSonic.h"
#include "DC.h"

void setup()
{
	//init all the drivers
	//init IRQs...
	//init HAL UltraSonic_Driver  DC_Driver
	//init Block
	UltraSonic_init();
	DC_init();
	//Set states pointers to each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);

}


int main()
{
	volatile int d;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		//delay
		for(d=0; d<1000; d++);
	}
	return 0;
}
