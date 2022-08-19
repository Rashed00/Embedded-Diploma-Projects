//C program to reverse a sentence using recursion
#include<stdio.h>
#include<string.h>

//Recursive function that reverse a sentence
void sentence(int x, char arr[])
{
	if(x>=0){
		printf("%c",arr[x]);
		x--;
		sentence(x,arr);
	}

}
int main()
{

	int y;
	char text[100];
	//Assigning a sentence from user
	printf("Enter a sentence: ");
	fflush(stdout);		fflush(stdin);
	gets(text);
	//variable 'y' here is used to store sentence length
	y = strlen(text);
	//Using both pass by value and pass by reference in function call
	sentence(y,text);

	return 0;
}

