/*
 * Student.c
 *
 *  Created on: Jul 19, 2023
 *      Author: dell
 */


#include "FIFO.h"

extern FIFO_Buf_t FIFO_Student;



/*
 * ===============================================================
 * 					Built-in Functions Definition
 * ===============================================================
*/
/**================================================================
 * @Fn			-Print_Student
 * @brief 		-Function prints certain student
 * @param [in]	-temp: pointer to element type of Student info that holds all info about student.
 * @retval 		-None.
 * Note			-
 */

void Print_Student(element_type* temp)
{
	uint32_t j;
	DPRINTF("\n====================================\n");
	DPRINTF("\tStudent roll number: %d\n",(temp->ID));
	DPRINTF("\tStudent name: %s %s\n",(temp->first_name),(temp->second_name));
	DPRINTF("\tStudent GPA: %.1f \n",(temp->GPA));
	DPRINTF("\tStudent Courses ID: ");
	for(j = 0; j<5; j++)
		DPRINTF("%d ",(temp->Course_ID[j]));
	DPRINTF("\n====================================\r\n");
}

/**================================================================
 * @Fn			-Check_existing_ID
 * @brief 		-Function checks if certain ID exists in whole system or not.
 * @param [in]	-temp: pointer to element type of Student info that holds all info about student.
 * @param [in]	-ID: value of ID you want to check on.
 * @retval 		-Student_statues_t: function returns enum that represents status of ID.
 * Note			-
 */
Student_statues_t Check_existing_ID(element_type* temp, uint32_t ID)
{
	//	element_type* temp;
	uint32_t i;
	temp = FIFO_Student.tail;
	for(i= 0; i<(FIFO_Student.count); i++)
	{
		if(temp->ID == ID)
		{

			return ID_exist;
		}
		else
			temp++;
	}
	return no_error;
}


/**================================================================
 * @Fn			-Enter_student_Details
 * @brief 		-Function used to take info from user manually and store it in system.
 * @param [in]	-temp: pointer to element type of Student info that holds all info about student.
 * @retval 		-None.
 * Note			-
 */
void Enter_student_Details(element_type* temp)
{
	//	element_type temp;
	//	element_type* check;
	//	check = FIFO_Student.tail;
	//	check = FIFO_Student.tail;

	char temp_text[40];
	uint32_t i,ID;

	DPRINTF("\nEnter Student ID: ");
	gets(temp_text);
	ID = atoi(temp_text);


	while(Check_existing_ID(temp,ID) == ID_exist)
	{
		DPRINTF("\n>ID already exist, try another!");
		DPRINTF("\nEnter Student ID: ");
		gets(temp_text);
		ID = atoi(temp_text);
	}

		temp->ID = ID;

		DPRINTF("\nEnter Student first name: ");
		gets(temp->first_name);

		DPRINTF("\nEnter Student second name: ");
		gets(temp->second_name);


		DPRINTF("\nEnter Student GPA: ");
		scanf("%f",&(temp->GPA));

		while(temp->GPA > 4 || temp->GPA < 0)
		{
			DPRINTF("\n>Invalid input. Try again");
			DPRINTF("\nEnter Student GPA: ");
			scanf("%f",&(temp->GPA));
		}


		for(i=0; i<5; i++)
		{
			DPRINTF("\nEnter Course[%d] ID: ",i+1);
			gets(temp_text);
			temp->Course_ID[i] = atoi(temp_text);

		}
}


/*
 * ===============================================================
 * 						APIs Function Definition
 * ===============================================================
*/

/**================================================================
 * @Fn			-Add_Student_Details_From_File
 * @brief 		-Function used to add students info from text file with file format (space between each info (ID name GPA)
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */

void Add_Student_Details_From_File()
{
	uint8_t temp_text[40];
	element_type* temp;
	temp = FIFO_Student.head;
	uint32_t count = 0;

	DPRINTF("\nEnter file.txt name: ");
	gets(temp_text);

	FILE *fp;
	fp = fopen(temp_text, "r");
	if(fp == NULL)
	{
		DPRINTF("\n==============================================");
		DPRINTF("\n\tError opening file.");
		DPRINTF("\n==============================================\n");
	}
	else
	{
		//Read student information from file
		while(FIFO_Student.count < 50 &&
				fscanf(fp, "%d %s %s %f %d %d %d %d %d\n",
						&(temp->ID),
						(temp->first_name),
						(temp->second_name),
						&(temp->GPA),
						&(temp->Course_ID[0]),
						&(temp->Course_ID[1]),
						&(temp->Course_ID[2]),
						&(temp->Course_ID[3]),
						&(temp->Course_ID[4])) == 9 )
		{
			if(Check_existing_ID(temp,temp->ID) == ID_exist)
			{
				continue;
			}
			else
			{
				DPRINTF("\n>Reading line (%d) from file...",count+1);
				count++;
				temp++;
				FIFO_Student.count++;
				FIFO_Student.head++;
			}
		}
		DPRINTF("\n==============================================");
		DPRINTF("\n\tFile has been read successfully.");
		DPRINTF("\n==============================================\n");

	}
	fclose(fp);
}


/**================================================================
 * @Fn			-Add_Student_Details_Manually
 * @brief 		-Function used to add students manually by user registering to system
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Add_Student_Details_Manually()
{
	switch(FIFO_IS_FULL(&FIFO_Student))
	{
	case FIFO_no_error:
		break;
	case FIFO_full:
		DPRINTF("\n===================================================");
		DPRINTF("\n\tNo storage in Data base!");
		DPRINTF("\n===================================================\n");
		break;
	default:
		break;
	}
	element_type* temp;
	temp = FIFO_Student.head;
	Enter_student_Details(temp);
	FIFO_Enqueue(&FIFO_Student, temp);
	DPRINTF("\n===================================================");
	DPRINTF("\n\tStudent enrolled successfully!");
	DPRINTF("\n===================================================\n");

}

/**================================================================
 * @Fn			-Find_Student_By_ID
 * @brief 		-Function to find Student registered with unique roll number.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Find_Student_By_ID()
{
	uint32_t ID;
	char temp_text[40];

	//Get student ID from user.
	DPRINTF("\nEnter Student ID: ")
	gets(temp_text);
	ID = atoi(temp_text);

	//define temporary structure to compare given ID with all buffer IDs
	element_type* temp;
	uint32_t i;
	temp = FIFO_Student.tail;

	//Loop for all buffer values
	for(i= 0; i<(FIFO_Student.count); i++)
	{
		if(ID == temp->ID)
		{
			Print_Student(temp);
			break;
		}
		else
		{
			temp++;
			if(i == (FIFO_Student.count -1))
			{
				DPRINTF("\n===================================================");
				DPRINTF("\n\tStudent with ID (%d) not found!",ID);
				DPRINTF("\n===================================================\n");
			}
		}
	}
}


/**================================================================
 * @Fn			-Find_Student_By_First_name
 * @brief 		-Function to find student by his first name.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Find_Student_By_First_name()
{
	//define temporary structure to compare given name with all buffer names
	element_type* temp;
	uint32_t i,count=0;
	uint8_t name[20];
	uint8_t temp_text[40];

	//Get student first name from user.
	DPRINTF("\nEnter Student First name: ")
	gets(name);

	temp = FIFO_Student.tail;
	for(i = 0; i<FIFO_Student.count; i++)
	{
		if(!(strcmp(name,temp->first_name)))
		{
			Print_Student(temp);
			count++;
		}
		else if(i == (FIFO_Student.count -1) && (count == 0))
		{
			DPRINTF("\n===================================================");
			DPRINTF("\n\tStudent '%s' not found!",name);
			DPRINTF("\n===================================================\n");
		}
		temp++;
	}

}

/**================================================================
 * @Fn			-Find_Students_Registered_In_Course
 * @brief 		-Function to print all students info that registered in specific course ID.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Find_Students_Registered_In_Course()
{
	element_type* temp;
	uint32_t i,j,course_ID,count = 0;
	uint8_t temp_text[40];
	temp = FIFO_Student.tail;

	DPRINTF("\nEnter Course ID: ");
	gets(temp_text);
	course_ID = atoi(temp_text);

	DPRINTF("\n==========Course[%d]_Print===========",course_ID);
	for(i=0; i<FIFO_Student.count; i++)
	{
		for(j=0; j<5; j++)
		{
			if(course_ID == temp->Course_ID[j])
			{
				Print_Student(temp);
				count++;
				break;
			}

		}
		temp++;
		if((i == (FIFO_Student.count -1)) && (count == 0))
		{
			DPRINTF("\n===================================================");
			DPRINTF("\n\tNo students enrolled in course[%d].",course_ID);
			DPRINTF("\n===================================================\n");
		}
	}

}

/**================================================================
 * @Fn			-Count_Of_Students
 * @brief 		-Function to print the count of all students in system.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Count_Of_Students()
{
	DPRINTF("\n===================================================");
	DPRINTF("\n\tCount of all students = %d",FIFO_Student.count);
	DPRINTF("\n===================================================\n");
}


/**================================================================
 * @Fn			-Delete_Student
 * @brief 		-Function to delete certain student using his unique roll number.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Delete_Student()
{
	uint32_t ID;
	char temp_text[40];

	//Get student ID from user.
	DPRINTF("\nEnter Student ID: ")
	gets(temp_text);
	ID = atoi(temp_text);

	//define temporary structure to compare given ID with all buffer IDs
	element_type* temp;
	uint32_t i;
	temp = FIFO_Student.tail;

	if(Check_existing_ID(temp,ID) == ID_exist)
	{
		//Loop for all buffer values
		for(i= 0; i<(FIFO_Student.count); i++)
		{
			if(ID == temp->ID)
			{
				FIFO_Dequeue(&FIFO_Student, temp);
				DPRINTF("\n===================================================");
				DPRINTF("\n\tStudent with roll number = %d has been deleted.",ID);
				DPRINTF("\n===================================================\n");

				break;
			}
			else
				temp++;
		}
	}
	else
	{
		DPRINTF("\n===================================================");
		DPRINTF("\n\tID not found.");
		DPRINTF("\n===================================================\n");
	}
}


/**================================================================
 * @Fn			-Update_Student
 * @brief 		-Function to update student info. that includes his ID.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Update_Student()
{
	uint8_t temp_text[40];
	element_type* temp;
	uint32_t i,ID;
	DPRINTF("\nEnter ID of student to be updated: ");
	gets(temp_text);
	ID = atoi(temp_text);


	temp = FIFO_Student.tail;
	for(i= 0; i<(FIFO_Student.count); i++)
	{
		if(ID == temp->ID)
		{
			FIFO_Dequeue(&FIFO_Student, temp);
			temp = FIFO_Student.head;
			Enter_student_Details(temp);
			FIFO_Enqueue(&FIFO_Student, temp);
			DPRINTF("\n===============================================");
			DPRINTF("\n\tStudent updated successfully!");
			DPRINTF("\n===============================================\n");
			break;
		}
		else if(i == (FIFO_Student.count - 1))
		{
			DPRINTF("\n===================================================");
			DPRINTF("\n\tCannot find matching ID.");
			DPRINTF("\n===================================================\n");
		}
		else
			temp++;
	}
}


/**================================================================
 * @Fn			-Show_all_information
 * @brief 		-Function to show all students registered in system.
 * @param [in]	-None.
 * @retval 		-None.
 * Note			-
 */
void Show_all_information()
{
	element_type* temp;
	temp = FIFO_Student.tail;
	int i;
	if(FIFO_Student.count==0)
	{
		DPRINTF("\n===================================================");
		DPRINTF("\n\tSystem is empty");
		DPRINTF("\n===================================================\n");

	}
	else
	{
		DPRINTF("\n========Information_Print========\n");
		for(i=0; i<FIFO_Student.count; i++)
		{
			Print_Student(temp);
			if(temp == (FIFO_Student.base + ((FIFO_Student.length)-1) * sizeof(element_type)))
				temp = FIFO_Student.tail;
			else
				temp++;
		}
	}

}

