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

	//���������䱾�ʾ�������ָ��(�����ָ��) ��Դ����ĵ�����ָ�벽�� 3 Ҳ����˵ ����ָ������(+1)���� + 3
	printf("*a = %p\n", *a);//�����һ��Ԫ�صĵ�ַ
	printf("a[0] = %p\n", a[0]);//ͬ��
	printf("*a + 1 = %p\n", *a + 1);//����ڶ���Ԫ�صĵ�ַ
	printf("*(a + 1) = %p\n", *(a + 1));//����ָ��+1�൱�ڼ� 3 �ó��������� a[1]�ĵ�ַ	
	printf("**a = %d\n", **a);
	printf("*(*a + 1) = %d\n", *(*a + 1));//�������
	system("pause");
}