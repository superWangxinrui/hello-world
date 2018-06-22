#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	
	int arr[100][100] = {0};
	int row = 6;
	for (int n = 0; n <row; n++)
	{//打印空格
		for (int i = 0; i < row-1 - n; i++)
		{
			printf(" ");
		}
		//打印数字
		for (int j = 0; j <= n ; j++)
		{
			printf("%3d", (arr[n][j] = (n == j || j == 0) ? 1: // 首尾置 1
				arr[n - 1][j] + arr[n - 1][j - 1])); // 使用上一行计算 
		}
		printf("\n");
	}
	getchar();
	return 0;
}