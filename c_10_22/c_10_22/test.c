#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char chess[ROW][COL];
	char result = 0;
	init_chess(chess, ROW, COL); // ��ʼ������
	display_board(chess, ROW, COL); // �������
	while (1)
	{
		user_play(chess, ROW, COL); // �û�����
		display_board(chess, ROW, COL); // �������
		result = is_win(chess, ROW, COL); // �ж���Ӯ
		if (result != 'C')
		{
			break;
		}
		computer_play(chess, ROW, COL); // ��������
		display_board(chess, ROW, COL); // �������
		result = is_win(chess, ROW, COL); // �ж���Ӯ
		if (result != 'C')
		{
			break;
		}
	}
	// ���н���ж�
	if (result == '#')
	{
		printf("���:user_palyʤ��!!!\n");
	}
	else if (result == '*')
	{
		printf("����:computer_palyʤ��!!!\n");
	}
	else
	{
		printf("��Һ͵��Դ��ƽ��!!!\n");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		// �����ѡ��˵�
		menu(); 
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		// ����ѡ��
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("�˳���Ϸ....\n");
			break;
		default :
			printf("�������,����������!!!\n");
		}
	}while (input);

	return 0;
}