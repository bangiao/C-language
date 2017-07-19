#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetString(char *String/*in*/, const char *StringFlag/*in*/);/*返回数量*/

void fun(int i);

//数组步长分析
//int a[2][3]
//这时 这里的  a 步长为3 代表了二级指针 a + 1 等于 &a[1]
//*a 的步长为1    *a + 1 等同于 &a[0][1]
//数组 a[2][3]可以表示为*(*(a + 1) + 2)
//推出 数组 &a[2][3] 等同于 (*(a + 1) + 2)
//本质
//本质上 a[0] 相当于 *(a + 0)
//a[1]  相当于 *(a + 1)

int a[2][3] = { 0 };

int main()
{
	int *p = NULL;
// 	int i, j;
	int ret = 0;

	int a = 10;

	fun(a);

// 	ret = GetString("1346271143454311", "1");
// 	if (-1 == ret)
// 	{
// 		return ret;
// 	}
// 
// 	printf("%d", ret);



// 	p = (*(a + 0) + 1);
// 	
// 	for (i = 0; i < 2; i++)
// 	{
// 		for (j = 0; j < 3; j++)
// 		{
// 			printf("a[%d][%d]的地址为:%p\n", i, j, &a[i][j]);
// 		}
// 	}
// 	puts(" - - - - - - - - - - - - - - - - - - - - ");
// 	printf("a[0]的地址%p\n", &a[0]);	//步长为1
// 	printf("*a的地址为%p\n", *a);//步长为1
// 	printf("a[1]的地址%p\n", &a[1]);//步长为1
// 	printf("a+1:的地址%p\n", a + 1);//步长为3
// 	printf("*a+1:的地址%p\n", *a + 1);//步长为1
	system("pause");
	return 0;
}


int GetString(char *String/*in*/, const char *StringFlag/*in*/)
{
	int ret = 0;
	char *p = NULL;
	int StringLen = 0;
	if (NULL == String || NULL == StringFlag)
	{
		ret = -1;
		printf("err line: %d, file:%d\n", __LINE__, __FILE__);
		return ret;
	}
	StringLen = strlen(StringFlag);
	while (1)
	{
		p = strstr(String, StringFlag);
		if (NULL == p)
		{
			break;
		}
		else
		{
			++ret;
		}
		String = p = p + StringLen;
	}
	return ret;
}

void fun(int i)
{
	if (i / 2 != 0)		//10   5  2  1
	{
		fun(i / 2);
	}
	printf("%d", i % 2);
}