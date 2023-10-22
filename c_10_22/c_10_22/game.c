#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// 输出选择菜单
void menu()
{
	printf("******************************\n");
	printf("*********   1.paly   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}

// 初始化棋子
void init_chess(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			chess[i][j] = ' ';
		}
	}
}

// 输出棋盘
void display_board(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	// 输出表格
	for (i = 0; i < row; i++)
	{
		// 输出数据
		int j = 0;
		for (j = 0; j < row; j++)
		{
			printf(" %c ", chess[i][j]);
			// 输出|
			if (j < row - 1)
			{
				printf("|");
			}
		}
		// 输出完一行换行
		printf("\n");

		// 在其中间输出分割线 -- 只输出两行
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			// 输出完一行换行
			printf("\n");
		}
	}
}

// 用户下棋
void user_play(char chess[ROW][COL], int row, int col)
{
	printf("用户请下棋:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		// 下棋位置判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (chess[x - 1][y - 1] != ' ')
			{
				printf("位置已有棋子,请重新输入...\n");
			}
			else
			{
				chess[x - 1][y - 1] = '#';
				break;
			}
		}
		else
		{
			printf("位置不合法,请重新输入...\n");
		}
	}
}

// 电脑下棋
void computer_play(char chess[ROW][COL], int row, int col)
{
	printf("电脑下棋中...\n");
	Sleep(500);
	while (1)
	{
		// 生成随机数
		int x = rand() % ROW;
		int y = rand() % COL;
		// 位置判断
		if (x >= 0 && x < ROW && y >= 0 && y < COL && chess[x][y] == ' ')
		{
			chess[x][y] = '*';
			break;
		}
	}
}

// 判断棋盘是否下满
int is_full(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (chess[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

// 判断输赢
char is_win(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// 判断三行
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][1] != ' ')
		{
			return chess[i][0];
		}
		// 判断三列
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[1][i] != ' ')
		{
			return chess[0][i];
		}
	}
	// 判断对角线
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[1][1] != ' ')
	{
		return chess[1][1];
	}
	if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[1][1] != ' ')
	{
		return chess[1][1];
	}
	// 判断是否平局
	if (is_full(chess, row, col) == 0)
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}