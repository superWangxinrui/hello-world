#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//判断为几位数
		int count = 1;
		int sum = 0;
		int temp = i;
		while (temp>9)
		{
			count++;
			temp = temp / 10;
		}
		//求每一位
		temp = i;
		while (temp)
		{
			sum+=_Pow_int(temp%10, count);
			temp = temp / 10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	getchar();
	return 0;
}