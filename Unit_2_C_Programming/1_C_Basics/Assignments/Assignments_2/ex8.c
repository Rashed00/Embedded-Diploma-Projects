/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 8

#include <stdio.h>

int main(){

	float x,y;
	char operator;

	printf("Enter operator: ");
	fflush(stdout);		fflush(stdin);
	scanf("%c",&operator);

	printf("Enter two operands: ");
	fflush(stdout);		fflush(stdin);
	scanf("%f %f",&x,&y);

	switch(operator){

	case '+':{
		printf("%f + %f = %f",x,y,x+y);
	}
	break;

	case '-':{
		printf("%f - %f = %f",x,y,x-y);
	}
	break;

	case '*':{
		printf("%f * %f = %f",x,y,x*y);
	}
	break;

	case '/':{
		printf("%f / %f = %f",x,y,x/y);
	}
	break;

	default:{
		printf("Wrong operator.");
	}
	break;
	}

	return 0;
}
