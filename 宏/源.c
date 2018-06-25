#define _CRT_SECURE_NO_WARNINGS
//5.写一个宏可以将一个数字的奇数位和偶数位交换。
//6.使用宏实现两个数中求较大值。

#include<stdio.h>
//#define MAX(x,y) x > y ? x : y
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a, b);
//	printf("%d", max);
//	getchar();
//	return 0;
//}
#define CHANGE(m) ((a & 0xaaaaaaaa)>>1) |((a & 0x5555555555)<<1)
int main()
{
	int a = 10;
	int b = CHANGE(a);
	printf("%d", b);
	getchar();
	return 0;
}