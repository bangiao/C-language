#include <stdio.h>
#include <stdlib.h>


static union
{ 
	char c[4];
	unsigned long mylong;
} 

// l   === little endian  b ========= big endian
endian_test = { { 'l', '?', '?', 'b' } };

#define ENDIANNESS ((char)endian_test.mylong)

int main(void)
{
	printf("%c\n", ENDIANNESS);
	system("pause");
	return 0;
}