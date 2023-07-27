/*
 * CA.h
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

extern void (*CA_state)();
//Define states
enum {
	CA_Waiting,
	CA_Driving
}CA_state_id;

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
