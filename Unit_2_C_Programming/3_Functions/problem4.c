//C program to calculate the power of a number using recursion
#include<stdio.h>
#include<string.h>

//Recursive function to calculate power of a number
void power(int x, int y)
{
	static int m=1;
	if(x==0){
		printf("0");
	}
	else if(x==1){
		printf("1");
	}
	else if(y>=1){
		m*=x;
		--y;
		power(x,y);
	}
	else if(y==0){
		printf("%d",m);
	}
}
int main()
{
	int baseNum;
	int powerNum;
	//Assigning base number from user
	printf("Enter base number: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&baseNum);
	//Assigning power order
	printf("Enter power number (Positive integer): ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&powerNum);
	//calling recursive function
	printf("%d^%d = ",baseNum,powerNum);
	power(baseNum,powerNum);

	return 0;
}

