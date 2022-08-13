//C program to reverse string without using function library
#include<stdio.h>
#include<string.h>

int main()
{
	char text[100];
	char reverse[100];
	int i,length;
	//Assign the string and setting its length
	printf("Enter the string: ");
	fflush(stdout);		fflush(stdin);
	scanf("%s",&text);
	length=strlen(text);
	//Reversing characters using two arrays
	for(i=length;i>0;i--){
		reverse[length-i] = text[i-1];
	}
	//Add null terminal and printing reversed string
	reverse[length]=0;
	printf("Reverse string is: %s",reverse);

	return 0;
}
