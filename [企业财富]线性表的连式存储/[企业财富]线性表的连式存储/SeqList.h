#pragma once

//这是对数据类型的封装
//底层库不让上层应用知道我的函数类型
//底层库DLL可能给任何人用而且用到的有.h和.lib而.h会将函数的类型显示出来这个时候底层库不让使用的人
//知道函数的原型的类型所以使用自定义的类型
typedef void SeqList;		//用于存放链表的类型
typedef void SeqListDate;	//用于存放数据的数据类型

//这是Linux的链表
typedef struct _LinuxList
{
	struct _LinuxList *pNext;
}LinuxList;

//创建链表的头
SeqList *SeqList_Create();
//排序链表的数据
int SeqList_Sort(SeqList *list);
//链表的逆置
int SeqList_Inverte(SeqList *list);
//链表的删除
int SeqList_Delete(SeqList *list, int pos);
//链表的打印
int SeqList_Print(SeqList *list);
//链表数据的修改
int SeqList_Write(SeqList *list, int pos);
//链表的插入
int SeqList_Insert(SeqList *list, SeqListDate *date, int pos);
//链表的长度
int SeqList_Length(SeqList *list);
//链表的读取
SeqListDate *SeqList_Read(SeqList *list, int pos);
//链表的销毁
void SeqList_Destory(SeqList **list);
