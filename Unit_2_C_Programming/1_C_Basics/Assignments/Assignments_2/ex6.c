/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 6
#include<stdio.h>

int main(){

	unsigned int x;
	int i,sum=0;
	printf("Enter an integer: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&x);
	for (i=1; i<=x; i++){
		sum += i;
	}
	printf("Sum = %d",sum);
	return 0;
}

