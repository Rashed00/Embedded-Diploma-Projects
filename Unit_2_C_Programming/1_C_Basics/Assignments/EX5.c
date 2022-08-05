/*
 * EX5.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 5 Write C Program to Find ASCII Value of a Character
#include <stdio.h>
#include <math.h>
int main()
{
	char x;
	printf("Enter a character: ");
	fflush (stdout);
	scanf("%c", &x);
	printf("ASCII value of %c = %d",x,x);
	return 0;
}

