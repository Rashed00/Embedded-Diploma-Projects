/*
 * DC.c
 *
 *  Created on: Jul 15, 2023
 *      Author: dell
 */
#include "DC.h"
//Variables
int DC_speed = 0;


//State pointer to function
void (*DC_state)();

void DC_init()
{
	//init DC driver
	printf("DC_motor_init\n");
}

void DC_motor_set(int speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CollisionAvoidance--------Speed = %d------------Dc_Motor\n",DC_speed);
}

STATE_define(DC_idle)
{
	//State name
	DC_state_id = DC_Idle;

	//State Action
	//Call PWM to make speed = DC_speed
	printf("DC_idle state: speed= %d\n",DC_speed);
}

STATE_define(DC_busy)
{
	//State name
	DC_state_id = DC_Busy;
	//State Action

	//Call PWM to make speed = DC_speed
	DC_state = STATE(DC_idle);
	printf("DC_busy state: speed= %d\n",DC_speed);
}




