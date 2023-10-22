#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char chess[ROW][COL];
	char result = 0;
	init_chess(chess, ROW, COL); // 初始化棋子
	display_board(chess, ROW, COL); // 输出棋盘
	while (1)
	{
		user_play(chess, ROW, COL); // 用户下棋
		display_board(chess, ROW, COL); // 输出棋盘
		result = is_win(chess, ROW, COL); // 判断输赢
		if (result != 'C')
		{
			break;
		}
		computer_play(chess, ROW, COL); // 电脑下棋
		display_board(chess, ROW, COL); // 输出棋盘
		result = is_win(chess, ROW, COL); // 判断输赢
		if (result != 'C')
		{
			break;
		}
	}
	// 进行结果判断
	if (result == '#')
	{
		printf("玩家:user_paly胜利!!!\n");
	}
	else if (result == '*')
	{
		printf("电脑:computer_paly胜利!!!\n");
	}
	else
	{
		printf("玩家和电脑打成平局!!!\n");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		// 输出想选择菜单
		menu(); 
		printf("请选择:>\n");
		scanf("%d", &input);
		// 进行选择
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("退出游戏....\n");
			break;
		default :
			printf("输入错误,请重新输入!!!\n");
		}
	}while (input);

	return 0;
}