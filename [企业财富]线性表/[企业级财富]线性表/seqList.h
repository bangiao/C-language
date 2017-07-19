#pragma once 

typedef void SeqList;
typedef void SeqListNode;

__declspec(dllexport)
SeqList *SeqList_Create(int capacity);

__declspec(dllexport)
int SeqList_Length(SeqList *list);

__declspec(dllexport)
int SeqList_Capacity(SeqList *list);

__declspec(dllexport)
int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);

__declspec(dllexport)
SeqListNode *SeqList_Get(SeqList *list, int pos);

__declspec(dllexport)
SeqListNode *SeqList_Delete(SeqList *list, int pos);

__declspec(dllexport)
int SeqList_Destory(SeqList *list);
