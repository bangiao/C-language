#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct _Teacher 
{
	LinuxList *node;
	char *name;
	int age;
}Teacher;

int mainOP(int *list, Teacher *node, int pos)
{
	int ret = 0;

	ret = SeqList_Insert(list, (LinuxList *)node, pos);

	for (int i = 0; i < pos + 1; i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		if (NULL == tmp)
		{
			return -1;
		}
		printf("%d\n", tmp->age);
	}
	puts("mainOP()");
	return 0;
}

int main()
{
	int *list = NULL;
	int ret = 0;
	Teacher t1, t2, t3;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	list = SeqList_Create();
	if (NULL == list)
	{
		return -1;
	}
	ret = mainOP(list, &t1, SeqList_Length(list));
	if (-1 == ret)
	{
		return ret;
	}
	ret = mainOP(list, &t2, SeqList_Length(list));
	if (-1 == ret)
	{
		return ret;
	}
	ret = mainOP(list, &t3, SeqList_Length(list));
	if (-1 == ret)
	{
		return ret;
	}

	SeqList_Destory(&list);
	system("pause");
	return 0;
}