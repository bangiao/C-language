#include <stdio.h>
#include <stdlib.h>

enum Enum
{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};

void main()
{
	int a[2][3] = { ONE, TWO, THREE, FOUR, FIVE, SIX };

	//数字名字其本质就是数组指针(数组的指针) 此源代码的的数组指针步长 3 也就是说 数组指针自增(+1)就是 + 3
	printf("*a = %p\n", *a);//数组第一个元素的地址
	printf("a[0] = %p\n", a[0]);//同上
	printf("*a + 1 = %p\n", *a + 1);//数组第二个元素的地址
	printf("*(a + 1) = %p\n", *(a + 1));//数组指针+1相当于加 3 得出的是数组 a[1]的地址	
	printf("**a = %d\n", **a);
	printf("*(*a + 1) = %d\n", *(*a + 1));//自行体会
	system("pause");
}