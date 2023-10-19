#define _CRT_SECURE_NO_WARNINGS 1

// 猜数字游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 输出菜单
void menu()
{
	printf("*****************************\n");
	printf("*****   1.paly 0.exit   *****\n");
	printf("*****************************\n");
}

// 玩游戏
void game()
{
	// 生成随机数
	int random_number = rand() % 100 + 1;
	int user_input = 0;
	while (1)
	{
		printf("请输入:>\n");
		scanf("%d", &user_input);
		// 进行判断
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
		// 输出菜单
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		// 设置随机数生成起点
		srand((unsigned int)time(NULL));
		// 进行选择
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏....\n");
			break;
		default :
			printf("输入错误,请重新输入!!!\n");
		}
	} while (input);

	return 0;
}

// 启动程序,则计算机60秒之后自动关机,控制台输入"我是猪"则取消定时关机
#include <string.h>

int main2()
{
	char str[20] = "0";
	system("shutdown -s -t 60");
	while (1)
	{
		printf("说我是猪取消关机\n");
		scanf("%s", str);
		if (strcmp(str, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	printf("你是猪你是猪你是猪,你真的是猪\n");

	return 0;
}

// 求两个数最大公约数 -- 辗转相除法
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

// 输出1~100数字之间包含多少个9
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

// 输出99乘法表
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