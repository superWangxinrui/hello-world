#define _CRT_SECURE_NO_WARNINGS 
//熟悉预处理标识符：
//__LINE__
//__FILE__
//__DATE__
//__TIMRE__
//# 
//## 
//#define PRINT fprintf(pf,"file=%s line=%d data=%s time=%s i=%d\n"\
//, __FILE__, __LINE__, __DATE__, __TIME__, i);
//#include<stdio.h>
//int main()
//{
//	FILE *pf = fopen("log.txt", "w");
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		PRINT;
//	}
//	fclose(pf);
//	getchar();
//	return 0;
//}
#define print(format,x) printf("the vale of "#x" is "format"\n",x);
#include<stdio.h>
int main()
{
	int a = 10;
	float f = 20.0f;
	print("%d",a);
	print("%f",f);
	getchar();
	return 0;
}
//#define cat(x,y) x##y
//#include<stdio.h>
//int main()
//{
//	int vai10 = 9;
//	printf("%d\n", cat(vai, 10));
//	getchar();
//	return 0;
//}
