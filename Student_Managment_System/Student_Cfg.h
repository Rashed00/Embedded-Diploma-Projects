/*
 * Student_Cfg.h
 *
 *  Created on: Jul 29, 2023
 *      Author: dell
 */

#ifndef STUDENT_CFG_H_
#define STUDENT_CFG_H_

//Define structure for student info
typedef struct
{
	uint8_t first_name[20];
	uint8_t second_name[20];
	uint32_t ID;
	float GPA;
	uint8_t Course_ID[5];
}info_t;

//USER CONFIGURATION
#define element_type 	info_t

//Create buffer
#define width1 50
element_type DataBase[width1];

#endif /* STUDENT_CFG_H_ */
