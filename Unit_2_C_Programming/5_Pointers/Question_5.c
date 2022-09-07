//C program to show a pointer to an array which contents are pointer to structure.
#include <stdio.h>
#include <string.h>

struct Semployee{
	char *name;
	int id;
};
int main()
{
	static struct Semployee emp1={"John",1003},emp2 ={"Alex",1002},emp3={"Taylor",1004};
	struct Semployee (*arr[])={&emp1,&emp2,&emp3};
	struct Semployee (*(*ptr)[3])= &arr;

	printf("Employee Name : %s\n",(**(*ptr+1)).name);
	printf("Employee ID : %d",(*(*ptr+1))->id);


	return 0;
}



