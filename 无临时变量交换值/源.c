#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("ÇëÊäÈëa,bµÄÖµ£º");
	scanf("%d%d",&a,&b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d\n", a);
	printf("%d", b);
	getchar();
	getchar();
}