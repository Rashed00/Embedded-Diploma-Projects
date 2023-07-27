/*
 * US.h
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */

#ifndef US_H_
#define US_H_

#include "state.h"


//Define states
enum {
	US_Busy
}US_state_id;

//declare states functions US
STATE_define(US_busy);

void UltraSonic_init();

//State pointer to function
extern void (*US_state)();
#endif /* US_H_ */
