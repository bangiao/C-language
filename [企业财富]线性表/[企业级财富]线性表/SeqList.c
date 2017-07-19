#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"

typedef struct _tag_SeqListNode 
{
	int capacity;//规定的是线性表的最大长度
	int Length;//规定的是线性表的现在长度
	unsigned int *Date;//这是上层应用的数据存放的地方
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

//在第pos的位置插入数据node
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
	//从尾部遍历到pos处
	for (int i = SeqList_Length(tlist); i > pos; i--)
	{
		tlist->Date[i] = tlist->Date[i - 1];
	}
	//将数据放进空出来的位置
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
