#define  _CRT_SECURE_NO_WARNINGS
#include "cfg_op.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Cfg_Write_Data(const char *pFileName, const char *pKey, const char *pValue)
{
	int ret = 0;
	char pLineBuf[4096] = { 0 };
	char pFileBuf[4096] = { 0 };
	FILE *fp = NULL;
	char *pRev = NULL;
	int FlagKey = 0;
	int Len = 0;
//	char tmpArray[1024] = { 0 };

	if (NULL == pFileName || NULL == pKey || NULL == pValue)
	{
		ret = -1;
		return ret;
	}
	fp = fopen(pFileName, "r+");
	if (NULL == fp)
	{
		printf("func Cfg_Write_Data() if (NULL == fp) line:%d, file:%s\n", __LINE__, __FILE__);
		return -2;
	}
	while (1)
	{

	}
	fseek(fp, 0L, 0);
	fprintf(fp, "%s", pFileBuf);
	fclose(fp);
	return ret;
}

int Cfg_Read_Data(const char *pFileName, const char *pKey, char *pValue)
{
	return 0;
}