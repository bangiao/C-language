#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����Լ��  �ǹ��� �����������Ϳ���ʵ�ֻص�����
typedef int(*MyFuncAdd)(int a, int b);

//���ǵײ���ļ�  Ҳ�����ϲ�Ӧ�ø����.h�ļ���д�ĺ��� Ϊ�˷�ֹ���� �������ֲ���ͬ
//�����൱���麯����
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

//���Ǽܹ� Ҳ���ǲ���һֱ�ı�ĵط�
int mainOP(MyFuncAdd MyAdd, int a, int b)
{
	int ret = 0;
	ret = MyAdd(a, b);
	return ret;
}
//���Ǽܹ�
int mainOP2(int(*MFuncAdd2)(int a, int b), int a, int b)
{
	int ret = 0;
	ret = MFuncAdd2(a, b);
	return ret;
}

int main()
{
	//�����ϲ�Ӧ��  �ϲ�ҵ��  Ҳ���Ǿ����ı��ҵ�����
	int ret = 0;
	int a = 9;
	int b = 10;
	MyFuncAdd MyAdd = NULL;
	MyAdd = add;

	ret = add(a, b);	//ֱ�ӵ��õķ���
	ret = mainOP(MyAdd, a, b);	//û��·
	//�����൱�ڸ��ݺ���ָ��(vptrָ��)Ѱַ
	ret = mainOP(add, a, b);	//��ӵ��÷�
	ret = mainOP(add1, a, b);
	ret = mainOP(add2, a, b);

	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}