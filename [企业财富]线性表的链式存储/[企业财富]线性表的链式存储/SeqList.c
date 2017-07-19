#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

//�ײ�ⲻ�ؿ����ϲ�Ӧ�õ����ݽṹ
//�ײ��ֻҪ���ϲ�Ӧ�����ݽṹ�ĵ�ַ���ڵײ��涨�����ݽṹ�о�����
typedef struct _tag_ListNode 
{
	LinuxList Node;
	int Length;
}TLinkLsit;

//����ͷ���
vSeqList *SeqList_Create()
{
	TLinkLsit *t_list = (TLinkLsit *)malloc(sizeof(TLinkLsit));
	if (NULL == t_list)
	{
		return NULL;
	}
	t_list->Node.pNext = NULL;//ͷ���
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
	Cur = (LinuxList *)list;		//Linux�ں�����ĺ���˼��
	if (NULL == t_list || NULL == node)
	{
		return -1;
	}
	for (int i = 0; i < pos; i++)
	{
		Cur = Cur->pNext;
	}
	//pos = 3����֮��Curָ����Ҫ�ĵ��ǰһ���� Ȼ��nodeҪ�����һ����
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