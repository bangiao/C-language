#include <stdio.h>
#include <stdlib.h>

typedef union MyUnion
{
	int a;
	char *pval;
	double d;
}MyUnion;

int main(void)
{
	MyUnion a;
	a.a = 10;

	printf("a.a = %d, a.pval = %p, a.d = %lf", a.a, a.pval, a.d);

	system("pause");
	return 0;
}