/*
 * EX7.c
 *
 *  Created on: Aug 5, 2022
 *      Author: dell
 */
//Example 7 Write Source
#include<stdio.h>

int main(){

	int x = 50, y = 9;

	    x = x + y;
	    y = x - y;
	    x = x - y;

	    printf("After Swapping: x = %d, y = %d", x, y);

	return 0;
}

