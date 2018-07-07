#define _CRT_SECURE_NO_WARNINGS 
int leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	int year = 0;
	scanf("%d", &year);
	if (1 == leap_year(year))
	{
		printf("是闰年！");
	}
	else
		printf("不是闰年！");
	return 0;
}