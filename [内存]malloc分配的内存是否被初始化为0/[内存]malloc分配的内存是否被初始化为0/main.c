#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = malloc(100);

	memset(p, 0, 100);

	system("pause");
	return 0;
}