#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

double work_m(double x, double m, double sum)
{
	double ret = 0;
	for (m = 0; m < INT_MAX; m++)
	{
		if (sum == pow(x, 2) + x + m)
		{
			ret = m;
			return ret;
		}
	}
	return ret;
}

double work_sum(double x, double m, double sum)
{
	double ret = 0;
	printf("pow(x): %f\n", pow(x, 2));
	sum = pow(x, 2) + x + m;
	ret = sum;
	return ret;
}

int main01()
{
	int ret = 0;
	double m = 0;
	double x = 0;
	double sum = 0;

	//当 x 等于 1 是 x*x+x+m == 7
	x = 1;
	sum = 7;
	m = work_m(x, m, sum);
	printf("m:%f\n", m);

	//当 x = -1
	x = -1;
	sum = work_sum(x, m, sum);
	printf("sum:%f\n", sum);
	system("pause");
	return ret;
}


//const 修饰目标看 const 和 * 之间的位置
//const 在 * 前 表示const 修饰指针指向的内存(const int *p或者 int const *p)
//const 在 * 后 表示const 修饰指针指向的地址(指针的值)
int main(int argv, char *args[])
{
	int ret = 0;
	int a = 3;
	int b = 4;

// 	const int *p = &a;
// 	*p = 4;
// 
// 	int const *p3 = &a;
// 	*p3 = b;

// 	int * const p1 = &a;
// 
// 	int *p2 = &b;
// 
// 	p1 = p2;







	system("pause");
	return ret;
}