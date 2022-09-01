/*C program to store information of student
(name, roll and marks) of a student using structures*/
#include<stdio.h>
#include<string.h>
#include<math.h>
//Structure definition contain char and int data type
struct Sinfo{		//size of struct Sinfo = 9 byte (packing)
	char m_name[50];					   //12 byte (padding)
	int m_roll;
	float m_marks;
};

int main()
{
	//Local variable of user-defined data type (struct Sinfo)
	struct Sinfo student;
	char first_name[50];
	char second_name[50];

	//Assigning first name from user
	printf("Enter your first name: ");
	fflush(stdout);		fflush(stdin);
	scanf("%s",&first_name);

	//Assigning second name from user
	printf("Enter your second name: ");
	fflush(stdout);		fflush(stdin);
	scanf("%s",&second_name);

	//Put both first and second names in member 'name' in the struct above
	strcpy(student.m_name,first_name);
	strcat(student.m_name," ");
	strcat(student.m_name, second_name);

	//Scan roll value to roll member of struct Sinfo student
	printf("Enter your roll number: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&student.m_roll);

	//Assigning marks value as an integer to struct Sinfo variable
	printf("Enter your marks: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f",&student.m_marks);

	//Printing result
	printf("Student Name: %s\nID: %d\nTotal Marks: %.2f",student.m_name,student.m_roll,student.m_marks);

	return 0;
}

