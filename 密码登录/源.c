#define _CRT_SECURE_NO_WARNINGS ch
#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
//编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。
//三次均错，则提示退出程序。
int main(){
	char arr[10] = { 0 };
	int count = 3;
	while (count--){
		printf("请输入密码：");
		scanf("%s", arr);
		if (0 == strcmp(arr, "123456")){
			printf("密码正确！登陆成功\n");
		}
		else{
			printf("您还有%d次机会\n", count);
		}
	}
	system("pause");

	return 0;
}