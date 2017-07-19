#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct _Teacher 
{
	LinuxList *node;
	char *name;
	int age;
}Teacher;

int mainOP()
{
	SeqList *list = NULL;
	int ret = 0;
	Teacher t1, t2, t3, t4, t5;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	puts("创建头结点...");
	list = SeqList_Create();
	puts("插入成功...");
	ret = SeqList_Insert(list, (SeqListDate *)&t1, SeqList_Length(list));
	ret = SeqList_Insert(list, (SeqListDate *)&t2, SeqList_Length(list));
	ret = SeqList_Insert(list, (SeqListDate *)&t3, SeqList_Length(list));
	ret = SeqList_Insert(list, (SeqListDate *)&t4, SeqList_Length(list));
	ret = SeqList_Insert(list, (SeqListDate *)&t5, SeqList_Length(list));
	
	ret = SeqList_Print(list);
	puts("排序...");
	ret = SeqList_Sort(list);

	ret = SeqList_Print(list);
	puts("逆置...");
	ret = SeqList_Inverte(list);
	
	ret = SeqList_Print(list);
	puts("修改...");
	ret = SeqList_Write(list, 2);

	ret = SeqList_Print(list);
	puts("删除...");
	ret = SeqList_Delete(list, 3);

	ret = SeqList_Print(list);

	for (int i = 0; i < 5; i++)
	{
		Teacher * tmp = (Teacher *)SeqList_Read(list, i);
		if (NULL == tmp)
		{
			return 0;
		}
		printf("%d\n", tmp->age);
	}
	return 0;
}

int main()
{
	mainOP();
	system("pause");
	return 0;
}