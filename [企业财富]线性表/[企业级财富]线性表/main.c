#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqList.h"

#define ERR -1
#define OK 0

typedef struct _Teacher 
{
	char *name;
	int age;
}Teacher;

int mainOP()
{
	int ret = 0;
	SeqList *list = NULL;
	Teacher t1, t2, t3;
	int i = 0;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	list = SeqList_Create(10);
	if (NULL == list)
	{
		return ERR;
	}

	ret = SeqList_Length(list);
	if (-1 == ret)
	{
		return ERR;
	}

	ret = SeqList_Capacity(list);
	if (-1 == ret)
	{
		return ERR;
	}

	ret = SeqList_Insert(list, (SeqListNode *)&t1, 0);
	if (-1 == ret)
	{
		return ERR;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t2, 0);
	if (-1 == ret)
	{
		return ERR;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t3, 0);
	if (-1 == ret)
	{
		return ERR;
	}

	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* tmp = (Teacher *)SeqList_Get(list, i);
		if (NULL == tmp)
		{
			return ERR;
		}
		printf("%d\n", tmp->age);
	}

	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher* tmp = (Teacher *)SeqList_Get(list, i);
		if (NULL == tmp)
		{
			return ERR;
		}
		printf("%d\n", tmp->age);
	}

	ret = SeqList_Destory(list);
	return 0;
}

int main()
{
	int ret = 0;
	ret = mainOP();
	if (-1 == ret)
	{
		printf("func mainOP() err\n");
		system("pause");
		return ERR;
	}
	system("pause");
	return 0;
}