#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6 }, i, j;

	for (i = 0; i < (5 - i); i++)		//原题是for (i = 0; i < 6; i++)
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

//总结: 小括号的优先级大于花括号的优先级所以 先执行()内的东西 
//然后 () 内的东西以逗号为分界 所以逗号后面的就是结果
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
// 	while (!feof(fp))		//判断是否文件是否读取完毕 完毕返回值 未完毕返回0
// 	{
// 		printf("%c", fgetc(fp));
// 		++ct;
// 	}
// 	fclose(fp);
// 	printf("\n%d个\n", ct);
// 	system("pause");
// 	return 0;
// }
