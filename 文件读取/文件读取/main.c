#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];		//���������4���ַ�����'\0'
	char sex[10];			//�Ա�
	int age;			//����
	long Student_ID;	//ѧ��
	char squad[20];   //�༶
	float math;		//��ѧ�ɼ�
	float english;	//Ӣ��ɼ�
	float yuwen;	//���ĳɼ�
	float totle_score;	//�ܳɼ�
}New_Student;

//ѧ���ɼ�����
void order()
{
	//int i;		//ѭ������
	//char Temp;
	FILE* pf_order = NULL;		//����ʱ�ļ���ָ��
	FILE* pf2_order = NULL;	//��ѧ���ļ���ָ��
	char Str[_MAX_PATH] = { 0 };		//�洢ѧ����Ϣ�ļ�
	char TmpStr[_MAX_PATH] = { 0 };
	New_Student Student4;
	memset(&Student4, 0, sizeof(New_Student));

	//��·���µ������ļ���ֱ�Ӵ��뵽һ��txt�ļ���
	system("dir D:\\ѧ����Ϣ�ļ���\\*. /b > D:\\ѧ����Ϣ�ļ���\\������ʱ�ļ�.txt");

	pf_order = fopen("D:\\ѧ����Ϣ�ļ���\\������ʱ�ļ�.txt", "r");	//�򿪱����������ļ�����txt
	if (NULL == pf_order)
	{
		printf("δ�������ļ��������ԣ�\n");
	}

	while (!feof(pf_order))	//��ȡ��ʱ�ļ��������
	{
		fgets(Str, sizeof(Str), pf_order);
		int nLen = strlen(Str);
		memset(TmpStr, 0, sizeof(TmpStr));
		memcpy(TmpStr, Str, (nLen - 1) * sizeof(*Str));
		pf2_order = fopen(TmpStr, "wb+");
		if (NULL == pf2_order)	//��������ΪStr�ַ�����
		{
			continue;
		}
		fread(&(Student4), sizeof(Student4), 1, pf2_order);
		printf("student->nname = %s\n", (&Student4)->name);
		printf("student->totle = %.2f\n", (&Student4)->totle_score);
		if (NULL != pf2_order)
		{
			fclose(pf2_order);
			pf2_order = NULL;
		}
	}
	if (NULL != pf_order)
	{
		fclose(pf_order);
		pf_order = NULL;
	}
	return;
}

int main(void)
{
	order();
	system("pause");
	return 0;
}