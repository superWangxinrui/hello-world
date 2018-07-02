#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6

int search(int arr[3][3],int row,int col, int num)
{
	int x = 0;
	int y = col - 1;
	while ((x<row) && (y>0))
	{
		if (num > arr[x][y])
		{
			x++;
		}
		else if (num == arr[x][y])
		{
			return arr[x][y];
		}
		else if (num < arr[x][y])
		{
			y--;
		}
	}
	return -1;
}
int main()
{
	int arr[3][3] ={ { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 }};
	int ret=search(arr,3,3,3);
	printf("%d", ret);
	getchar();
	return 0;
}