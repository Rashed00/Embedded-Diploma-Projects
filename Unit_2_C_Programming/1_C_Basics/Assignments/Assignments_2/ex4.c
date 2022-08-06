/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 4
#include<stdio.h>

int main(){

	float x;
	printf("Enter a number: ");
	fflush (stdout);		fflush (stdin);
	scanf("%f", &x);
	if(x>0)
		printf("%f is postive.",x);
	else if(x<0)
		printf("%f is negative.", x);
	else
		printf("You entered zero.");


	return 0;
}

