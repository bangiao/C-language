#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ݹ� ���� �ۼ�
int add(int num)
{
	if (0 == num)
	{
		return 0;
	}
	num += add(num - 1);
	return num;
}


int main1(void)
{
	int num = 3;
	int sum = 0;
	sum = add(num);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}

// �ݹ����ڽ׳�
int Mul(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else
	{
		num *= Mul(num - 1);
		return num;
	}
}

int main(void)
{
	int num = 10;
	int sum = 0;
	sum = Mul(num);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}

// �õݹ�ķ���, �����ִ������ַ���
void func1(int num)
{
	if (num / 10)
	{
		func1(num / 10);
	}
	printf("%c", num % 10 + '0');
}

int main3(void)
{
	int num = 203344;

	func1(num);

	system("pause");
	return 0;
}

//���õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ���� 
void func2(char *str)
{ 
	if ('\0' != *str)
	{
		func2(++str);
	}
	printf("%c", *str);
}

int main4(void)
{
	char *str = " ABC";

	func2(str);

	system("pause");
	return 0;
}