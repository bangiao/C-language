#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6 }, i, j;

	for (i = 0; i < (5 - i); i++)		//ԭ����for (i = 0; i < 6; i++)
	{
		j = a[i];
		a[i] = a[5 - i];
		a[5 - i] = j;
	}

	for (i = 0; i < 6; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}

//�ܽ�: С���ŵ����ȼ����ڻ����ŵ����ȼ����� ��ִ��()�ڵĶ��� 
//Ȼ�� () �ڵĶ����Զ���Ϊ�ֽ� ���Զ��ź���ľ��ǽ��
// void main()
// {
// 	int a[3][2] = { (80, 1), (2, 3), (4, 5) };
// 	int *p = NULL;
// 	p = a[0];
// 	printf("%p\n", a[0]);
// 	printf("%d", p[0]);
// 	system("pause");
// }

// int main()
// {
// 	FILE *fp = NULL;
// 	int ct = 0;
// 	fp = fopen("c:\\a.txt", "r");
// 	if (NULL == fp)
// 	{
// 		puts("err");
// 		return -1;
// 	}
// 	while (!feof(fp))		//�ж��Ƿ��ļ��Ƿ��ȡ��� ��Ϸ���ֵ δ��Ϸ���0
// 	{
// 		printf("%c", fgetc(fp));
// 		++ct;
// 	}
// 	fclose(fp);
// 	printf("\n%d��\n", ct);
// 	system("pause");
// 	return 0;
// }
