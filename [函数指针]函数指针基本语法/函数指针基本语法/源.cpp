#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int FUN(int);

//函数的名称就代表函数的入口地址
int ret_fun(int a)
{
	return a*a;
}

int main1()
{
	//用函数类型定义一个函数指针
//	FUN &f1 = ret_fun;
	FUN *f1 = ret_fun;

	printf("%d\n", f1(2));

	//对函数的名字取多少次地址都是一样的同样 *也可以取无限层
	f1 = &ret_fun;
	printf("%d\n", f1(3));
	system("pause");
	return 0;
}

void f(void)
{
	printf("执行了f\n");
}

int main2()
{
	//函数指针和数组的指针非常相似
	void (*F1)() = f;
	void(*F2)() = &f;
	F1();
	F2();

	printf("%p\n", F1);
	printf("%p\n", f);
	printf("%p\n", &f);
	system("pause");
	return 0;
}

//直接定义一个函数指针类型
typedef int(*fun)();
fun aa;

int print(int a, int b)
{
	return a + b;
}

typedef int(*Print)(int, int);

int main()
{
//	fun f1 = print;
	Print P1 = print;

	printf("%d\n", P1(3, 4));
	system("pause");
	return 0;
}