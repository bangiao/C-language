#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
下面定义了一套socket客户端发送报文接受报文的api接口
请写出这套接口api的调用方法
*/
typedef struct _tag_ 
{
	int num;
	char buf[10];
}_tag_;
/*
1 先把基本框架实现 版本管理
2 内存泄露检查
3 日志
4 版本优化
*/
//开发底层库（开发接口），提供的是一种机制 ，而不是某种具体的策略。

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

//将第三方的函数的地址传入
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

//客户端初始化
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
	//分配内存并初始化
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//域赋值
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;
	sh->pDecFunc = NULL;
	sh->pEncFunc = NULL;
	sh->buf = NULL;
	sh->buflen = 0;
	//传出
	*handle = sh;


	return rv;
}

//客户端发报文
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
		//把发送的报文数据，存储 handle 上下文之中
		memcpy(sh->buf, buf, buflen);
		sh->buflen = buflen;
	}
	return rv;
}
//客户端收报文
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

	//赋值 把上下文中的数据，copy到buf空间中
	//支持二次调用，第一次调用求长度 第二次调用可以把数据copy buf中
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
//客户端释放资源
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

/////////////////第二套api实现/////////////////////////////////////////////////


//客户端初始化
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
	//分配内存并初始化
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		rv = -2;
		return rv;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));

	//域赋值
	strcpy(sh->version, "0.0.1");
	strcpy(sh->serverip, "192.168.0.211");
	sh->serverport = 8888;

	//传出
	*handle = sh;


	return rv;
}

//客户端发报文
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

	//把发送的报文数据，存储 handle 上下文之中
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return rv;
}
//客户端收报文
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


	//分配内存数据传出
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

//客户端释放资源
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


