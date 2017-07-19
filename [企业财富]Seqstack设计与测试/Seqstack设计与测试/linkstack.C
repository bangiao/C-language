#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "SeqList.h"


typedef struct _Teacher
{
	LinuxList node;
	void *item;
}Teacher;

typedef struct LinkListNode 
{

};

LinkStack *LinkStack_Create()
{
	return SeqList_Create();
}

void LinkStack_Destory(LinkStack *stack)
{
	return ;
}

void LinkStack_Clear(LinkStack *stack)
{
	return ;
}

int LinkStack_Push(LinkStack *stack, void *item)
{
	int ret = 0;
	Teacher *t1 = (Teacher *)malloc(sizeof(Teacher));
	if (NULL == t1)
	{
		return -1;
	}
	ret = SeqList_Insert(stack, (LinuxList *)t1, 0);
	if (-1 == ret)
	{
		free(t1);
	}
	return 0;
}

void *LinkStack_Pop(LinkStack *stack)
{
	SeqList_Delete(stack, 0);
	return NULL;
}

void *LinkStack_Top(LinkStack *stack)
{
	return NULL;
}

int LinkStack_Size(LinkStack *stack)
{
	return 0;
}