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
	init_contact(&contact); // ��ʼ��ͨѶ¼��Ϣ
	do
	{
		menu();
		printf("��ѡ��:\n");
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
			printf("�˳�ϵͳ��....\n");
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