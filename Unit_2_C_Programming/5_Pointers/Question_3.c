//C program to print string in reverse order
#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	char rev[50];
	//Pointer to string of characters
	char *stptr = str;
	char *revptr = rev;
	printf("Input a string : ");
	fflush(stdin);		fflush(stdout);
	//Assigning a string to pointer holds 'str' address
	scanf("%s",stptr);
	int length = -1;

	while(*stptr){
		stptr++;		//increment pointer by pointer data type size (1Byte)
		length++;
	}
	//pointer 'strptr' pointing now to null terminator
	while(length>=0){
		stptr--;		//decrement to point on last character entered
		*revptr = *stptr;		//storing 'str' array into 'rev' array
		revptr++;
		length--;
	}
	*revptr = '\0';		//Adding null terminator

	printf("Reverse of the string is : %s",rev);		//Printing 'rev' Array

	return 0;
}



