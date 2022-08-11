//C program to search an element in Array
#include<stdio.h>
#include<string.h>

int main()
{
	int i,search;
	int num=0;
//Assign number of elements and create an array of the same size
	printf("Enter no of elements: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&num);
	int arr[num];
//Assign values of the array
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
//Scanning the value to be searched
	printf("Enter the elements to be searched: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&search);
//Printing the location of value if found
	for(i=0;i<num;i++){
		if(search==arr[i]){
			printf("Number found at the location = %d", i+1);
			break;
		}
//in case number wasn't found
	}
	if(i==num)
		printf("Number not found.");

	return 0;
}

