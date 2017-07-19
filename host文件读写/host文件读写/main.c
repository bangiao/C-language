#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int FuncReplaceString(char *szDestStr, int nDestLen, char *szTargetStr, int nTargetLen)
{
	int ret = 0;
	if (NULL == szDestStr || NULL == szTargetStr || nDestLen <= 0 || nTargetLen <= 0)
	{
		ret = -1;
		printf("func FuncReplaceString() err, line:%d, file:%s\n", __LINE__, __FILE__);
		return ret;
	}



	return ret;
}

// 文件读取, 返回值 为1 时的时候就是成功 ,  返回负数的时候就是失败的意思

//参数: 文件地址  ,    文件地址的长度,  目标文本,   替换文本
int FuncFileSearch(char *szFileAddr, char *szDestTarget, int nTargetLen, char *szText)
{
	int ret = 0;
	if (NULL == szFileAddr || nTargetLen <= 0 || NULL == szDestTarget || NULL == szText)
	{
		ret = -1;
		printf("func FuncFileSearch() err line:%d, file:%s, ret = %d\n", __LINE__, __FILE__);
		return ret;
	}
	FILE *fp = fopen(szFileAddr, "r+");
	if (NULL == fp)
	{
		ret = -2;
		printf("func FuncFileSearch() err fopen() line:%d, file:%s, ret = %d\n", __LINE__, __FILE__);
		return ret;
	}
	char szTempText[1024];
	char *pTmp = NULL;
	while (!feof(fp))
	{
		memset(szTempText, 0, sizeof(szTempText));
		pTmp = fgets(szTempText, 1024, fp);
		if (NULL == pTmp)
		{
			ret = -3;
			printf("func FuncFileSearch() err line:%d, file:%s\n", __LINE__, __FILE__);
			return ret;
		}
		if (0 == memcmp(pTmp, szDestTarget, nTargetLen))
		{
			printf("find string\t\n");
			break;
		}
	}
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return 0;
}

int main(void)
{
		
	system("pause");
	return 0;
}