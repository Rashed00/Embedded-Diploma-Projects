//C program to find sum of two matrices
#include<stdio.h>
#include<string.h>
int main()
{
	float matrix1[2][2];
	float matrix2[2][2];
	int i,k;
	//scanning values of first matrix
	printf("Enter the elements of 1st matrix\n");
	for(i=0;i<2;i++){		//nested 'for' loop for multidimensional array
		for(k=0 ; k<2; k++){
			printf("Enter a%d%d: ",i+1,k+1);
			fflush(stdout);		fflush(stdin);
			scanf("%f",&matrix1[i][k]);
		}
	}
	//scanning values of 2nd matrix
	printf("\r\nEnter the elements of 2nd matrix\n");
	for(i=0;i<2;i++){
		for(k=0 ; k<2; k++){
			printf("Enter b%d%d: ",i+1,k+1);
			fflush(stdout);		fflush(stdin);
			scanf("%f",&matrix2[i][k]);
				}
	}
	//adding every two elements
	for(i=0;i<2;i++){
		for(k=0 ; k<2; k++){
			matrix1[i][k]+=matrix2[i][k];
				}
	}
	//printing result
	printf("\r\nSum Of Matrix\n");
	for(i=0;i<2;i++){
		for(k=0;k<2;k++){
			printf("%.1f\t",matrix1[i][k]);
		}
		printf("\r\n");
		}

	return 0;
}
