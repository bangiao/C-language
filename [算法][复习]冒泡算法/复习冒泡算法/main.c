#include <stdio.h>
#include <stdlib.h>

void printArray(int *pArray, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d\t", pArray[i]);
	}
	puts("");
}


//ÓÅ»¯°æµÄÃ°ÅÝÅÅÐò
void BubbleSort(int *pArray, int len)
{
	int i, j, tmp;

	int cnt = 0;

	int exchange = 1;


	for (i = 0; i < len - 1 && exchange; i++)
	{
		exchange = 0;
		for (j = 1; j < len; j++)
		{
			if (pArray[j] < pArray[j - 1])
			{
				tmp = pArray[j];
				pArray[j] = pArray[j - 1];
				pArray[j - 1] = tmp;
				exchange = 1;
			}
			cnt++;
			printf("%d:", cnt);
			for (int k = 0; k < len; k++)
			{
				printf("%d\t", pArray[k]);
			}
			puts("");
		}
	}
}
//ÖÕ¼¶ÓÅ»¯°æµÄÃ°ÅÝÅÅÐò
void AdvBubbleSort(int *pArray, int len)
{
	int i, j, tmp;

	int cnt = 0;

	int exchange = 1;


	for (i = 0; i < len - 1 && exchange; i++)
	{
		exchange = 0;
		for (j = len - 1; j > i; j--)
		{
			if (pArray[j] < pArray[j - 1])
			{
				tmp = pArray[j];
				pArray[j] = pArray[j - 1];
				pArray[j - 1] = tmp;
				exchange = 1;
			}
			cnt++;
			printf("%d:", cnt);
			for (int k = 0; k < len; k++)
			{
				printf("%d\t", pArray[k]);
			}
			puts("");
		}
	}
}

int main01()
{
	int a[] = { 100, 32, 45, 85, 64,
		96, 75, 25, 34, 80 };
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int i, j;
	int BufLen = sizeof(a) / sizeof(int);
	int tmp = 0;
	int cnt = 0;
	int exchange = 1;

	for (i = 0; i < BufLen && exchange; i++)
	{
		exchange = 0;
		for (j = BufLen - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				exchange = 1;
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
			cnt++;
		printf("%d:", cnt);
		for (int k = 0; k < BufLen; k++)
		{
			printf("%d  ", a[k]);
		}
		puts("");
		}
	}

	for (i = 0; i < BufLen; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int a[] = { 100, 32, 45, 85, 64,
		96, 75, 25, 34, 80 };
//	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int len = sizeof(a) / sizeof(int);
//	BubbleSort(a, len);		//100     96      85      80      75      64      45      34      32      25
	//72:25   32      34      45      64      75      80      85      96      100
	AdvBubbleSort(a, len);	//100     96      85      80      75      64      45      34      32      25
	//45:25   32      34      45      64      75      80      85      96      100
	printArray(a, len);
	system("pause");
	return ret;
}