#include "driver.h"
#include "State.h"
#include "Pressure_Sensor.h"
#include "Main_Algorithm.h"
#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"



void setup()
{
	//init all the drivers
	//init IRQs...
	//init HAL PressureSensor & Alarm Actuator
	PSensor_init();
	Alarm_init();

	//Set state pointers to each block
	Psensor_state = STATE(PSensor_reading);
	Alarm_actuator_state = STATE(alarm_act_waiting);
	Alarm_state = STATE(alarmOFF);
	Check_state = STATE(High_Pressure_check);
}
int main (){

	setup();
	while (1)
	{
		//Implement your Design 
		Psensor_state();
		Check_state();
		Alarm_state();
		Alarm_actuator_state();
		Delay(1000000);
	}
	return 1;
}
