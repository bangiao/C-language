#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"

typedef struct _tag_SeqListNode 
{
	int capacity;//�涨�������Ա����󳤶�
	int Length;//�涨�������Ա�����ڳ���
	unsigned int *Date;//�����ϲ�Ӧ�õ����ݴ�ŵĵط�
}StructSeqList;

SeqList *SeqList_Create(int capacity)
{
	StructSeqList *tlist = NULL;
	tlist = (StructSeqList *)malloc(sizeof(StructSeqList) + sizeof(unsigned int ) * capacity);
	if (NULL == tlist)
	{
		return NULL;
	}
	tlist->Date = (unsigned int *)(tlist + 1);
	tlist->Length = 0;
	tlist->capacity = 0;
	return (SeqList *)tlist;
}

int SeqList_Length(SeqList *list)
{
	int ret = 0;
	StructSeqList *tlist = (StructSeqList *)list;
	if (NULL == tlist)
	{
		ret = -1;
		return ret;
	}
	return tlist->Length;
}

int SeqList_Capacity(SeqList *list)
{
	int ret = 0;
	StructSeqList *tlist = (StructSeqList *)list;
	if (NULL == tlist)
	{
		ret = -1;
		return ret;
	}
	return tlist->capacity;
}

//�ڵ�pos��λ�ò�������node
int SeqList_Insert(SeqList *list, SeqListNode *node, int pos)
{
	int ret = 0;
	StructSeqList *tlist = (StructSeqList *)list;
	if (NULL == tlist)
	{
		ret = -1;
		return ret;
	}
	if (0 < pos || pos > SeqList_Length(tlist))
	{
		ret = -1;
		return ret;
	}
	//��β��������pos��
	for (int i = SeqList_Length(tlist); i > pos; i--)
	{
		tlist->Date[i] = tlist->Date[i - 1];
	}
	//�����ݷŽ��ճ�����λ��
	tlist->Date[pos] = (unsigned int)node;
	tlist->Length++;
	return ret;
}

SeqListNode *SeqList_Get(SeqList *list, int pos)
{
	StructSeqList *tlist = (StructSeqList *)list;
	if (NULL == tlist)
	{
		return NULL;
	}
	return (SeqListNode *)tlist->Date[pos];
}

SeqListNode *SeqList_Delete(SeqList *list, int pos)
{
	StructSeqList *tlist = (StructSeqList *)list;
	if (NULL == tlist)
	{
		return NULL;
	}
	for (int i = pos + 1; i < tlist->Length; i++)
	{
		tlist->Date[i - 1] = tlist->Date[i];
	}
	tlist->Length--;
	return tlist->Date;
}

int SeqList_Destory(SeqList **list)
{
	StructSeqList *tlist = (StructSeqList *)*list;
	if (NULL == tlist)
	{
		return 1;
	}
	tlist->capacity = 0;
	tlist->Length = 0;
	tlist->Date = NULL;
	free(tlist);
	tlist = NULL;
	return 0;
}
