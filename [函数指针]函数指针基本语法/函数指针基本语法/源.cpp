#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int FUN(int);

//���������ƾʹ���������ڵ�ַ
int ret_fun(int a)
{
	return a*a;
}

int main1()
{
	//�ú������Ͷ���һ������ָ��
//	FUN &f1 = ret_fun;
	FUN *f1 = ret_fun;

	printf("%d\n", f1(2));

	//�Ժ���������ȡ���ٴε�ַ����һ����ͬ�� *Ҳ����ȡ���޲�
	f1 = &ret_fun;
	printf("%d\n", f1(3));
	system("pause");
	return 0;
}

void f(void)
{
	printf("ִ����f\n");
}

int main2()
{
	//����ָ��������ָ��ǳ�����
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

//ֱ�Ӷ���һ������ָ������
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