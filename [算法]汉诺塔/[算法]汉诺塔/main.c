#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ŵ��
//����Ŀ��:a --> c
static int flag = 0;
void printH(char a, char c)
{
	flag++;
	printf("%d:%c->%c\n", flag, a, c);
}

void hanoi(char a, char b, char c, int num)
{
	if (1 == num)
	{
		printH(a, c);
	}
	else
	{
		//�� a �ϵ����� ���� c �ƶ��� b
		hanoi(a, c, b, num - 1);
		//��������ܺ����
		//������ֻ��һ����ʱ��ֱ�Ӵ� a �ƶ��� c-
		//�����Ӷ����ʱ��(��������), �� (1) hanoi(a, c, b, num - 1); �������  
		//���ʱ�� (2) void hanoi(char a, char b, char c, int num)
		//������� a ��Ӧ (1) �ܵ� a
		//(2)��b��Ӧ(1)c 
		//(2)��c��Ӧ(1)b
		//��ʱ�� a -- a  b -- c  c -- b
		//����printH(a, c);  a --> c
		//ʵ������ a �ƶ��� b
		//printf ��ʾ������ ��  A->B  ��ʱ num = 1;
		//���ʱ���ٴε��� hanoi(a, c, b, num - 1);
		//�ͱ���� 
		// a -- a
		// b -- b
		// c -- c
		//��ʱ���� printH(a, c); �ͱ���� a->c  �ַ���ʾ'A'->'C';
		printH(a, c);
		//�� b �ϵ����� ���� a �ƶ��� c
		//ͬ��
		// b -> c
		hanoi(b, a, c, num - 1);
	}
	
}

int main(int argc, char *argv[])
{
	int ret = 0;
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int num = 0;

	
	puts("������Ҫ��������:");
	scanf("%d", &num);

	hanoi(a, b, c, num);
	
	system("pause");
	return ret;
}