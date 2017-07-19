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

// �ļ���ȡ, ����ֵ Ϊ1 ʱ��ʱ����ǳɹ� ,  ���ظ�����ʱ�����ʧ�ܵ���˼

//����: �ļ���ַ  ,    �ļ���ַ�ĳ���,  Ŀ���ı�,   �滻�ı�
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