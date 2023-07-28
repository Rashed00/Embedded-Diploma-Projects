/*
 * Alarm_Actuator_Driver.c
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#include "Alarm_Actuator_Driver.h"


void (*Alarm_actuator_state)();

void Alarm_init()
{
	//DPRINTF("Alarm init\n");
}

void StartAlarm()
{
	Set_Alarm_actuator(0);

}
void StopAlarm()
{
	Set_Alarm_actuator(1);

}

STATE_define(alarm_act_waiting)
{
	//State ID
//	Alarm_Actuator_state_id = Alarm_Act_Waiting;

	//State action

}
STATE_define(alarm_act_OFF)
{
	//State ID
//	Alarm_Actuator_state_id = Alarm_Act_OFF;

	//State action
//	Set_Alarm_actuator(0);
}
STATE_define(alarm_act_ON)
{
	//State ID
//	Alarm_Actuator_state_id = Alarm_Act_ON;

	//State action
//	Set_Alarm_actuator(1);

}


