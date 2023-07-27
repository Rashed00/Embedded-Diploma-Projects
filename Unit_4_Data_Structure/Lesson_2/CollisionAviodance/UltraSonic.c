/*
 * US.c
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */
#include "UltraSonic.h"
//Variables
int US_distance = 0;


//Prototype
int US_Get_distance_random(int l, int r, int count);

void UltraSonic_init()
{
	//init UltraSonic driver
	printf("UltraSonic_init\n");
}
//State pointer to function
void (*US_state)();

STATE_define(US_busy)
{
	//State name
	US_state_id = US_Busy;

	//State Action
	US_distance = US_Get_distance_random(45,55,1);
	printf("US_Busy state: distance = %d\n",US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}


int US_Get_distance_random(int l, int r, int count)
{
	//This will generate random number between min and max
	int i;
	for(i=0; i<count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l ;
		return rand_num;
	}
}



