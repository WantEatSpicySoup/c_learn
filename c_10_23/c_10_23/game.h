#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9
#define ROWS (ROW+2)
#define COLS (COL+2)
#define MINE_NUMBER 10
#define EASY_COUNT ((ROW*COL)-(MINE_NUMBER))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu(void); // 输出选择菜单
void game(void); // 游戏核心逻辑
void init_board(char board[ROWS][COLS], int rows, int cols, char symb); // 初始化棋盘
void display_board(char board[ROWS][COLS], int row, int col); // 输出棋盘
void set_mine(char board[ROWS][COLS], int row, int col); // 填充雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col); // 排查类