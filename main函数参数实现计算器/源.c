#define _CRT_SECURE_NO_WARNINGS 
//使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“ - a”选项执行加法，
//“ - s”选项执行减法，“ - m”选项执行乘法，“ - d”选项执行除法，后面两个参数为操作数。
//
//例如：命令行参数输入：test.exe -a 1 2
//执行1 + 2输出3
#include <stdio.h>
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a -b;
}
int Mul(int a, int b)
{
	return a *b;
}
int Div(int a, int b)
{
	return a / b;
}
int main(int argc,char *argv[],char *envp[])
{
	if (argc != 4)
	{
		printf("参数错误\n");
		exit(1);
	}
	int ret = 0;
	switch (*(argv[1] + 1))
	{
	case 'a':
		 ret = Add(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 's':
		 ret = Sub(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 'm':
		 ret = Mul(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	case 'd':
		 ret = Div(atoi(argv[2]), atoi(argv[3]));
		 printf("%d", ret);
		break;
	}
	getchar();
	return 0;
}
