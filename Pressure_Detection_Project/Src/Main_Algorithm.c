/*
 * Main_Algorithm.c
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#include "Main_Algorithm.h"

//Variables
int Pressure_Threshold = 20;
int pVal = 0;

//State Pointer to function
void (*Check_state) ();

void Set_Pressure_Val(int PressureVal)
{
	pVal = PressureVal;
	//DPRINTF("PressureSensor--------Pressure = %d------------MainAlgorithm\n",pVal);

}


STATE_define(High_Pressure_check)
{
	//State ID
	Algorithm_state_id = High_Pressure_Check;

	//State action
	//DPRINTF("MainAlogrithm_Check state: Pressure = %d\n",pVal);
	if(pVal <= Pressure_Threshold)
	{
		//Do nothing
		//DPRINTF("Pressure is low!\n");
	}
	else
	{
		High_Pressure_Detected(pVal);
	}
}
