#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�������õݹ�����õķ���
//�������ı�������������
//�������
//�������
//�������

typedef struct _BitNode
{
	int data;						//���ݽṹ
	struct _BitNode *lChild;		//����
	struct _BitNode *rChild;		//�Һ���
}BitNode, *BitTree;

BitNode *CopyBitTree(BitNode *T)
{
	BitNode *NewNode = NULL, *newLptr = NULL, *newRptr = NULL;
	if (NULL == T)
	{
		return NULL;
	}
	if (NULL != T->lChild)
	{
		newLptr = CopyBitTree(T->lChild);
	}
	else
	{
		newLptr = NULL;
	}
	if (NULL != T->rChild)
	{
		newRptr = CopyBitTree(T->rChild);
	}
	else
	{
		newRptr = NULL;
	}
	NewNode = (BitNode *)malloc(sizeof(BitNode));
	if (NULL == NewNode)
	{
		return NULL;
	}
	NewNode->lChild = newLptr;
	NewNode->rChild = newRptr;
	NewNode->data = T->data;
	return NewNode;
}

void PreOrder(BitNode *T)
{
	if (T != NULL)
	{
		printf("%d\n", T->data);	//�ȴ�ӡ��ͷ���
		PreOrder(T->lChild);		//Ȼ���ӡ��ڵ�
		PreOrder(T->rChild);		//�ٴ�ӡ�ҽڵ�
	}
}

int main()
{
	BitNode a, b, c, d, e;
	BitNode *newTree = NULL;
	int num = 0;
	memset(&a, 0, sizeof(BitNode));
	memset(&b, 0, sizeof(BitNode));
	memset(&c, 0, sizeof(BitNode));
	memset(&d, 0, sizeof(BitNode));
	memset(&e, 0, sizeof(BitNode));
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;

	//�������Ĺ�ϵ
	a.lChild = &b;
	a.rChild = &c;
	b.lChild = &d;
	c.lChild = &e;
	newTree = CopyBitTree(&a);
	if (NULL == newTree)
	{
		return -1;
	}

	PreOrder(newTree);
	system("pause");
	return 0;
}