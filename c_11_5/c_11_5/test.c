#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("************************************\n");
	printf("*****     1.add      2.del      ****\n");
	printf("*****     3.search   4.modify   ****\n");
	printf("*****     5.show     6.sort     ****\n");
	printf("*****           0.exit          ****\n");
	printf("************************************\n");
}

void test()
{
	int input = 0;
	Contact contact;
	init_contact(&contact); // 初始化通讯录信息
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD :
			add(&contact);
			break;
		case DEL:
			delete_contact(&contact);
			break;
		case SEARCH:
			search_contact(&contact);
			break;
		case MODIFY:
			modify_contact(&contact);
			break;
		case SHOW:
			show_contact(&contact);
			break;
		case SORT:
			sort_contact(&contact);
			break;
		case EXIT :
			printf("退出系统中....\n");
			destroy_contact(&contact);
			break;
		default:
			break;
		}
	}while (input);
}

int main()
{
	test();
}