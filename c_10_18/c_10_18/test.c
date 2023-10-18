#define _CRT_SECURE_NO_WARNINGS 1

// ��������Ϸ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ����˵�
void menu()
{
	printf("*****************************\n");
	printf("*****   1.paly 0.exit   *****\n");
	printf("*****************************\n");
}

// ����Ϸ
void game()
{
	// ���������
	int random_number = rand() % 100 + 1;
	int user_input = 0;
	while (1)
	{
		printf("������:>\n");
		scanf("%d", &user_input);
		// ������ж�
		if (random_number < user_input)
		{
			printf("�´���!!!\n");
		}
		else if (random_number > user_input)
		{
			printf("��С��!!!\n");
		}
		else
		{
			printf("��ϲ��,�¶���!!!\n");
			break;
		}
	}
}

int main1()
{
	int input = 0;
	do
	{
		// 1.����˵�
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		// ����ʱ���������������
		srand((unsigned int)time(NULL));
		// 2.�û�ѡ��
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ....\n");
			break;
		default :
			printf("ѡ�����,����������!!!\n");
		}
	} while (input);

	return 0;
}

// ʹ��ϵͳ�������ü����1���Ӻ�ػ�,����������ȡ���ػ�
#include <string.h>

int main2()
{
	char str[20] = "0";
	system("shutdown -s -t 60");
	while (1)
	{
		printf("��˵������,������Խ���һ���Ӻ�ػ�\n");
		scanf("%s", str);
		if (strcmp(str, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	printf("������,������,������\n");

	return 0;
}

// �����������Լ��,շת�����
int main3()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	while (m % n)
	{
		int tmp = m % n;
		m = n;
		n = tmp;
	}
	printf("%d", n);

	return 0;
}

// ���1��100�����������г��ֶ��ٸ�����9
int main4()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9)
		{
			count++;

		}
	}
	printf("%d\n", count);
	// 9 19 29 39 49 59 69 79 89 99 
	// 90 91 92 93 94 95 96 97 98 99
	// 20
	
	return 0;
}

// �ڿ���̨���99�˷���
int main5()
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %-2d | ", j, i, i * j);
		}
		printf("\n");
	}

	return 0;
}