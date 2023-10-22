#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

void menu(void); // ���ѡ��˵�
void init_chess(char chess[ROW][COL], int row, int col); // ��ʼ������
void display_board(char chess[ROW][COL], int row, int col); // �������
void user_play(char chess[ROW][COL], int row, int col); // �û�����
void computer_play(char chess[ROW][COL], int row, int col); // ��������
char is_win(char chess[ROW][COL], int row, int col); // �ж���Ӯ
int is_full(char chess[ROW][COL], int row, int col); // �ж������Ƿ�����