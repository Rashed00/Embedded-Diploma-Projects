//C program to find transpose of matrix
#include<stdio.h>
#include<string.h>

int main()
{
	int n,m,i,k;
	//scanning size of the array then defining the array size based upon it
	printf("Enter numbers of rows and columns of matrix respectively:\n");
	fflush(stdout);		fflush(stdin);
	scanf("%d %d",&n,&m);
	float x[n][m];
	float y[m][n];
	//putting values in both x and y matrices
	printf("\nEnter elements of matrix:\n");
	for (i=0;i<n;i++){
		for (k=0;k<m;k++){
			printf("Enter elements a%d%d: ",i+1,k+1);
			fflush(stdout);		fflush(stdin);
			scanf("%f",&x[i][k]);
			y[k][i]=x[i][k];

		}
	}
	//printing the scanned matrix
	printf("\nEntered matrix:\n");
	for (i=0;i<n;i++){
		for (k=0;k<m;k++){
			printf("%.2f\t",x[i][k]);
		}
		printf("\r\n");
	}

	//printing the transpose matrix
	printf("\nTranspose matrix:\n");
	for (i=0;i<m;i++){
		for (k=0;k<n;k++){
			printf("%.2f\t",y[i][k]);
		}
		printf("\r\n");
	}

	return 0;
}

