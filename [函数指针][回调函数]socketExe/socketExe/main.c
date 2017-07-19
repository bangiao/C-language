#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclientdll.h"

//���ܽ��ܺ���
//���������ܺ���
int EncDataIMP(const unsigned char *inData, const int inDataLen, unsigned char *outData, int *outDataLen)
{
	char str1[10] = "inData";
	inDataLen = strlen(str1) + 1;
	strncpy(outData, str1, inDataLen);
	*outDataLen = inDataLen;
	return 0;
}
//���������ܺ���
int DecDataIMP(const unsigned char *inData, const int inDataLen, unsigned char *outData, int *outDataLen)
{
	char str1[10] = "outData";
	*outDataLen = strlen(str1) + 1;
	strncpy(inData, str1, *outDataLen);
	*outDataLen = inDataLen;
	return 0;
}

int mainOP(void *handle, unsigned char *inbuf, int inbuflen, unsigned char *outbuf, int outbuflen)
{
	int ret = 0;
	ret = cltSocketInit(&handle /*out*/);
	ret = SetEncCallBackAddr(handle, EncDataIMP);		//��ǰ�������ĵ�ַ���͵��ײ���е�������
	ret = SetDecCallBackAddr(handle, DecDataIMP);		//��ǰ�������ĵ�ַ���͵��ײ���е�������

	//�ͻ��˷�����
	ret = cltSocketSend(handle /*in*/, inbuf /*in*/, inbuflen /*in*/);

	//�ͻ����ձ���
	ret = cltSocketRev(handle /*in*/, outbuf /*in*/, &outbuflen /*in out*/);

	//�ͻ����ͷ���Դ
	ret = cltSocketDestory(handle/*in*/);
	return ret;
}

int main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char inbuf[1024] = "aaaaaaa";
	int inbuflen = 5;
	unsigned char outbuf[1024];
	int outbuflen = 0;
	ret = mainOP(handle, inbuf, inbuflen, outbuf, outbuflen);
	if (-1 == ret)
	{
		return ret;
	}
	system("pause");
	return 0;
}