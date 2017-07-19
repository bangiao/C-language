#pragma once

typedef void vSeqList;
typedef void vSeqListNode;

//Linux ÏµÍ³Á´±í
__declspec(dllexport)
typedef struct _tag_LinuxList
{
	struct _tag_LinuxList *pNext;
}LinuxList;

__declspec(dllexport)
vSeqList *SeqList_Create();

__declspec(dllexport)
int SeqList_Length(vSeqList *list);

__declspec(dllexport)
int SeqList_Insert(vSeqList *list, LinuxList *node, int pos);

__declspec(dllexport)
vSeqListNode *SeqList_Get(vSeqList *list, int pos);

__declspec(dllexport)
vSeqListNode *SeqList_Delete(vSeqList *list, int pos);

__declspec(dllexport)
void SeqList_Destory(vSeqList *list);
