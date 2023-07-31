/*
 * User_interface.c
 *
 *  Created on: Jul 29, 2023
 *      Author: dell
 */

#include "FIFO.h"

FIFO_Buf_t FIFO_Student;

void setup()
{
	uint8_t temp_text[40];
	uint32_t Exit = 0;
	uint32_t option;

	FIFO_Init(&FIFO_Student, DataBase, 50);


	DPRINTF("Welcome to the Student Management System\n");
	while(!Exit)
	{
		DPRINTF("\nChoose the task you want to perform\n");
		DPRINTF("1.Add the student details manually\n");
		DPRINTF("2.Add the student details from text file\n");
		DPRINTF("3.Find the student details by roll number\n");
		DPRINTF("4.Find the student details first name\n");
		DPRINTF("5.Find the student details by course ID\n");
		DPRINTF("6.Find the total number of students\n");
		DPRINTF("7.Delete the student details by roll number\n");
		DPRINTF("8.Show all information\n");
		DPRINTF("9.Update Student information\n");
		DPRINTF("10.Exit\n");

		gets(temp_text);
		option = atoi(temp_text);

		switch(option)
		{
		case 1:
			Add_Student_Details_Manually();
			break;
		case 2:
			Add_Student_Details_From_File();
			break;
		case 3:
			Find_Student_By_ID();
			break;
		case 4:
			Find_Student_By_First_name();
			break;
		case 5:
			Find_Students_Registered_In_Course();
			break;
		case 6:
			Count_Of_Students();
			break;
		case 7:
			Delete_Student();
			break;
		case 8:
			Show_all_information();
			break;
		case 9:
			Update_Student();
			break;
		case 10:
			Exit = 1;
			break;
		default:
			DPRINTF("\n===================================================");
			DPRINTF("\n\tWrong Option please try again.");
			DPRINTF("\n===================================================\n");
			break;
		}
	}
}
