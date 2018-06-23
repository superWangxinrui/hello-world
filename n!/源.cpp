#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//非递归实现
//int jc(int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret*i;
//	}
//	return ret;
//}
////递归实现
int jc(int n)
{
	if (n == 1)
		return n;
	else
	return n*jc(n - 1);
}
int main()
{
	int ret = jc(3);
	printf("%d", ret);
	getchar();
	return 0;
}