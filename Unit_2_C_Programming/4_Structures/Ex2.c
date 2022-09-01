//C program to Add two distances (in inch-feet) system
#include<stdio.h>
#include<string.h>
#include<math.h>

//Defining structure holds distance values in inch and feet
struct Sdistance{		//size of structure = 12 byte
	float m_inch;
	float m_feet;
	float m_distance;
};

//Function to Assign values from user and return value of struct Sdistance data type
float distance(char number[10]){		//array argument to print string

	//Variable 'obj' allocated memory in function stack
	struct Sdistance obj;

	//Scanning feet distance from user
	printf("Enter information of %s distance\nEnter feet: ",number);
	fflush(stdout);		fflush(stdin);
	scanf("%f",&obj.m_feet);

	//Scanning inch distance from user
	printf("Enter inch: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f",&obj.m_inch);

	//Calculate distance
	obj.m_distance = obj.m_feet + obj.m_inch/12;

	return obj.m_distance;
}

int main()
{
	float distance1 , distance2;

	distance1 = distance("first");
	distance2 = distance("second");

	printf("Sum of distance = %.2f",distance1+distance2);

	return 0;
}

