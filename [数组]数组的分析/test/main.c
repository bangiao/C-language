#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetString(char *String/*in*/, const char *StringFlag/*in*/);/*��������*/

void fun(int i);

//���鲽������
//int a[2][3]
//��ʱ �����  a ����Ϊ3 �����˶���ָ�� a + 1 ���� &a[1]
//*a �Ĳ���Ϊ1    *a + 1 ��ͬ�� &a[0][1]
//���� a[2][3]���Ա�ʾΪ*(*(a + 1) + 2)
//�Ƴ� ���� &a[2][3] ��ͬ�� (*(a + 1) + 2)
//����
//������ a[0] �൱�� *(a + 0)
//a[1]  �൱�� *(a + 1)

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
// 			printf("a[%d][%d]�ĵ�ַΪ:%p\n", i, j, &a[i][j]);
// 		}
// 	}
// 	puts(" - - - - - - - - - - - - - - - - - - - - ");
// 	printf("a[0]�ĵ�ַ%p\n", &a[0]);	//����Ϊ1
// 	printf("*a�ĵ�ַΪ%p\n", *a);//����Ϊ1
// 	printf("a[1]�ĵ�ַ%p\n", &a[1]);//����Ϊ1
// 	printf("a+1:�ĵ�ַ%p\n", a + 1);//����Ϊ3
// 	printf("*a+1:�ĵ�ַ%p\n", *a + 1);//����Ϊ1
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