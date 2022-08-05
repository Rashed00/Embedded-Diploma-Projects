/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 2
#include<stdio.h>

int main(){

	char x;
	printf("Enter an alphabet: ");
	fflush (stdout); 	fflush(stdin);
	scanf("%c", &x);
	if (x=='a'||x=='i'||x=='o'||x=='u'||x=='e')
		printf("%c is a vowel", x);
	else
		printf("%c is a consonant", x);

	return 0;
}

