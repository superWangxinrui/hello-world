#define _CRT_SECURE_NO_WARNINGS 
//Çó1£¡+2£¡+.....+10!
#include<stdio.h>
int main()
{
	int ret = 1;
	int sum = 0; 
		for (int j = 1; j <=10; j++)
		{
			ret = ret*j;
			sum = sum + ret;
		}
		printf("%d", sum);
		getchar();
}