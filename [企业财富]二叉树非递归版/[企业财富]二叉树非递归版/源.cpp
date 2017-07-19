#include <iostream>
#include <stack>

using namespace std;

typedef struct _BitNode
{
	int data;						//数据结构
	struct _BitNode *lChild;		//左孩子
	struct _BitNode *rChild;		//右孩子
}BitNode, *BitTree;

BitNode *GoFarLeft(BitNode * T, stack <BitNode *> &s)
{
	if (NULL == T)
	{
		return NULL;
	}
	while (T->lChild)
	{
		s.push(T);
		T = T->lChild;
	}
	return T;
}

void InOrder(BitNode * T)
{
	stack<BitNode *>s;
	BitNode *t = GoFarLeft(T, s);

	printf("%d", t->data);
	if (t->lChild)
	{
		t = GoFarLeft(T->lChild, s);
	}
	else if (!s.empty())
	{
		t = s.top();
		s.pop();
	}
	else
	{
		t = NULL;
	}
}

int main()
{
	BitNode a, b, c, d, e;
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
	InOrder(&a);
	system("pause");
	return 0;
}