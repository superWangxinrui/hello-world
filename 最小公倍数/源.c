#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int j = m*n;
	while (m%n)
	{
		int temp = m%n;
		m = n;
		n = temp;


	}
	printf("%d", (j/n));
	getchar();
	getchar();
	return 0;
}