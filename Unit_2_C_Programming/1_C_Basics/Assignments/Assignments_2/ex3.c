/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 3
#include<stdio.h>

int main(){

	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);
	if (a>b){
		if(a>c)
			printf("Largest number = %f", a);
		else
			printf("Largest number = %f",c);
	}
	else if (b>c)
		printf("Largest number = %f",b);
	else
		printf("Largest number = %f", c);
	return 0;
}

