#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
void bubble_sort(char **arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (strcmp(arr[j],arr[j + 1])<0)
			{
				char *temp = NULL;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char * arr[] = { "abcde", "bcdef", "cdefg" ,"acb"};
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,len);
	for (int i = 0; i < len; i++)
	{
		printf("%s ", arr[i]);
	}
	getchar();
	return 0;
}