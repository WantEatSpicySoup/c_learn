#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// 输出选择菜单
void display_menu()
{
	printf("***************************\n");
	printf("*****  1.play 0.exit  *****\n");
	printf("***************************\n");
}

// 初始化棋盘
void init_board(char board[ROWS][COLS], int rows, int cols, char symb) // symbol:形状
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = symb;
		}
	}
}

// 输出棋盘
void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("|----扫雷游戏----|\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);				
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// 填充雷
void set_mine(char board[ROWS][COLS], int row, int col)
{
	int mine_number = MINE_NUMBER;
	while (mine_number > 0)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			mine_number--;
		}
	}
}

int gei_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1]
		+ mine[x - 1][y]
		+ mine[x - 1][y + 1]
		+ mine[x][y - 1]
		+ mine[x][y + 1]
		+ mine[x + 1][y - 1]
		+ mine[x + 1][y]
		+ mine[x + 1][y + 1])
		- '0' * 8;
}

// 排查类
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < EASY_COUNT)
	{
		printf("请输入要排查的坐标:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾,这个位置有雷,你被炸死了...\n");
				display_board(mine, ROW, COL);
				break;
			}
			else
			{
				show[x][y] = gei_mine_count(mine, x, y) + '0';
				display_board(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标输入有误,请重新输入...\n");
		}
	}
	if (win == EASY_COUNT)
	{
		printf("恭喜你胜利了...\n");
	}
}
// 游戏核心逻辑
void game()
{
	char mine[ROWS][COLS]; // 存放布置好雷的棋盘
	char show[ROWS][COLS]; // 存放计算好雷的棋盘
	// 初始化棋盘
	// mine '0'
	// show '*'
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	// 输出棋盘
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);
	// 填充雷
	set_mine(mine, ROW, COL);
	//display_board(mine, ROW, COL);
	find_mine(mine, show, ROW, COL);
}