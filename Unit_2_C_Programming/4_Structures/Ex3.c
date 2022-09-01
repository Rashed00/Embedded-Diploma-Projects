//C program to Add two complex numbers
#include<stdio.h>
#include<string.h>
#include<math.h>

//Structure contains float data types of real and imaginary members
struct Scomplex{
	float m_I;
	float m_R;
};

//Function return and arguments of type struct Scomplex
struct Scomplex Sum(struct Scomplex first , struct Scomplex second){

	//object 'sum' to add members of two different complex numbers (function stack)
	struct Scomplex sum;
	sum.m_R = first.m_R + second.m_R;
	sum.m_I = first.m_I + second.m_I;

	return sum;
}

int main()
{
	struct Scomplex first, second, sum;

	//Assigning first complex number from user
	printf("For 1st complex number\nEnter real and imaginary respectively: ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f %f",&first.m_R,&first.m_I);
	//Assigning second complex number from user
	printf("For 2nd complex number\nEnter real and imaginary respectively: ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f %f",&second.m_R,&second.m_I);
	//Function return stored in object 'sum' (main stack)
	sum = Sum(first , second);
	//Printing result
	printf("Sum = %.2f + %.2fi", sum.m_R , sum.m_I);

	return 0;
}

