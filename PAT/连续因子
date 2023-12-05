一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2…31）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630

输出样例：
3
5*6*7

#include<stdio.h>
#include<math.h>
int main()
{
	
	long long num;
	scanf("%lld", &num);
	int n = 2;
	int sum = 0;
	int max = 0;
		int flag;
	while (n < sqrt(num))
	{
		long long num1 = num;
		sum = 0;
		for (int i = n; i <= sqrt(num); i++)
		{
			
			if (num1 % i == 0)
			{
				sum++;
				num1 /= i;
			}
			else
			{
				break;
			}
		}
		
		if (sum >max)
		{
			max = sum;
			flag = n;
		}
		n++;
	}
	if (max == 0)
		printf("1\n%lld\n", num);
	else
	{
		printf("%d\n", max);
		for (int i = 0; i < max; i++)
		{
			printf("%d",flag);
			flag++;
			if (i != max - 1)
				printf("*");
			else
				printf("\n");
		}
	}
	return 0;
}
