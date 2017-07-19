#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这个是约定  是规则 按照这个规则就可以实现回调函数
typedef int(*MyFuncAdd)(int a, int b);

//这是底层库文件  也就是上层应用给予的.h文件编写的函数 为了防止错误 函数名字不相同
//这里相当于虚函数表
int add(int a, int b)
{
	return a + b;
}

int add1(int a, int b)
{
	return a + b;
}

int add2(int a, int b)
{
	return a + b;
}

//这是架构 也就是不用一直改变的地方
int mainOP(MyFuncAdd MyAdd, int a, int b)
{
	int ret = 0;
	ret = MyAdd(a, b);
	return ret;
}
//这是架构
int mainOP2(int(*MFuncAdd2)(int a, int b), int a, int b)
{
	int ret = 0;
	ret = MFuncAdd2(a, b);
	return ret;
}

int main()
{
	//这是上层应用  上层业务  也就是经常改变的业务地区
	int ret = 0;
	int a = 9;
	int b = 10;
	MyFuncAdd MyAdd = NULL;
	MyAdd = add;

	ret = add(a, b);	//直接调用的方法
	ret = mainOP(MyAdd, a, b);	//没上路
	//这里相当于根据函数指针(vptr指针)寻址
	ret = mainOP(add, a, b);	//间接调用法
	ret = mainOP(add1, a, b);
	ret = mainOP(add2, a, b);

	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}