/*
 * Alarm_Actuator_Driver.h
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#ifndef INC_ALARM_ACTUATOR_DRIVER_H_
#define INC_ALARM_ACTUATOR_DRIVER_H_

#include "driver.h"
#include "State.h"

//state pointer to function
extern void (*Alarm_actuator_state)();


//Define states
enum
{
	Alarm_Act_Waiting,
	Alarm_Act_OFF,
	Alarm_Act_ON
}Alarm_Actuator_state_id;

STATE_define(alarm_act_waiting);
STATE_define(alarm_act_OFF);
STATE_define(alarm_act_ON);

void Alarm_init();

#endif /* INC_ALARM_ACTUATOR_DRIVER_H_ */
