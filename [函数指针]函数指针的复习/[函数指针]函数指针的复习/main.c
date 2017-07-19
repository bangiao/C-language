#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *Swap(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return a;
}
//定义一个函数指针类型
typedef int *(*FUNCSwap)(int *, int *);

int main01()
{
	int ret = 0;
	int a = 10;
	int b = 20;
	int *p = NULL;
	
	p = Swap(&a, &b);
	printf("a:%d\t", a);
	printf("b:%d\t", b);
	printf("*p:%d\t", *p);
	puts("");

	//定义一个函数指针
	int *(*FuncSwap)(int *, int *) = Swap;
	p = FuncSwap(&a, &b);
	printf("a:%d\t", a);
	printf("b:%d\t", b);
	printf("*p:%d\t", *p);
	puts("");

	FUNCSwap Functmp = Swap;
	p = Functmp(&a, &b);
	printf("a:%d\t", a);
	printf("b:%d\t", b);
	printf("*p:%d\t", *p);
	puts("");

	return ret;
}

int main02()
{
	int ret = 0;
	int i = 0;
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(a) / sizeof(int);
//	int *(*FuncSwap)(int *, int *);
	int(*pArray)[3];
	pArray = a;

	for (i = 0; i < len; i++)
	{
		printf("pArray:%d\t", ((*pArray)[i]));
	}
	puts("");
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	//函数指针的测试
	main01();
	//数组指针的测试
	main02();
	system("pause");
	return ret;
}