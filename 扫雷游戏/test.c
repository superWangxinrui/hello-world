#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	INIT(mine, ROWS, COLS, '0');//将mine初始化为全0
	INIT(show, ROWS, COLS, '*');//将show初始化为*
	PRINT(show, ROW, COL);
	SET_MINE(mine, ROW, COL);//布雷
	PRINT(mine, ROW, COL);
	clear(mine,show, ROW, COL);//排雷
	PRINT(mine, ROW, COL);
}
menu()
{
	printf("***********************\n");
	printf("*****1 开始 0 结束*****\n ");
	printf("***********************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	fflush(stdin);//清空输入缓冲区
	getchar();
	return 0;
}