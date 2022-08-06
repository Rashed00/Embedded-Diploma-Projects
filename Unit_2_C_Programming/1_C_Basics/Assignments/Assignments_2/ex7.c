/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 7

#include <stdio.h>

int main(){

	int x,i,factorial=1;
	printf("Enter an integer: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&x);
	if (x>0){
		for(i=1;i<=x;i++){
			factorial*=i;
		}
		printf("Factorial = %d",factorial);
	}
	else if(x==0)
		printf("Factorial = 1");
	else if(x<0)
		printf("Error!!! Factorial of negative numbers doesn't exist");


	return 0;
}
