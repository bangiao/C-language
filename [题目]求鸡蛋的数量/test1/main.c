#include <stdio.h>
#include <stdlib.h>
// x ���ټ������� 2 ������ ���Ա� 3 7 9 ����, ����༦������ 4  �� 1 ���� 5 �� 4 ���� 6 �� 3 ���� 8 �� 1 

//x ���ټ������� 2 ������  == > ��������ǵ��� 1 3 5 7 9 11 13 ........ (2 * n - 1)  n == INFINITE(�����)
//1. ����
//���Ա� 3 7 9 ����
//1449
int main()
{
	//����
	//ÿλ����Ӻ�ĺ�Ϊ3�ı���
	int egg = 0;
	int tmp = 0;
	int cnt = 0;
	for (egg = 0; egg < INT_MAX; egg++)
	{
		if (egg % 2)
		{
			if (!(egg % 3))
			{
				if (!(egg % 7))
				{
					if (!(egg % 9))
					{
						if ((tmp = (egg % 4)) == 1)
						{
							if ((tmp = (egg % 5)) == 4)
							{
								if ((tmp = (egg % 6)) == 3)
								{
									if ((tmp = (egg % 8)) == 1)
									{
										cnt++;
										printf("%d:%d\n", cnt, egg);		//���޸���
										system("pause");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}