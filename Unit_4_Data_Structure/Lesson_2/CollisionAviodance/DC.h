/*
 * DC.h
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"


//Define states
enum {
	DC_Idle,
	DC_Busy
}DC_state_id;

//declare states functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//State pointer to function
extern void (*DC_state)();

#endif /* CA_H_ */
