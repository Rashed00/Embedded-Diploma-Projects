//C program to store information of students
#include<stdio.h>
#include<string.h>
#include<math.h>
//Structure holds student information (name, roll and marks)
struct Sinfo{
	char name[50];
	int roll;
	float marks;
};

int main()
{
	//Object array 'student' created in main stack (size of struct Sinfo)
	struct Sinfo student[10];
	int count=0;
	int i;
	printf("Enter information of students:\n");
	//Assigning values to members in each array element
	do {
		student[count].roll = count + 1;
		//Assigning student name
		printf("For roll number %d\nEnter name: ",student[count].roll);
		fflush(stdout);		fflush(stdin);
		scanf("%s",&student[count].name);
		//Assigning student marks
		printf("Enter marks: ");
		fflush(stdout);		fflush(stdin);
		scanf("%f",&student[count].marks);
		count++;

		if(count==10)
			break;
	}
	while(count);
	//Displaying result
	printf("Displaying information of students:\r\n");
	for(i=0;i<10;i++){
		printf("Information for roll number %d:\n",student[i].roll);
		printf("Name: %s\n",student[i].name);
		printf("Marks: %.1f\r\n",student[i].marks);

	}

	return 0;
}

