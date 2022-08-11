//C program to calculate average using arrays
#include<stdio.h>
#include<string.h>

int main()
{
	int n,i;
	float sum=0;
	//scanning size of the array then defining the array size based upon it
	printf("Enter the number of data: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&n);
	float x[n];
	//get elements values and store its summation in variable 'sum'
	for (i=0;i<n;i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdout);		fflush(stdin);
		scanf("%f",&x[i]);
		sum += x[i];
	}
	//printing the average value
	printf("Average = %.2f", sum/n);

	return 0;
}
