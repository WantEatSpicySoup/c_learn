#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		display_menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0 :
			printf("退出游戏....\n");
			break;
		default :
			printf("选择错误,请重新选择...\n");
		}
	} while (input);

	return 0;
}