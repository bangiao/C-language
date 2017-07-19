#pragma once

//���Ƕ��������͵ķ�װ
//�ײ�ⲻ���ϲ�Ӧ��֪���ҵĺ�������
//�ײ��DLL���ܸ��κ����ö����õ�����.h��.lib��.h�Ὣ������������ʾ�������ʱ��ײ�ⲻ��ʹ�õ���
//֪��������ԭ�͵���������ʹ���Զ��������
typedef void SeqList;		//���ڴ�����������
typedef void SeqListDate;	//���ڴ�����ݵ���������

//����Linux������
typedef struct _LinuxList
{
	struct _LinuxList *pNext;
}LinuxList;

//���������ͷ
SeqList *SeqList_Create();
//�������������
int SeqList_Sort(SeqList *list);
//���������
int SeqList_Inverte(SeqList *list);
//�����ɾ��
int SeqList_Delete(SeqList *list, int pos);
//����Ĵ�ӡ
int SeqList_Print(SeqList *list);
//�������ݵ��޸�
int SeqList_Write(SeqList *list, int pos);
//����Ĳ���
int SeqList_Insert(SeqList *list, SeqListDate *date, int pos);
//����ĳ���
int SeqList_Length(SeqList *list);
//����Ķ�ȡ
SeqListDate *SeqList_Read(SeqList *list, int pos);
//���������
void SeqList_Destory(SeqList **list);
