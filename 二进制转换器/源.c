#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void printf_eb(unsigned int value)
{
	int arr[32] = { 0 };
	int i = 0;
	while (value)
	{
		arr[i] = value % 2;
		i++;
		value = value / 2;
	}
	//printf("%d", i);
	for (int j=i-1; j >= 0; j--)
	{
		printf("%d", arr[j]);
	}
}
int main()
{
	unsigned int a = 0;
	scanf("%d", &a);
	printf_eb(a);
	getchar();
	getchar();


}