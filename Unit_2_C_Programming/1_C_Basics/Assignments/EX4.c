/*
 * EX4.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 4 Write C Program to Multiply two Floating Point Numbers

#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,product;
	printf("Enter two numbers: ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f %f",&a,&b);
	product = a*b;
	printf("Product: %f",product);
	return 0;
}

