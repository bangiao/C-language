#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[10];

typedef int(Array10)[10];
typedef int(*pArray)[10];

int main()
{
	Array10 a1;
	a1[0] = 1;
	printf("%d\n", a1[0]);
	pArray a2 = &a1;
	(*a2)[0] = 2;
	printf("%d\n", (*a2)[0]);
	system("pause");
	return 0;
}