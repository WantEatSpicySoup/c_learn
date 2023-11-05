#define _CRT_SECURE_NO_WARNINGS 1

// 头文件声明
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// 预定义常量符号
#define MAX_CONTACT 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define ADD 1
#define DEL 2
#define SEARCH 3
#define MODIFY 4
#define SHOW 5
#define SORT 6
#define EXIT 0

#define DEFAULAT_SIZE 5
#define INCREASE_SIZE 5

// 类型声明
typedef struct people_info
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char adder[MAX_ADDR];
}People_info;

// 动态版本通讯录
typedef struct Contact
{
	People_info* data; // 指向存放数据的空间
	int size; // 有效信息个数
	int capacity; // 通讯录最大容量
}Contact;

//// 静态版本通讯录
//typedef struct Contact
//{
//	People_info data[MAX_CONTACT]; // 创建通讯录(只能存放)
//	int size; // 有效信息个数
//}Contact;

// 函数声明
// 初始化通讯录
void init_contact(Contact* p_contact);
// 添加联系人
void add(Contact* p_contact);
// 显示联系人列表
void show_contact(const Contact* p_contact);
// 删除指定联系人
void delete_contact(Contact* p_contact);
// 查找指定联系人
void search_contact(const Contact* p_contact);
// 修改指定联系人
void modify_contact(Contact* p_contact);
// 排序通讯录
void sort_contact(Contact* p_contact);
// 内存释放
void destroy_contact(Contact* p_contact);
