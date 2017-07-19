#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[32];
//	fprintf(stdout, "aaa");
//	sprintf(a, "abcde");
	sprintf_s(a, 6, "aaaaa");
	printf("%s\n", a);
	system("pause");
	return 0;
}