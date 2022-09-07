//C program to print elements of array in reverse order
#include <stdio.h>
#include <string.h>

int main()
{
	int num, i, temp;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&num);
	temp = num;

	int array[num];
	int reverse[num];
	int *arrptr = array;
	int *revptr = reverse;

	for(i = 1; i<=num; i++){
		printf("element - %d : ",i);
		fflush(stdin);		fflush(stdout);
		scanf("%d",arrptr);
		arrptr++;
	}
	while(num>0){
		arrptr--;
		*revptr = *arrptr;
		revptr++;
		num--;
	}

	printf("\r\nThe elements of array in reverse order are :\n");
	for(i = temp; i>0; i--){
		printf("element - %d : %d\n",i,reverse[temp - i]);

	}

	return 0;
}



