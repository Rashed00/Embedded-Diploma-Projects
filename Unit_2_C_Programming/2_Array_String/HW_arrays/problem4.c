//C program to insert an element in an Array
#include<stdio.h>
#include<string.h>

int main()
{
	int num,i,location;
	int insert;
//Assign number of elements
	printf("Enter no of elements: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&num);
	int arr[num+1];
//Assign element values
	printf("enter elements values: ");
	fflush(stdout);		fflush(stdin);
	for(i=0;i<num;i++){
		scanf("\n%d",&arr[i]);
	}
//Assign the inserted value
	printf("\nEnter the element to be inserted: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d", &insert);
//Assign location in Array
	printf("Enter the location: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&location);
//Shifting array values to keep the location free of assigned data
	for(i=num;i>=location;i--){
		arr[i]=arr[i-1];
		}
	arr[location-1]=insert;
//Printing new array
	for(i=0;i<num+1;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}
