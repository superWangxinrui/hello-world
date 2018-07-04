#define _CRT_SECURE_NO_WARNINGS 
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
#include<stdio.h>
#include<math.h>
int sum = 0;
int reverse_bit(unsigned int value)
{
	for (int i = 0; i < 32; i++)
	{
		sum=sum << 1;
		sum=((value >> i) & 1) | sum;
	}
	return sum;
}
int main()
{
	int ret=reverse_bit(25); 
	printf("%u", ret);
	getchar();
	return 0;
}