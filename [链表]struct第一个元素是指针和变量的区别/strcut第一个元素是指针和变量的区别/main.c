#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//指针也是一种变量 - - - - 不过它存放的是地址罢了
typedef struct _LinuxNode
{
	struct LinuxNode *node;
}LinuxNode;

typedef struct _Teacher 
{
	LinuxNode *node;
	int age;
}Teacher;

typedef struct _People
{
	LinuxNode node;
	int age;
}People;

int main()
{
	Teacher t1;
	People p1;

	t1.age = 11;
	p1.age = 22;

	t1.node = NULL;

	printf("%p\n", &t1);
	printf("%p\n", &t1.node);

	printf("%p\n", &p1);
	printf("%p\n", &p1.node);
	system("pause");
	return 0;
}