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

void display_menu(void); // ���ѡ��˵�
void game(void); // ��Ϸ�����߼�
void init_board(char board[ROWS][COLS], int rows, int cols, char symb); // ��ʼ������
void display_board(char board[ROWS][COLS], int row, int col); // �������
void set_mine(char board[ROWS][COLS], int row, int col); // �����
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col); // �Ų���