#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

int mainOP1()
{
	void *handle = NULL;
	int ret = 0;
	unsigned char *buf = "ÔüÔü";
	int buflen = strlen(buf) + 1;
	unsigned char buf1[32];
	int buf1len = 0;
	//socket init
	handle = socketclient_init();
	if (NULL == handle)
	{
		return -1;
	}

	//socket send
	ret = socketclient_send(handle, buf, buflen);
	if (-1 == ret)
	{
		return ret;
	}
	//socket rev
	ret = socketclient_rev(handle, buf1, &buf1len);
	if (-1 == ret)
	{
		return ret;
	}
	printf("%s\n", buf1);
	//socket free
	socketclient_destory(handle);
	return 0;
}

int mainOP2()
{
	void *handle = NULL;
	int ret = 0;
	unsigned char *buf = "ÔüÔü";
	int buflen = strlen(buf) + 1;
	unsigned char *buf1 = NULL;
	int buf1len = 0;

	//socket init
	ret = socketclient_init2(&handle);
	if (-1 == ret)
	{
		return -1;
	}

	//socket send
	ret = socketclient_send2(handle, buf, buflen);
	if (-1 == ret)
	{
		return ret;
	}
	//socket rev
	ret = socketclient_rev2(handle, &buf1, &buf1len);
	if (-1 == ret)
	{
		return ret;
	}
	printf("%s\n", buf1);
	//socket free
	socketclient_destory2(&handle);
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	ret = mainOP1();
	if (-1 == ret)
	{
		return -1;
	}
	ret = mainOP2();
	if (-1 == ret)
	{
		return -1;
	}
	system("pause");
	return 0;
}
