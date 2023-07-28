/*
 * State.h
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//Automatic state function generated
#define STATE_define(_statFUN_)	void ST_##_statFUN_()
#define STATE(_statFUN_)	ST_##_statFUN_

//Connection between states
void Set_Pressure_Val(int PressureVal);
void High_Pressure_Detected(int PressureVal);
void StartAlarm();
void StopAlarm();

#endif /* STATE_H_ */
