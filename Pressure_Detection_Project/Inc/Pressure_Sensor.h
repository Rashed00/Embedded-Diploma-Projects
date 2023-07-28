/*
 * Pressure_Sensor.h
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#ifndef INC_PRESSURE_SENSOR_H_
#define INC_PRESSURE_SENSOR_H_

#include "State.h"
#include "driver.h"

//State pointer to function
extern void (*Psensor_state)();

//Define states
enum
{
	PSensor_Reading,
	PSensor_Waiting
}PSensor_state_id;

//Declare State functions
STATE_define(PSensor_reading);
STATE_define(PSensor_waiting);


void PSensor_init();

#endif /* INC_PRESSURE_SENSOR_H_ */
