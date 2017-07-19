#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node
{
	struct list_node *p_next;
}list_node;

typedef struct Node
{
	list_node p_node;
	char buf[1024];
}Node;

typedef struct Dat 
{
	int (*Swap)(int a, int b);
	int a;
	int b;
}Dat;

int _mul(int a, int b)
{
	return a - b;
}

int _add(int a, int b)
{
	return a + b;
}

int main(int argc, char *args[])
{
	Node node;
	Dat dat;

	dat.Swap = _mul;
	dat.a = 10;
	dat.b = 20;

	node.p_node.p_next = &dat;
	memcpy(node.buf, "zhazha", strlen("zhazha") + 1);
	char *p_reference = &node;

	printf("p_reference = %p\n", p_reference);
	printf("&dat = %p\n", &dat);
	printf("&node = %p\n", &node);
	printf("&(node.p_node) = %p\n", &(node.p_node));
	printf("node.p_node.p_next = %p\n", node.p_node.p_next);

	// ´íÎó
// 	int num1 = ((Dat *)(p_reference))->Swap(dat.b, dat.a);
// 	printf("num1 = %d\n", num1);

	int num2 = ((Dat *)((*((Node *)(p_reference))).p_node.p_next))->Swap(dat.b, dat.a);
	printf("num2 = %d\n", num2);

	int num3 = ((Dat *)(node.p_node.p_next))->Swap(dat.b, dat.a);
	printf("num3 = %d\n", num3);

	int num4 = ((Dat *)(node.p_node.p_next))->Swap(dat.b, dat.a);
	printf("num4 = %d\n", num4);

	int num5 = ((Dat *)(((Node *)(p_reference))->p_node.p_next))->Swap(dat.b, dat.a);
	printf("num5 = %d\n", num5);

// 	int num6 = (((Node *)(p_reference))->p_node)
// 	printf("num6 = %d\n", num6);

	system("pause");
	return 0;
}