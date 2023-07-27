/*
 * CA.c
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */
#include "CA.h"
//Variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


//State pointer to function
void (*CA_state)();


void US_Set_distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) :(CA_state = STATE(CA_driving));
	printf("UltraSonic--------distance = %d------------CollisionAvoidance\n",CA_distance);
}

STATE_define(CA_waiting)
{
	//State name
	CA_state_id = CA_Waiting;
	printf("CA_waiting state: distance = %d, speed= %d\n",CA_distance,CA_speed);
	//State Action
	CA_speed = 0;
	//DC_motor(CA_speed)
	DC_motor_set(CA_speed);
}

STATE_define(CA_driving)
{
	//State name
	CA_state_id = CA_Driving;
	printf("CA_Driving state: distance = %d, speed= %d\n",CA_distance,CA_speed);
	//State Action
	CA_speed = 30;
	//DC_motor(CA_speed)
	DC_motor_set(CA_speed);
}




