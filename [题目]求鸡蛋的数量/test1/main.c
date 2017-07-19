#include <stdio.h>
#include <stdlib.h>
// x 多少鸡蛋除以 2 有余数 可以被 3 7 9 整除, 这个多鸡蛋除以 4  余 1 除以 5 余 4 除以 6 余 3 处于 8 余 1 

//x 多少鸡蛋除以 2 有余数  == > 这个数字是单数 1 3 5 7 9 11 13 ........ (2 * n - 1)  n == INFINITE(无穷大)
//1. 单数
//可以被 3 7 9 整除
//1449
int main()
{
	//单数
	//每位数相加后的和为3的倍数
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
										printf("%d:%d\n", cnt, egg);		//无限个答案
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