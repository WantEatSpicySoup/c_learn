#define _CRT_SECURE_NO_WARNINGS 1

// ͷ�ļ�����
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// Ԥ���峣������
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

// ��������
typedef struct people_info
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char adder[MAX_ADDR];
}People_info;

// ��̬�汾ͨѶ¼
typedef struct Contact
{
	People_info* data; // ָ�������ݵĿռ�
	int size; // ��Ч��Ϣ����
	int capacity; // ͨѶ¼�������
}Contact;

//// ��̬�汾ͨѶ¼
//typedef struct Contact
//{
//	People_info data[MAX_CONTACT]; // ����ͨѶ¼(ֻ�ܴ��)
//	int size; // ��Ч��Ϣ����
//}Contact;

// ��������
// ��ʼ��ͨѶ¼
void init_contact(Contact* p_contact);
// �����ϵ��
void add(Contact* p_contact);
// ��ʾ��ϵ���б�
void show_contact(const Contact* p_contact);
// ɾ��ָ����ϵ��
void delete_contact(Contact* p_contact);
// ����ָ����ϵ��
void search_contact(const Contact* p_contact);
// �޸�ָ����ϵ��
void modify_contact(Contact* p_contact);
// ����ͨѶ¼
void sort_contact(Contact* p_contact);
// �ڴ��ͷ�
void destroy_contact(Contact* p_contact);
