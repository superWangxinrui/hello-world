#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void PrintInt(int n)
{
	if (n < 10)
		printf("%d", n);
	else
	{
		PrintInt(n / 10);
		printf("%d", n % 10);
	}
}
int main()
{
	PrintInt(123);
	getchar();
	return 0;
}