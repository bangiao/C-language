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

	//�� x ���� 1 �� x*x+x+m == 7
	x = 1;
	sum = 7;
	m = work_m(x, m, sum);
	printf("m:%f\n", m);

	//�� x = -1
	x = -1;
	sum = work_sum(x, m, sum);
	printf("sum:%f\n", sum);
	system("pause");
	return ret;
}


//const ����Ŀ�꿴 const �� * ֮���λ��
//const �� * ǰ ��ʾconst ����ָ��ָ����ڴ�(const int *p���� int const *p)
//const �� * �� ��ʾconst ����ָ��ָ��ĵ�ַ(ָ���ֵ)
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