#include <stdio.h>
#include <stdlib.h>
// ����� 10 ��������, �������ǲ������ڴ�ĵ�ַ
// ����� "abcd" �ǳ��� �������ĳ��������ڴ�ĵ�ַ
int main(int argc, char *args[])
{
	printf("%p", &"abcd");
	//printf("%p", &10);
	system("pause");
	return 0;
}