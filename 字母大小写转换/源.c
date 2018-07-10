#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
int input = 0;
while ((input = getchar()) != EOF)
{
	if ('a' <= input && input <= 'z')
	{
		printf("%c\n",input - 32);
		fflush(stdin);

	}
	else if('A' <= input&&input <= 'Z')
	{
		printf("%c\n",input + 32);
		fflush(stdin);
	}
	
	else
	{
		break;

	}
	printf("请输入大写或小写字母：\n");
}
getchar();
return 0;
}