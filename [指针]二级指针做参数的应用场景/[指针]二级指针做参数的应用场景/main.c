#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char **p)
{
	char *ip1 = *p;
	ip1 = "127.0.0.0";	// ������ָ������ָ��һ���µ�ֵ
	*p = "127.0.0.1";	// �����������������ָ��ָ���µ�ֵ
}

int main(void)
{
	char *ip = NULL;
	func(&ip);
	printf("ip = %s\n", ip);
	system("pause");
	return 0;
}