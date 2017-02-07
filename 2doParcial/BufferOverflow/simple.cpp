#include<stdio.h>
#include<cstring>

//g++ simple.cpp -fno-stack-protector
//./a.out 123123124231523451435134513
int main(int argc, char const *argv[])
{
	char arr[8]={'4','5','6','7','0','1','2','3'};
	char arr2[8]={'0','1','2','3','4','5','6','7'};
	int value = 10;

	printf("array 1 is at %p with value %s\n",arr,arr);
	printf("array 2 is at %p with value %s\n",arr2,arr2);
	printf("value is at   %p with value %i\n",&value,value);

	strcpy(arr2,argv[1]);

	printf("array 1 is at %p with value %s\n",arr,arr);
	printf("array 2 is at %p with value %s\n",arr2,arr2);
	printf("value is at   %p with value %i\n",&value,value);

	return 0;
}