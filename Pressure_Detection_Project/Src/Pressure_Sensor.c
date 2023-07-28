/*
 * Pressure_Sensor.c
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */
#include "Pressure_Sensor.h"

//Variables
int PressureVal = 0;
int Pull_Timer = 100;

//State pointer to function
void (*Psensor_state)();


//int Get_pressure_random(int l, int r, int count)
//{
//	//This will generate random number between l and r
//	int i;
//	for(i=0; i<count; i++)
//	{
//		int rand_num = (rand() % (r - l + 1)) + l ;
//		return rand_num;
//	}
//}

void PSensor_init()
{
	//GPIO init
	GPIO_INITIALIZATION();
	//DPRINTF("Pressure Sensor init\n");
}

STATE_define(PSensor_reading)
{
	//State ID
//	PSensor_state_id = PSensor_Reading;

	//State action
	PressureVal = getPressureVal();
	//DPRINTF("PressureSensor_Reading state: Pressure = %d\n",PressureVal);
	Set_Pressure_Val(PressureVal);
//	Psensor_state = STATE(PSensor_waiting);
//	Psensor_state();
}
STATE_define(PSensor_waiting)
{
	//State ID
//	PSensor_state_id = PSensor_Waiting;

	//State action
	//DPRINTF("PressureSensor_Waiting state: Pressure = %d\n",PressureVal);
//	Psensor_state = STATE(PSensor_reading);
}


