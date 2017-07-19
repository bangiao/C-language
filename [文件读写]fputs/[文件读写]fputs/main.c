#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char *args[])
{
	FILE *fp = NULL;
	char Array[1024] = { 0 };
	fp = fopen("D:/2.txt", "a+");
	if (NULL == fp)
	{
		return -1;
	}
	sprintf(Array, "%s = %s\n", "key3", "value3");
	fputs(Array, fp);
	fclose(fp);
	printf("hello world...\n");
	system("pause");
	return 0;
}