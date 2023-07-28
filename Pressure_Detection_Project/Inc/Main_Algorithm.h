/*
 * Main_Algorithm.h
 *
 *  Created on: Jul 17, 2023
 *      Author: dell
 */

#ifndef INC_MAIN_ALGORITHM_H_
#define INC_MAIN_ALGORITHM_H_

#include "driver.h"
#include "State.h"


extern void (*Check_state) ();

//Define states
enum
{
		High_Pressure_Check
}Algorithm_state_id;

//Declare State function
STATE_define(High_Pressure_check);


#endif /* INC_MAIN_ALGORITHM_H_ */
