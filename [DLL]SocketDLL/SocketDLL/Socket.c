#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Socket.h"

#define PASSWORD 4096

typedef struct _tag_SockDLL
{
	unsigned char *Data;
	int DataLen;
	EncDataFunc Enc;
	DecDataFunc Dec;
}TSockDLL;

int Socket_SetEnc(void *Handle, EncDataFunc Enc, DecDataFunc Dec)
{
	TSockDLL *SocketData = NULL;
	if (NULL == Enc || NULL == Dec)
	{
		return -1;
	}
	SocketData = Handle;
	SocketData->Enc = Enc;
	SocketData->Dec = Dec;
	return 0;
}

int Socket_Init(void **Handle)
{
	if (NULL == Handle)
	{
		return -1;
	}
	TSockDLL *SocketData = malloc(sizeof(TSockDLL));
	if (NULL == SocketData)
	{
		return -1;
	}
	SocketData->Data = NULL;
	SocketData->DataLen = 0;
	*Handle = SocketData;
	return 0;
}

int Socket_Send(void *Handle, unsigned char *inData, int inLen)
{
	TSockDLL *SocketData = NULL;
	unsigned char Tmp_Data[4096];
	int Tmp_Len = 0;
	if (NULL == Handle || NULL == inData || 0 >= inLen)
	{
		return -1;
	}
	SocketData = Handle;
	if (NULL != SocketData->Data)
	{
		free(SocketData->Data);
		SocketData->Data = NULL;
	}
	SocketData->Data = malloc(sizeof(unsigned char) * PASSWORD);
	if (NULL == SocketData->Data)
	{
		return -1;
	}
	memset(SocketData->Data, 0, sizeof(unsigned char) * PASSWORD);
	if (NULL != SocketData->Enc)
	{
		SocketData->Enc(inData, inLen, Tmp_Data, &Tmp_Len);
		memcpy(SocketData->Data, Tmp_Data, Tmp_Len);
		SocketData->DataLen = Tmp_Len;
	}
	else
	{
		memcpy(SocketData->Data, inData, inLen);
		SocketData->DataLen = inLen;
	}
	return 0;
}

int Socket_Res(void *Handle, unsigned char *outData, int *outLen)
{
	TSockDLL *SocketData = NULL;
	if (NULL == Handle || NULL == outData || NULL == outLen)
	{
		return -1;
	}
	SocketData = Handle;
	memset(outData, 0, sizeof(unsigned char) * SocketData->DataLen);
	if (NULL != SocketData->Dec)
	{
		SocketData->Dec(SocketData->Data, SocketData->DataLen, outData, outLen);
	}
	else
	{
		memcpy(outData, SocketData->Data, sizeof(unsigned char) * SocketData->DataLen);
		*outLen = SocketData->DataLen;
	}
	return 0;
}

void Socket_Destory(void **Handle)
{
	TSockDLL *SocketData = NULL;
	if (NULL == Handle)
	{
		return;
	}
	SocketData = *Handle;
	if (NULL != SocketData->Data)
	{
		free(SocketData->Data);
		SocketData->Data = NULL;
	}
	if (NULL != SocketData)
	{
		free(SocketData);
		*Handle = NULL;
	}

	return;
}