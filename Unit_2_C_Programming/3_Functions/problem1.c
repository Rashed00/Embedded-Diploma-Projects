//C program to print prime numbers between two intervals
#include<stdio.h>

//Function to find the prime numbers
int prime(int first_num, int last_num){
	int i,k;
	int m;
//nested loop to check every integer between two numbers
	for(i=first_num; i<=last_num; i++){
		m=i/2;		//variable 'm' used to limit the number of iterations in second loop
		for(k=2; k<=m; k++){
			if(i%k==0){
				break;
			}
			if(k==m){
				printf("%d ",i);
			}
		}
	}
}

int main()
{
	int interval1,interval2;
//Assigning two intervals in main function
	printf("Enter two numbers (intervals): ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d %d",&interval1,&interval2);
//Calling function using pass by value
	printf("Prime numbers between %d and %d are: ",interval1,interval2);
	prime(interval1,interval2);
	return 0;
}

