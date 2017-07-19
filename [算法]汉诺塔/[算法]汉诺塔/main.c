#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//汉诺塔
//最终目的:a --> c
static int flag = 0;
void printH(char a, char c)
{
	flag++;
	printf("%d:%c->%c\n", flag, a, c);
}

void hanoi(char a, char b, char c, int num)
{
	if (1 == num)
	{
		printH(a, c);
	}
	else
	{
		//将 a 上的盘子 借助 c 移动到 b
		hanoi(a, c, b, num - 1);
		//这个函数很好理解
		//当盘子只有一个的时候直接从 a 移动到 c-
		//当盘子多个的时候(假设两个), 看 (1) hanoi(a, c, b, num - 1); 这个调用  
		//这个时候 (2) void hanoi(char a, char b, char c, int num)
		//这上面的 a 对应 (1) 总的 a
		//(2)的b对应(1)c 
		//(2)的c对应(1)b
		//此时的 a -- a  b -- c  c -- b
		//函数printH(a, c);  a --> c
		//实质上是 a 移动到 b
		//printf 显示出来的 是  A->B  此时 num = 1;
		//这个时候再次调用 hanoi(a, c, b, num - 1);
		//就变成了 
		// a -- a
		// b -- b
		// c -- c
		//此时调用 printH(a, c); 就变成了 a->c  字符显示'A'->'C';
		printH(a, c);
		//将 b 上的盘子 借助 a 移动到 c
		//同理
		// b -> c
		hanoi(b, a, c, num - 1);
	}
	
}

int main(int argc, char *argv[])
{
	int ret = 0;
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int num = 0;

	
	puts("请问需要几个碟子:");
	scanf("%d", &num);

	hanoi(a, b, c, num);
	
	system("pause");
	return ret;
}