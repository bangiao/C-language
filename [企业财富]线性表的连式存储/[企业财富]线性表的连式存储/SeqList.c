#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct _tag_LinkList 
{
	LinuxList node;
	int Length;
}TLinkList;

//创建链表的头
SeqList *SeqList_Create()
{
	TLinkList *pList = (TLinkList *)malloc(sizeof(TLinkList));
	if (NULL == pList)
	{
		return NULL;
	}
	pList->Length = 0;
	pList->node.pNext = NULL;
	return (SeqList *)pList;
}
//排序链表的数据
int SeqList_Sort(SeqList *list)
{
	TLinkList *pList = (TLinkList *)list;
	LinuxList *Cur = NULL;
	Cur = (TLinkList *)list;
	if (NULL == pList)
	{
		return -1;
	}
	return 0;
}
//链表的逆置
int SeqList_Inverte(SeqList *list)
{
	return 0;
}
//链表的删除
int SeqList_Delete(SeqList *list, int pos)
{
	return 0;
}
//链表的打印
int SeqList_Print(SeqList *list)
{
	return 0;
}
//链表数据的修改
int SeqList_Write(SeqList *list, int pos)
{
	return 0;
}
//链表的插入
int SeqList_Insert(SeqList *list, SeqListDate *date, int pos)
{
	return 0;
}
//链表的长度
int SeqList_Length(SeqList *list)
{
	return 0;
}
//链表的读取
SeqListDate *SeqList_Read(SeqList *list, int pos)
{
	return NULL;
}
//链表的销毁
void SeqList_Destory(SeqList **list)
{
	return ;
}
