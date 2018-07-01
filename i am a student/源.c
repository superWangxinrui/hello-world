#define _CRT_SECURE_NO_WARNINGS 
//有一个字符数组的内容为 : "student a am i", 请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
//
#include<stdio.h>
#include<string.h>
#include<assert.h>
void reserve(char*left,char*right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left< right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void reserve_all(char*p)
{
	int len = strlen(p);
	reserve(p,p+len-1);//逆序字符串
	while (*p!='\0')
	{
		char* end = p;
		char* start = p;
		while ((*end != ' ') && (*end != '\0'))
		{
			end++;
		}
		reserve(start, end-1);
		if (*end == ' ')
			p = end + 1;
		/*else
			p = end;*/
	}

}
int main()
{
	char arr[] = "student a am i";
	reserve_all(arr);
	printf("%s", arr);
	getchar();
	return 0;
}