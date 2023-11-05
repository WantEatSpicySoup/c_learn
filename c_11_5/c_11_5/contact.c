#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

// 动态版本
// 初始化通讯录
void init_contact(Contact* p_contact)
{
	assert(p_contact);
	p_contact->data = (People_info*)malloc(DEFAULAT_SIZE * sizeof(People_info));
	if(p_contact == NULL)
	{
		perror("init_contact");
		return;
	}
	p_contact->size = 0;
	p_contact->capacity = DEFAULAT_SIZE;
}

//// 静态版本
//// 初始化通讯录
//void init_contact(Contact* p_contact)
//{
//	memset(p_contact->data, 0, sizeof(p_contact->data)); // 初始化数组内容
//	p_contact->size = 0; // 有效信息个数设置为0
//}

// 查找联系人
int find_name(const Contact* p_contact, char* name)
{
	int i = 0;
	for (i = 0; i < p_contact->size; i++)
	{
		if (strcmp(p_contact->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

// 检测容量
int check_capacity(Contact* p_contact)
{
	if (p_contact->capacity == p_contact->size)
	{
		People_info* p_tmp = (People_info*)realloc(p_contact->data, (p_contact->capacity + INCREASE_SIZE) * sizeof(People_info));
		if (p_contact == NULL)
		{
			perror("check_capacity");
			return 0;
		}
		else
		{
			p_contact->data = p_tmp;
			p_contact->capacity += INCREASE_SIZE;
			printf("增容成功!!!\n");
			return 1;
		}
	}
	return 1;
}

// 增加容量


// 动态版本
// 添加联系人
void add(Contact* p_contact)
{
	assert(p_contact);
	if (p_contact->size == p_contact->capacity)
	{
		assert(p_contact);
		if (check_capacity(p_contact) == 0)
		{
			return;
		}
	}
	printf("请输入姓名:>");
	scanf("%s", p_contact->data[p_contact->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(p_contact->data[p_contact->size].age));
	printf("请输入性别:>");
	scanf("%s", p_contact->data[p_contact->size].sex);
	printf("请输入联系方式:>");
	scanf("%s", p_contact->data[p_contact->size].tele);
	printf("请输入地址:>");
	scanf("%s", p_contact->data[p_contact->size].adder);
	p_contact->size++;
	printf("联系人添加成功\n");
}

//// 静态版本
//// 添加联系人
//void add(Contact* p_contact)
//{
//	assert(p_contact);
//	if (p_contact->size == MAX_CONTACT)
//	{
//		printf("通讯录已满,无法添加新的联系人!!!\n");
//		return;
//	}
//	printf("请输入姓名:>");
//	scanf("%s", p_contact->data[p_contact->size].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(p_contact->data[p_contact->size].age));
//	printf("请输入性别:>");
//	scanf("%s", p_contact->data[p_contact->size].sex);
//	printf("请输入联系方式:>");
//	scanf("%s", p_contact->data[p_contact->size].tele);
//	printf("请输入地址:>");
//	scanf("%s", p_contact->data[p_contact->size].adder);
//	p_contact->size++;
//	printf("联系人添加成功\n");
//}

// 显示联系人列表
void show_contact(const Contact* p_contact)
{
	assert(p_contact);
	if (p_contact->size == 0)
	{
		printf("通讯录当前没有联系人!!!\n");
		return;
	}
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < p_contact->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n", p_contact->data[i].name,
			p_contact->data[i].age,
			p_contact->data[i].sex,
			p_contact->data[i].tele,
			p_contact->data[i].adder);
	}
}

// 删除指定联系人
void delete_contact(Contact* p_contact)
{
	char name[MAX_NAME];
	assert(p_contact);
	if (p_contact->size == 0)
	{
		printf("通讯录当前没有联系人!!!\n");
		return;
	}
	// 根据姓名来删除
	printf("请输入要删除联系人的姓名:>");
	scanf("%s", name);
	int del = find_name(p_contact, name);
	if (del == -1)
	{
		return;
	}
	// 删除坐标为del的信息
	int i = 0;
	for (i = del; i < p_contact->size - 1; i++)
	{
		p_contact->data[i] = p_contact->data[i + 1];
	}
	p_contact->size--;
	printf("联系人已被删除!!!\n");
}

// 查找指定联系人	
void search_contact(const Contact* p_contact)
{
	assert(p_contact);
	char name[MAX_NAME] = {0};
	printf("请输入要查找人的名字:>\n");
	scanf("%s", name);
	int pos = find_name(p_contact, name);
	if (pos == -1)
	{
		printf("此联系人不存在!!!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n", p_contact->data[pos].name,
			p_contact->data[pos].age,
			p_contact->data[pos].sex,
			p_contact->data[pos].tele,
			p_contact->data[pos].adder);
	}

}// 修改指定联系人
void modify_contact(Contact* p_contact)
{
	assert(p_contact);
	char name[MAX_NAME] = { 0 };
	printf("请输入你要修改的联系人姓名:>");
	scanf("%s", name);
	int pos = find_name(p_contact, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", p_contact->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(p_contact->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", p_contact->data[pos].sex);
		printf("请输入联系方式:>");
		scanf("%s", p_contact->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", p_contact->data[pos].adder);
	}
}

void bubble_sort(Contact* p_contact)
{
	int i = 0;
	for (i = 0; i < p_contact->size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < p_contact->size - i - 1; j++)
		{
			if (strcmp((p_contact->data[j]).name, (p_contact->data[j + 1]).name) == 1)
			{
				printf("需要修改\n");
				People_info tmp = p_contact->data[j];
				p_contact->data[j] = p_contact->data[j + 1];
				p_contact->data[j + 1] = tmp;
			}
		}
	}
}

// 排序通讯录
void sort_contact(Contact* p_contact)
{
	if (p_contact->size <= 1)
	{
		printf("通讯录为空或者只有1位联系人!!!\n");

		return;
	}
	bubble_sort(p_contact);
	printf("根据姓名排序完成!!!\n");
}

// 内存释放
void destroy_contact(Contact* p_contact)
{
	free(p_contact->data);
	p_contact->capacity = 0;
	p_contact->size = 0;
	p_contact = NULL;
}