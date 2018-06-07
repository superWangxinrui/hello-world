#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//循环实现菲波那切数列
//int fib(int n)
//{
//	int first = 1;
//	int second = 1;
//	int third = first;
//	while (n>2)
//	{
//		third = first + second;
//		first = second;
//		second = third;
//		n--;
//	}
//	return third;
//}


//递归实现菲波那切数列
//int fib(n)
//{
//	if (n <= 2)
//		return 1;
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 7;
//	int ret=fib(n);
//	printf("%d", ret);
//	getchar();
//	return 0;
//
//}
