/*
 * EX3.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 3 Write C Program to Add Two Integers
#include <stdio.h>
#include <math.h>
int main(){
	int a,b,sum;
	printf("Enter two integers: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d %d",&a,&b);
	sum = a+b;
	printf("Sum: %d", sum);

	return 0;
}

