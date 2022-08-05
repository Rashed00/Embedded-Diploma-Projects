/*
 * EX6.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 6 Write Source Code to Swap Two Numbers
#include<stdio.h>

int main(){

	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f",&b);
	printf("After swapping, value of a = %f\n",b);
	printf("After swapping, value of b = %f",a);
}

