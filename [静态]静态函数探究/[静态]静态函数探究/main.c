#include <stdio.h>
#include <stdlib.h>

static void Swap(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char *args[])
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);

	printf("a = %d\n", a);
	printf("a = %d\n", b);
	system("pause");
	return 0;
}