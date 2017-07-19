#pragma once

typedef void vSeqList;
typedef void vSeqListNode;

//Linux ÏµÍ³Á´±í
typedef struct _tag_LinuxList
{
	struct _tag_LinuxList *pNext;
}LinuxList;

vSeqList *SeqList_Create();

int SeqList_Length(vSeqList *list);

int SeqList_Insert(vSeqList *list, LinuxList *node, int pos);

vSeqListNode *SeqList_Get(vSeqList *list, int pos);

vSeqListNode *SeqList_Delete(vSeqList *list, int pos);

void SeqList_Destory(vSeqList *list);
