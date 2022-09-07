//C program to print all the alphabets
#include <stdio.h>
#include <string.h>

int main()
{
	char alphabet[26];		//Array of characters
	char *ptr = alphabet;	//Pointer holds array address
	int i;
	for(i = 0;i<25; i++){
		*ptr = i + 'A';		//storing alphabets in array using pointer
		ptr++;
	}
	ptr = alphabet;			//reset pointer address to the array's
	//Printing result
	printf("The alphabets are:\n");
	for(i = 0;i<25; i++){
		printf("%c ",*ptr);
		ptr++;
	}
	return 0;
}



