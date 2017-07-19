#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

//底层库不必考虑上层应用的数据结构
//底层库只要将上层应用数据结构的地址放在底层库规定的数据结构中就行了
typedef struct _tag_ListNode 
{
	LinuxList Node;
	int Length;
}TLinkLsit;

//创建头结点
vSeqList *SeqList_Create()
{
	TLinkLsit *t_list = (TLinkLsit *)malloc(sizeof(TLinkLsit));
	if (NULL == t_list)
	{
		return NULL;
	}
	t_list->Node.pNext = NULL;//头结点
	t_list->Length = 0;
	return t_list;
}

int SeqList_Length(vSeqList *list)
{
	TLinkLsit *t_list = (TLinkLsit *)list;
	if (NULL == t_list)
	{
		return -1;
	}
	return t_list->Length;
}

int SeqList_Insert(vSeqList *list, LinuxList *node, int pos)
{
	TLinkLsit *t_list = (TLinkLsit *)list;
	LinuxList *Cur = NULL;
	Cur = (LinuxList *)list;		//Linux内核链表的核心思想
	if (NULL == t_list || NULL == node)
	{
		return -1;
	}
	for (int i = 0; i < pos; i++)
	{
		Cur = Cur->pNext;
	}
	//pos = 3走完之后Cur指向需要的点的前一个点 然后node要插入后一个点
	node->pNext = Cur->pNext;
	Cur->pNext = node;
	t_list->Length++;
	return 0;
}

vSeqListNode *SeqList_Get(vSeqList *list, int pos)
{
	TLinkLsit *t_list = (TLinkLsit *)list;
	LinuxList *Cur = NULL;
	Cur = (LinuxList *)list;
	if (NULL == t_list)
	{
		return NULL;
	}
	for (int i = 0; i < pos; i++)
	{
		Cur = Cur->pNext;
	}
	return (vSeqListNode *)Cur->pNext;
}

vSeqListNode *SeqList_Delete(vSeqList *list, int pos)
{
	TLinkLsit *t_list = (TLinkLsit *)list;
	LinuxList *Cur = NULL;
	LinuxList *Next = NULL;
	Next = (LinuxList *)list;
	Cur = Next->pNext;
	if (NULL == t_list)
	{
		return NULL;
	}
	if (NULL == Cur->pNext)
	{
		return NULL;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		Cur = Cur->pNext;
	}
	Next = Cur->pNext;

	Cur->pNext = Next->pNext;
	t_list->Length--;
	return (vSeqListNode *)list;
}

void SeqList_Destory(vSeqList **list)
{
	TLinkLsit *t_list = (TLinkLsit *)*list;
	if (NULL == t_list)
	{
		return;
	}
	t_list->Length = 0;
	free(t_list);
	t_list = NULL;
	return ;
}