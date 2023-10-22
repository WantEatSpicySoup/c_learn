#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// ���ѡ��˵�
void menu()
{
	printf("******************************\n");
	printf("*********   1.paly   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}

// ��ʼ������
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

// �������
void display_board(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	// ������
	for (i = 0; i < row; i++)
	{
		// �������
		int j = 0;
		for (j = 0; j < row; j++)
		{
			printf(" %c ", chess[i][j]);
			// ���|
			if (j < row - 1)
			{
				printf("|");
			}
		}
		// �����һ�л���
		printf("\n");

		// �����м�����ָ��� -- ֻ�������
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
			// �����һ�л���
			printf("\n");
		}
	}
}

// �û�����
void user_play(char chess[ROW][COL], int row, int col)
{
	printf("�û�������:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		// ����λ���ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (chess[x - 1][y - 1] != ' ')
			{
				printf("λ����������,����������...\n");
			}
			else
			{
				chess[x - 1][y - 1] = '#';
				break;
			}
		}
		else
		{
			printf("λ�ò��Ϸ�,����������...\n");
		}
	}
}

// ��������
void computer_play(char chess[ROW][COL], int row, int col)
{
	printf("����������...\n");
	Sleep(500);
	while (1)
	{
		// ���������
		int x = rand() % ROW;
		int y = rand() % COL;
		// λ���ж�
		if (x >= 0 && x < ROW && y >= 0 && y < COL && chess[x][y] == ' ')
		{
			chess[x][y] = '*';
			break;
		}
	}
}

// �ж������Ƿ�����
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

// �ж���Ӯ
char is_win(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		// �ж�����
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][1] != ' ')
		{
			return chess[i][0];
		}
		// �ж�����
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[1][i] != ' ')
		{
			return chess[0][i];
		}
	}
	// �ж϶Խ���
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[1][1] != ' ')
	{
		return chess[1][1];
	}
	if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[1][1] != ' ')
	{
		return chess[1][1];
	}
	// �ж��Ƿ�ƽ��
	if (is_full(chess, row, col) == 0)
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}