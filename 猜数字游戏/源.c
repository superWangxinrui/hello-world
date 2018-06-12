#define _CRT_SECURE_NO_WARNINGS ch
#include<stdio.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
void menu(){
	printf("***1.play  0,exit***\n");
}
void game(){
	int num = rand() % 101;
	//printf("%d\n",num);
	int gnum = 0;
	do{
		printf("please guess the num(1--100)：");
		scanf("%d", &gnum);
		if (gnum < num){
			printf("smaller\n");
		}
		else if (gnum>num){
			printf("bigger\n");
		}
		else{
			printf("congratutions!\n");
			break;
		}
	} while (1);
}
int main(){
	srand((unsigned)time(NULL));//1970-1-1-0-0-0到现在的时间差，种子采用time避免rand产生的随机数一样
	int input = 0;
	do{
		menu();
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("game over!");
			break;
		default:
			printf("the wrong number");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}