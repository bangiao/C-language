#include <iostream>
using namespace std;

int main(void)
{
	int a = 1;
	if (*(char *)&a == 1)
	{
		cout << "С��ģʽ" << endl;
	}
	else
	{
		cout << "���ģʽ" << endl;
	}
	system("pause");
	return 0;
}