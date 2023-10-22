#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

void menu(void); // 输出选择菜单
void init_chess(char chess[ROW][COL], int row, int col); // 初始化棋子
void display_board(char chess[ROW][COL], int row, int col); // 输出棋盘
void user_play(char chess[ROW][COL], int row, int col); // 用户下棋
void computer_play(char chess[ROW][COL], int row, int col); // 电脑下棋
char is_win(char chess[ROW][COL], int row, int col); // 判断输赢
int is_full(char chess[ROW][COL], int row, int col); // 判断棋盘是否下满