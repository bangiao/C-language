#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

#define OK 0
#define ERR -1

typedef struct _tag_SockData
{
	unsigned char *Data;
	int DataLen;
}TSockData;

//socket init
void *socketclient_init()
{
	TSockData *THandle = NULL;
	THandle = malloc(sizeof(TSockData));
	if (NULL == THandle)
	{
		printf("func socketclient_init() if (NULL == THandle) line: %d, file: %d \n", __LINE__, __FILE__);
		return NULL;
	}
	memset(THandle, 0, sizeof(TSockData));
	return THandle;
}

//socket send
int socketclient_send(void *handle, unsigned char *buf, int buflen)
{
	TSockData *THandle = NULL;
	if (NULL == handle || NULL == buf || 0 == buflen)
	{
		printf("func socketclient_send() line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	THandle = handle;
	if (NULL != THandle->Data)
	{
		THandle->DataLen = 0;
		free(THandle->Data);
	}
	THandle->Data = malloc(sizeof(char) * buflen);
	if (NULL == THandle->Data)
	{
		printf("func socketclient_send () if (NULL == THandle->Data) line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	memset(THandle->Data, 0, sizeof(char) * buflen);
	THandle->DataLen = buflen;
	memcpy(THandle->Data, buf, buflen);
	if (NULL == THandle->Data)
	{
		printf("func socketclient_send() NULL == THandle->Data line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	return OK;
}

//socket rev
int socketclient_rev(void *handle, unsigned char *buf, int *buflen)
{
	TSockData *THandle = NULL;
	if (NULL == handle || NULL == buflen)
	{
		printf("func socketclient_rev() line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	THandle = handle;
	*buflen = THandle->DataLen;
	memcpy(buf, THandle->Data, THandle->DataLen);
	return 0;
}

//socket free
void socketclient_destory(void *handle)
{
	TSockData *THandle = NULL;
	THandle = handle;
	if (NULL != THandle->Data)
	{
		THandle->DataLen = 0;
		free(THandle->Data);
	}
	if (NULL != THandle)
	{
		free(THandle);
	}
	return ;
}




//socket init
int socketclient_init2(void **Handle)
{
	TSockData *THandle = NULL;
	THandle = malloc(sizeof(TSockData));
	if (NULL == THandle)
	{
		printf("func socketclient_init2() if (NULL == THandle) line: %d, file: %d \n", __LINE__, __FILE__);
		return 0;
	}
	memset(THandle, 0, sizeof(TSockData));
	*Handle = THandle;
	return 0;
}

//socket send
int socketclient_send2(void *handle, unsigned char *buf, int buflen)
{
	TSockData *THandle = NULL;
	if (NULL == handle || NULL == buf || 0 == buflen)
	{
		printf("func socketclient_send2() line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	THandle = handle;
	if (NULL != THandle->Data)
	{
		THandle->DataLen = 0;
		free(THandle->Data);
	}
	THandle->Data = malloc(sizeof(char) * buflen);
	if (NULL == THandle->Data)
	{
		printf("func socketclient_send2() if (NULL == THandle->Data) line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	memset(THandle->Data, 0, sizeof(char) * buflen);
	THandle->DataLen = buflen;
	memcpy(THandle->Data, buf, buflen);
	if (NULL == THandle->Data)
	{
		printf("func socketclient_send2() NULL == THandle->Data line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	return OK;
}

//socket rev
int socketclient_rev2(void *handle, unsigned char **buf, int *buflen)
{
	TSockData *THandle = NULL;
	unsigned char *Tbuf = NULL;
	if (NULL == handle || NULL == buflen)
	{
		printf("func socketclient_rev2() line: %d, file: %d \n", __LINE__, __FILE__);
		return ERR;
	}
	THandle = handle;
	Tbuf = malloc(sizeof(char) * THandle->DataLen);
	if (NULL == Tbuf)
	{
		printf("func socketclient_rev2() Tbuf = malloc(sizeof(char) * THandle->DataLen) line: %d, file: %d \n", __LINE__, __FILE__);
		return -1;
	}
	THandle = handle;
	*buflen = THandle->DataLen;
	memcpy(Tbuf, THandle->Data, THandle->DataLen);
	*buf = Tbuf;
	return 0;
}

//socket free
void socketclient_destory2(void **handle)
{
	TSockData *THandle = NULL;
	THandle = *handle;
	if (NULL == handle)
	{
		return;
	}
	THandle->DataLen = 0;
	free(THandle->Data);
	THandle->Data = NULL;
	free(*handle);
	*handle = NULL;
}
