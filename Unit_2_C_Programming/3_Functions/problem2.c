//C program to calculate a factorial of number using recursion
#include<stdio.h>
//Recursive function to calculate to factorial of a nubmer
int factorial(int x){
	static int y=1;		/*static integer used to not initialize variable 'y' each function call*/
	if(x>0){
		y*=x;
		x--;
		factorial(x);
	}
	else
		printf("%d",y);
}

int main()
{
//Assigning positive number to be calculated from user
	int number;
	printf("Enter a positive integer: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&number);
	printf("Factorial of %d = ",number);
//Function call
	factorial(number);
	return 0;
}

