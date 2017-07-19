#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclientdll.h"

//加密解密函数
//第三方加密函数
int EncDataIMP(const unsigned char *inData, const int inDataLen, unsigned char *outData, int *outDataLen)
{
	char str1[10] = "inData";
	inDataLen = strlen(str1) + 1;
	strncpy(outData, str1, inDataLen);
	*outDataLen = inDataLen;
	return 0;
}
//第三方解密函数
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
	ret = SetEncCallBackAddr(handle, EncDataIMP);		//提前将函数的地址发送到底层库中的属性中
	ret = SetDecCallBackAddr(handle, DecDataIMP);		//提前将函数的地址发送到底层库中的属性中

	//客户端发报文
	ret = cltSocketSend(handle /*in*/, inbuf /*in*/, inbuflen /*in*/);

	//客户端收报文
	ret = cltSocketRev(handle /*in*/, outbuf /*in*/, &outbuflen /*in out*/);

	//客户端释放资源
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