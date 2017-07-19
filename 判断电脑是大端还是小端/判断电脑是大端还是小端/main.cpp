#include <iostream>
using namespace std;

int main(void)
{
	int a = 1;
	if (*(char *)&a == 1)
	{
		cout << "小端模式" << endl;
	}
	else
	{
		cout << "大端模式" << endl;
	}
	system("pause");
	return 0;
}