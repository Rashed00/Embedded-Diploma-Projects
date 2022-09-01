//C program to calculate area by passing arguments to macros
#include<stdio.h>
#include <math.h>
#include<string.h>
#define PI 3.1415
#define area(r) (PI*(r)*(r))

int main(){
	int radius;
	float area;
	printf("Enter radius: ");
	fflush(stdout);		fflush(stdin);
	scanf("%d",&radius);

	area = area(radius);
	printf("Area = %.2f",area);

	return 0;
}
