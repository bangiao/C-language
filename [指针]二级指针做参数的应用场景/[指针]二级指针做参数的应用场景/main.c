#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char **p)
{
	char *ip1 = *p;
	ip1 = "127.0.0.0";	// 这里让指针重新指向一个新的值
	*p = "127.0.0.1";	// 这里让主函数里面的指针指向新的值
}

int main(void)
{
	char *ip = NULL;
	func(&ip);
	printf("ip = %s\n", ip);
	system("pause");
	return 0;
}