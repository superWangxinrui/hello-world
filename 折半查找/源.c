#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int binsearch(int key, int arr[],int n)
{
	int mid = 0;
	int left = 0;
	int right = n;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
			//break;
		}
	}

		return -1;


}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 18;
	int temp=sizeof(arr) / sizeof(arr[0]) ;
	int ret = binsearch(key, arr,temp);
	printf("%d", ret);

	
	
	getchar();
	return 0;
}