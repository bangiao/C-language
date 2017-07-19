#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "SeqList.h"

typedef struct _Teacher 
{
	char *name;
	int age;
}Teacher;

int mainOP()
{
	int ret = 0;
	Teacher t1, t2, t3;
	LinkStack *stack = NULL;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	stack = LinkStack_Create();
	if (NULL == stack)
	{
		return -1;
	}
	ret = LinkStack_Push(stack, (Teacher *)&t1);
	if (-1 == ret)
	{
		return ret;
	}
	ret = LinkStack_Push(stack, (Teacher *)&t2);
	if (-1 == ret)
	{
		return ret;
	}
	ret = LinkStack_Push(stack, (Teacher *)&t3);
	if (-1 == ret)
	{
		return ret;
	}
	ret = LinkStack_Size(stack);
	if (-1 == ret)
	{
		return ret;
	}
	printf("%d\n", ret);
	Teacher *tmp = LinkStack_Top(stack);
	if (NULL == tmp)
	{
		return -1;
	}
	LinkStack_Pop(stack);
	tmp = LinkStack_Top(stack);
	if (NULL == tmp)
	{
		return -1;
	}
	LinkStack_Pop(stack);
	tmp = LinkStack_Top(stack);
	if (NULL == tmp)
	{
		return -1;
	}
	LinkStack_Pop(stack);
	tmp = LinkStack_Top(stack);
	if (NULL == tmp)
	{
		return -1;
	}
	ret = LinkStack_Size(stack);
	if (-1 == ret)
	{
		return ret;
	}
	printf("%d\n", ret);
	LinkStack_Clear(stack);
	LinkStack_Destory(stack);
	return ret;
}

int main()
{


	system("pause");
	return 0;
}