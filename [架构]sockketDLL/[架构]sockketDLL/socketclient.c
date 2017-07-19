#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
���涨����һ��socket�ͻ��˷��ͱ��Ľ��ܱ��ĵ�api�ӿ�
��д�����׽ӿ�api�ĵ��÷���
*/
typedef struct _tag_ 
{
	int num;
	char buf[10];
}_tag_;
/*
1 �Ȱѻ������ʵ�� �汾����
2 �ڴ�й¶���
3 ��־
4 �汾�Ż�
*/
//�����ײ�⣨�����ӿڣ����ṩ����һ�ֻ��� ��������ĳ�־���Ĳ��ԡ�

typedef int(*EncData)(unsigned char *inData, int inDatalen, unsigned char *outData, int *outDatalen);
typedef int(*DecData)(unsigned char *inData, int inDatalen, unsigned char *outData, int *outDatalen);

typedef struct _SCK_HANDLE {
	char		version[16];
	char		serverip[16];
	int		serverport;
	unsigned char *	buf ;
	int				buflen;
	EncData			pEncFunc;
	DecData			pDecFunc;
}SCK_HANDLE;

//���������ĺ����ĵ�ַ����
__declspec(dllexport)int
SetEncCallBackAddr(void *Handle, EncData CallBackFunc)
{
	SCK_HANDLE *DLLSckHandle = Handle;
	if (NULL == DLLSckHandle)
	{
		return -1;
	}
	DLLSckHandle->pEncFunc = CallBackFunc;
	return 0;
}

__declspec(dllexport)int
SetDecCallBackAddr(void *Handle, DecData CallBackFunc)
{
	SCK_HANDLE *DLLSckHandle = Handle;
	if (NULL == DLLSckHandle)
	{
		return -1;
	}
	DLLSckHandle->pDecFunc = CallBackFunc;
	return 0;
}

//�ͻ��˳�ʼ��
__declspec(dllexport)int
cltSocketInit(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;


	if (handle == NULL)
	{
		rv = -1;
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;
	sh->pDecFunc = NULL;
	sh->pEncFunc = NULL;
	sh->buf = NULL;
	sh->buflen = 0;
	//����
	*handle = sh;


	return rv;
}

//�ͻ��˷�����
__declspec(dllexport)int
cltSocketSend(void *handle, unsigned char *buf,  int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		return rv;
	}

	sh = (SCK_HANDLE *)handle;
	if (NULL == sh->buf)
		sh->buf = (unsigned char *)malloc(sizeof(char)*buflen + 1);
	if (sh->buf == NULL)
	{
		rv = -6;
		return rv;
	}
	if (NULL != sh->pEncFunc)
	{
		sh->pEncFunc(buf, buflen, sh->buf, &sh->buflen);
	}
	else
	{
		//�ѷ��͵ı������ݣ��洢 handle ������֮��
		memcpy(sh->buf, buf, buflen);
		sh->buflen = buflen;
	}
	return rv;
}
//�ͻ����ձ���
__declspec(dllexport)int
cltSocketRev(void *handle, unsigned char *buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		return rv;
	}
	if (buf == NULL)
	{
		rv = -6;
		return rv;
	}

	sh = (SCK_HANDLE *)handle;

	//��ֵ ���������е����ݣ�copy��buf�ռ���
	//֧�ֶ��ε��ã���һ�ε����󳤶� �ڶ��ε��ÿ��԰�����copy buf��
	if (NULL != sh->pDecFunc)
	{
		sh->pDecFunc(sh->buf, sh->buflen, buf, buflen);
	}
	else
	{
		memcpy(buf, sh->buf, sh->buflen);
		*buflen = sh->buflen;
	}

	return rv;
}
//�ͻ����ͷ���Դ
__declspec(dllexport)int
cltSocketDestory(void *handle)
{
	SCK_HANDLE *sh = NULL;
	sh = handle; 
	if (sh != NULL)
	{
		free(sh->buf);
		free(sh);
	}
	return 0;
}

/////////////////�ڶ���apiʵ��/////////////////////////////////////////////////


//�ͻ��˳�ʼ��
__declspec(dllexport)int
cltSocketInit2(void **handle) //5day after
{
	SCK_HANDLE		*sh = NULL;
	int				rv = 0;


	if (handle == NULL)
	{
		rv = -1;
		return rv;
	}
	//�����ڴ沢��ʼ��
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//��ֵ
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//����
	*handle = sh;


	return rv;
}

//�ͻ��˷�����
__declspec(dllexport)int
cltSocketSend2(void *handle, unsigned char *buf,  int buflen)
{
	int				rv = 0;
	SCK_HANDLE		*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		return rv;
	}
	if (buf == NULL || buflen<=0)
	{
		rv = -5;
		return rv;
	}

	sh = (SCK_HANDLE *)handle;
	sh->buf = (unsigned char *)malloc(sizeof(char)*buflen);
	if (sh->buf == NULL)
	{
		rv = -6;
		return rv;
	}

	//�ѷ��͵ı������ݣ��洢 handle ������֮��
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return rv;
}
//�ͻ����ձ���
__declspec(dllexport)int
cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
	int			rv = 0;
	SCK_HANDLE	*sh = NULL;

	if (handle == NULL)
	{
		rv = -4;
		return rv;
	}
	if (buflen == NULL)
	{
		rv = -5;
		return rv;
	}
	sh = (SCK_HANDLE *)handle;


	//�����ڴ����ݴ���
	*buf = (char *)malloc(sh->buflen);
	if (*buf == NULL)
	{
		rv = -6;
		return rv;
	}
	memcpy(*buf, sh->buf, sh->buflen);

	*buflen = sh->buflen;

	return rv;
}

__declspec(dllexport)int
cltSocketRev2_Free(unsigned char **buf)
{
	int rv = 0;
	unsigned char * tmp = *buf;
	if (buf == NULL)
	{
		rv = -7;
		return rv;
	}
	if (tmp != NULL)
	{
		free(tmp);
	}
	*buf = NULL;
	return 0;
}

//�ͻ����ͷ���Դ
__declspec(dllexport)int
cltSocketDestory2(void **handle)
{
	SCK_HANDLE *sh = NULL;
	sh = *handle; 
	if (sh != NULL)
	{
		free(sh->buf);
		free(sh);
	}
	*handle = NULL;
	return 0;
}


