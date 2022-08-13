//C program to the frequency of a character in a string
#include<stdio.h>
#include<string.h>

int main()
{
	//Defining arrays and variables
	char text[100];
	char letter;
	int i,frequency=0;
	//Assign a text from the user
	printf("Enter a string: ");
	fflush(stdout);		fflush(stdin);
	gets(text);
	//Assign the character you want to check its frequency
	printf("Enter a character to find frequency: ");
	fflush(stdout);		fflush(stdin);
	scanf("%c",&letter);
	//Finding frequency
	for(i=0;i<strlen(text);i++){
		if(letter==text[i]){
			frequency++;
		}
	}
	//Printing result
	printf("Frequency of %c = %d",letter,frequency);

	return 0;
}
