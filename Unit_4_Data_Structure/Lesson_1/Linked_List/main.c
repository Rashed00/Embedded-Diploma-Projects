/*
 * main.c
 *
 *  Created on: Feb 5, 2023
 *      Author: dell
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "stdint.h"
#define DPRINTF(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

//effective data

struct Sdata
{
	int ID;
	char Name[40];
	float height;
};

//Linked List Node

struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;
};

struct SStudent* gpFirstStudent = NULL;
unsigned int Students_Num = 0;

void Add_Student()
{
	struct SStudent* PNewStudent;
	struct SStudent* PLastStudent;
	char temp_text[40];
	//check if record is empty
	//if yes
	if(gpFirstStudent == NULL)
	{
		//Set a new student record
		PNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		gpFirstStudent = PNewStudent;
	}
	//if no
	else
	{
		PLastStudent = gpFirstStudent;
		while(PLastStudent->PNextStudent)
			PLastStudent = PLastStudent->PNextStudent;
		//Set a new student record
		PNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		PLastStudent->PNextStudent = PNewStudent;
	}
	//fill new record
	DPRINTF("=====================\n");
	DPRINTF("Enter Student ID: \n");
	gets(temp_text);
	PNewStudent->Student.ID = atoi(temp_text);

	DPRINTF("Enter Student Full Name: \n");
	gets(PNewStudent->Student.Name);

	DPRINTF("Enter student height: \n");
	gets(temp_text);
	PNewStudent->Student.height = atof(temp_text);

	//set the new_student next pointer to null
	PNewStudent->PNextStudent = NULL;
	Students_Num++;
}

int Delete_Student()
{
	unsigned int Selected_ID;
	struct SStudent* PPreviousStudent =NULL;
	struct SStudent* PCurrentStudent = gpFirstStudent;
	char temp_text[40];
	DPRINTF("=====================\n");
	DPRINTF("Enter Student ID to be deleted: \n");
	gets(temp_text);
	Selected_ID = atoi(temp_text);

	if(PCurrentStudent == NULL)
	{
		DPRINTF("List is empty!\n");
		return 0;
	}
	else
	{
		while(PCurrentStudent)
		{
			if(PCurrentStudent->Student.ID == Selected_ID)
			{

				if(PPreviousStudent)
				{
					PPreviousStudent->PNextStudent = PCurrentStudent->PNextStudent;
				}
				else
				{
					gpFirstStudent = PCurrentStudent->PNextStudent;
				}
				free(PCurrentStudent);
				Students_Num--;
				DPRINTF("=====================\n");
				DPRINTF("Student with ID (%d) has been deleted\n",Selected_ID);
				return 1;
			}
			PPreviousStudent = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->PNextStudent;
		}
		DPRINTF("Cannot find Student ID.\n");
		return 0;
	}
}
void Print(struct SStudent* PSelectedStudent)
{

	DPRINTF("ID: %d\n",PSelectedStudent->Student.ID);
	DPRINTF("Name: %s\n",PSelectedStudent->Student.Name);
	DPRINTF("Height: %.1f\r\n",PSelectedStudent->Student.height);
}
void Print_Students()
{
	struct SStudent* PCurrentStudent = gpFirstStudent;
	unsigned int i=0;
	DPRINTF("=====================\n");
	if(PCurrentStudent == NULL)
	{
		DPRINTF("List is empty!\n");
	}

	else
	{
		while(PCurrentStudent)
		{
			i++;
			DPRINTF("Record Number (%d)\n",i);
			DPRINTF("ID: %d\n",PCurrentStudent->Student.ID);
			DPRINTF("Name: %s\n",PCurrentStudent->Student.Name);
			DPRINTF("Height: %.1f\r\n",PCurrentStudent->Student.height);

			PCurrentStudent = PCurrentStudent->PNextStudent;
		}
	}
}
void Delete_all()
{
	struct SStudent* PCurrentStudent = gpFirstStudent;
	DPRINTF("=====================\n");
	if(PCurrentStudent == NULL)
	{
		DPRINTF("List is empty!\n");
	}

	else
	{
		while(PCurrentStudent)
		{
			struct SStudent* PDeleteStudent = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->PNextStudent;
			free(PDeleteStudent);
		}
		gpFirstStudent = NULL;
		DPRINTF("All Students has been deleted.\n");
	}
}
void Nth_Node_from_end()
{
	char temp_text[40];
	int count = 0;
	DPRINTF("=====================\n");
	DPRINTF("Enter Student (Node) index: \n");
	gets(temp_text);
	unsigned int index = atoi(temp_text);

	struct SStudent* Pmain = gpFirstStudent;
	struct SStudent* Pref = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("List is empty!\n");
	}

	else
	{
		while(count<index)
		{
			Pref = Pref->PNextStudent;
			count++;
		}
		while(Pref)
		{
			Pref = Pref->PNextStudent;
			Pmain = Pmain->PNextStudent;
		}
		DPRINTF("=====================\n");
		DPRINTF("Record Number (%d)\n",(Students_Num - index + 1));
		Print(Pmain);
	}
}
int Get_Count(struct SStudent* head)
{

	if(head == NULL)
	{
		return 0;
	}
	else
		return 1 + Get_Count(head->PNextStudent);
}

void Get_Middle()
{
	struct SStudent* PFast = gpFirstStudent;
	struct SStudent* PSlow = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("List is empty!\n");
	}
	else if(PFast->PNextStudent->PNextStudent == NULL)
	{
		PSlow = PSlow->PNextStudent;
		DPRINTF("=====================\n");
		DPRINTF("Record Number (%d)\n",((Students_Num/2) + 1));
		Print(PSlow);
	}
}
int main()
{
	char temp_text[40];
	unsigned int option;

	Label:
	DPRINTF("=====================\n");
	DPRINTF("\tChoose one of the following options\r\n");
	DPRINTF("1:Add Student\n2:Delete Student\n3:View Students\n4:Delete all Students\n5:Find Student from the end with index\n6:Find Total number of Students\n7:Exit\nEnter Option Number: \n");
	gets(temp_text);
	option = atoi(temp_text);

	switch(option)
	{
	case 1:
		Add_Student();
		goto Label;
		break;
	case 2:
		Delete_Student();
		goto Label;
		break;
	case 3:
		Print_Students();
		goto Label;
		break;
	case 4:
		Delete_all();
		goto Label;
		break;
	case 5:
		Nth_Node_from_end();
		goto Label;
		break;
	case 6:
		DPRINTF("=====================\n");
		DPRINTF("Total number of students: %d\n",Get_Count(gpFirstStudent));
		goto Label;
		break;
	case 7:
		break;
	default :
		DPRINTF("Option not listed\n");
		goto Label;
		break;
	}

	return 0;
}
