#include <stdio.h>
#include <stdlib.h>
// 这里的 10 是字面量, 字面量是不存在内存的地址
// 这里的 "abcd" 是常量 常量区的常量存在内存的地址
int main(int argc, char *args[])
{
	printf("%p", &"abcd");
	//printf("%p", &10);
	system("pause");
	return 0;
}