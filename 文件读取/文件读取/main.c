#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	char name[20];		//姓名，最多4个字符，加'\0'
	char sex[10];			//性别
	int age;			//年龄
	long Student_ID;	//学号
	char squad[20];   //班级
	float math;		//数学成绩
	float english;	//英语成绩
	float yuwen;	//语文成绩
	float totle_score;	//总成绩
}New_Student;

//学生成绩排名
void order()
{
	//int i;		//循环变量
	//char Temp;
	FILE* pf_order = NULL;		//打开临时文件的指针
	FILE* pf2_order = NULL;	//打开学生文件的指针
	char Str[_MAX_PATH] = { 0 };		//存储学生信息文件
	char TmpStr[_MAX_PATH] = { 0 };
	New_Student Student4;
	memset(&Student4, 0, sizeof(New_Student));

	//将路径下的所有文件都直接存入到一个txt文件内
	system("dir D:\\学生信息文件夹\\*. /b > D:\\学生信息文件夹\\排序临时文件.txt");

	pf_order = fopen("D:\\学生信息文件夹\\排序临时文件.txt", "r");	//打开保存着所有文件名的txt
	if (NULL == pf_order)
	{
		printf("未打开所需文件，请重试！\n");
	}

	while (!feof(pf_order))	//读取临时文件里的内容
	{
		fgets(Str, sizeof(Str), pf_order);
		int nLen = strlen(Str);
		memset(TmpStr, 0, sizeof(TmpStr));
		memcpy(TmpStr, Str, (nLen - 1) * sizeof(*Str));
		pf2_order = fopen(TmpStr, "wb+");
		if (NULL == pf2_order)	//可能是因为Str字符出中
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