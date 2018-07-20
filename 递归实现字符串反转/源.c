#define _CRT_SECURE_NO_WARNINGS 
//编写一个函数reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中
//的字符串操作函数。
char* reverse_string(char * string)
{
	int len = strlen(string);
	char temp = *(string);
	*(string) = *(string + len - 1);
	*(string + len - 1) = '\0';
	if (strlen(string)> 1)
		reverse_string(string + 1);
	*(string + len - 1) = temp;
}
#include<stdio.h>
int main()
{
	char arr[100] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);
	getchar();
	return 0;
}
