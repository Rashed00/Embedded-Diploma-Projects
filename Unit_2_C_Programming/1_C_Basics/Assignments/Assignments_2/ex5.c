/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Homework#2 example 5

#include <stdio.h>

int main(){

    char x;
    printf("Enter a character:");
    fflush(stdout);
    fflush(stdin);
    scanf("%c",&x);
    if ((x>='a'&& x<='z')||(x>='A' && x<='Z'))
    	printf("%c is an alphabet.", x);
    else
    	printf("%c is not an alphabet", x);

    return 0;
}
