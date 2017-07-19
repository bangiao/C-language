#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b);

int libfun(/*函数指针当做参数*/int(*fun)(int a, int b));

int main()
{
	int(*fun)(int, int) = add;
	libfun(fun);
	system("pause");
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int libfun(int(*fun)(int, int))
{
	int a, b;
	a = 1;
	b = 2;
	printf("%d\n", fun(a, b));
	return 0;
}