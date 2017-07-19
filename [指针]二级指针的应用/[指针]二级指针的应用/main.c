#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int **a)
{
	int *b = (int *)malloc(sizeof(int) * 10);
	int i = 0 ;
	if (NULL == b)
	{
		printf("func err malloc() \n");
		return;
	}
	for (i = 0; i < 10; i++)
	{
		b[i] = i + 1;
	}
	*a = b;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int i = 0;
	int *a = NULL;

	func(&a);

	for (i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	system("pause");
	return ret;
}