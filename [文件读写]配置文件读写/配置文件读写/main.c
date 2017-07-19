#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg_op.h"

int main(int argv, char *args[])
{
	char *pFileName = "D:/1.txt";
	char pKey[20] = {0};
	char pValue[1024] = {0};
	int pValueLen = 0;

	pValueLen = strlen(pValue);
	while (1)
	{
		puts(" ‰»ÎpKey: ");
		scanf("%s", &pKey);
		if (!strcmp("exit", pKey))
		{
			break;
		}
		puts(" ‰»ÎpValue: ");
		scanf("%s", &pValue);
		Cfg_Write_Data(pFileName, pKey, pValue);
	}
	printf("hello world...\n");
	system("pause");
	return 0;
}