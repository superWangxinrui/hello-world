#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
game()
{
	    char ret = 0;
		char board[ROW][COL] = { 0 };
		init_board(board, ROW, COL);//初始化二维数组
		print_board(board, ROW, COL);//打印棋盘
		do
		{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = check_win(board, ROW, COL);//人赢X 电脑赢O 平局p 继续j
		if (ret !='j')
		{
			break;
		}
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = check_win(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		
		//int ret = check_win(board, ROW, COL);
	} while (1);
		if (ret == 'X')
		{
			printf("玩家赢\n");
		}
		if (ret == 'O')
		{
			printf("电脑赢\n");
		}
		if (ret == 'p')
		{
			printf("平局\n");
		}


}
menu()
{
	printf("***********************\n");
	printf("*****1 开始 0 结束*****\n ");
	printf("***********************\n");
}
void test()
{
	srand((unsigned int)time(NULL));//以系统时间为种子生成随机数
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