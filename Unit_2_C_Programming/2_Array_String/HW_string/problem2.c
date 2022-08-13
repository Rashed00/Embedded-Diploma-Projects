//C program to find the legth of a string
#include<stdio.h>
#include<string.h>

int main()
{
	int i,length=0;
	char text[100];
	//Assigning string
	printf("Enter a string: ");
	fflush(stdout);		fflush(stdin);
	gets(text);
	//Incrementing 'length' variable for every letter
	for(i=0; i<=length; i++){
		if((text[i]>='a' && text[i]<='z')||(text[i]>='A' && text[i]<='Z')||(text[i]==' ')){
			length++;
		}
	}
	//Printing length
	printf("Length of string: %d\n", length);

	return 0;
}
