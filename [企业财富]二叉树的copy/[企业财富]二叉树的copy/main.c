#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二叉树用递归是最好的方法
//二叉树的遍历方法有三种
//先序遍历
//中序遍历
//后序遍历

typedef struct _BitNode
{
	int data;						//数据结构
	struct _BitNode *lChild;		//左孩子
	struct _BitNode *rChild;		//右孩子
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
		printf("%d\n", T->data);	//先打印出头结点
		PreOrder(T->lChild);		//然后打印左节点
		PreOrder(T->rChild);		//再打印右节点
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

	//构建树的关系
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