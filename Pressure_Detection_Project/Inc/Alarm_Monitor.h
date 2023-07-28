/*
 * Alarm_Monitor.h
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#ifndef INC_ALARM_MONITOR_H_
#define INC_ALARM_MONITOR_H_

#include "driver.h"
#include "State.h"

extern void (*Alarm_state)();

//Define states
enum
{
	AlarmOFF,
	AlarmON,
	Waiting
}Alarm_state_id;

STATE_define(alarmOFF);
STATE_define(alarmON);
STATE_define(waiting);


#endif /* INC_ALARM_MONITOR_H_ */
