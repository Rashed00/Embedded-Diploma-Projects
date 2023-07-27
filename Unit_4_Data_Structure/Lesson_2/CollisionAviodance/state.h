/*
 * state.h
 *
 *  Created on: Jul 15, 2023
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
void US_Set_distance(int distance);
void DC_motor_set(int speed);

#endif /* STATE_H_ */
