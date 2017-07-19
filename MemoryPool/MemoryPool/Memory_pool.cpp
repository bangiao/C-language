#include "Memory_pool.h"
#include <iostream>

using namespace std;

int main(void)
{
	Pool p(8);
	p.alloc();
	int nNum = p.get_memory_used_mb();
	p.free_all_chunks();
	system("pause");
	return 0;
}