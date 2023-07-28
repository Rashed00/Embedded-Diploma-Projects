/*
 * Alarm_Monitor.c
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#include "Alarm_Monitor.h"

//Variables
int AlarmTimer = 0;
int AlarmPeriod = 60;

//State pointer to function
void (*Alarm_state)();


void High_Pressure_Detected(int PressureVal)
{
	//DPRINTF("MainAlgorithm----------High Pressure Detected (pressure = %d)--------------AlarmMonitor\n",PressureVal);
	Alarm_state = STATE(alarmON);
	Alarm_state();
}

STATE_define(alarmOFF)
{
	//State ID
	// Alarm_state_id = AlarmOFF;

	//State action
	StopAlarm();
	//DPRINTF("AlarmMonitor_AlarmOFF state\n");
}
STATE_define(alarmON)
{
	//State ID
	// Alarm_state_id = AlarmON;

	//State action
	StartAlarm();
	//DPRINTF("AlarmMonitor_AlarmON state\n");
	Alarm_state = STATE(waiting);
}
STATE_define(waiting)
{
	//State ID
	// Alarm_state_id = Waiting;

	//State action
	//DPRINTF("AlarmMonitor_AlarmWaiting state\n");
	Delay(1000000);
	Alarm_state = STATE(alarmOFF);
	Alarm_state();
}

