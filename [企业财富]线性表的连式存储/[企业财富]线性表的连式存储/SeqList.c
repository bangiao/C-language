#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct _tag_LinkList 
{
	LinuxList node;
	int Length;
}TLinkList;

//���������ͷ
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
//�������������
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
//���������
int SeqList_Inverte(SeqList *list)
{
	return 0;
}
//�����ɾ��
int SeqList_Delete(SeqList *list, int pos)
{
	return 0;
}
//����Ĵ�ӡ
int SeqList_Print(SeqList *list)
{
	return 0;
}
//�������ݵ��޸�
int SeqList_Write(SeqList *list, int pos)
{
	return 0;
}
//����Ĳ���
int SeqList_Insert(SeqList *list, SeqListDate *date, int pos)
{
	return 0;
}
//����ĳ���
int SeqList_Length(SeqList *list)
{
	return 0;
}
//����Ķ�ȡ
SeqListDate *SeqList_Read(SeqList *list, int pos)
{
	return NULL;
}
//���������
void SeqList_Destory(SeqList **list)
{
	return ;
}
