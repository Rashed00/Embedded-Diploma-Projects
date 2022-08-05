/*
 * EX.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 2 Write C Program to Print a Integer Entered by a User
#include <stdio.h>
#include <math.h>
int main(){
	int x;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x);
	printf("You entered: %d",x);
	return 0;
}

