#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main01()
{
	char *str1 = "abcdefgh";
	char str2[1024];
	int str1Len = strlen(str1) + 1;
	int str2Len = 5;
	int bugLen = str1Len - str2Len;
	if (bugLen < 0)
	{
		bugLen = ~bugLen;
	}

	memcpy(str2, str1, str1Len);
	printf("%s\n", str2);
	memcpy(str2, str1 + bugLen, str2Len);
	printf("%s\n", str2);
	system("pause");
	return 0;
}

int main02()
{
	char *str1 = "abcdefgh";
	char *str2 = NULL;
	int str1Len = strlen(str1) + 1;
	int str2Len = 5;

	str2 = (char *)malloc(sizeof(char) * 1024);

	strcpy(str2, str1);


	printf("%s\n", str2);
	if (NULL != str2)
	{
		free(str2);
	}
	system("pause");
	return 0;
}

int main03()
{
	char *str1 = "abcdefgh";
	char *str2 = NULL;
	int str1Len = strlen(str1) + 1;
	int str2Len = 5;

	str2 = (char *)malloc(sizeof(char) * 1024);

	strncpy(str2, str1, str1Len);


	printf("%s\n", str2);
	if (NULL != str2)
	{
		free(str2);
	}
	system("pause");
	return 0;
}

int main()
{
	char *str1 = "abcdefgh";
	char *str2 = NULL;
	int str1Len = strlen(str1) + 1;
	int str2Len = 5;

	str2 = (char *)malloc(sizeof(char) * 1024);

	strcpy_s(str2, str1Len, str1);


	printf("%s\n", str2);
	if (NULL != str2)
	{
		free(str2);
	}
	system("pause");
	return 0;
}