#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

// ��̬�汾
// ��ʼ��ͨѶ¼
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

//// ��̬�汾
//// ��ʼ��ͨѶ¼
//void init_contact(Contact* p_contact)
//{
//	memset(p_contact->data, 0, sizeof(p_contact->data)); // ��ʼ����������
//	p_contact->size = 0; // ��Ч��Ϣ��������Ϊ0
//}

// ������ϵ��
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

// �������
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
			printf("���ݳɹ�!!!\n");
			return 1;
		}
	}
	return 1;
}

// ��������


// ��̬�汾
// �����ϵ��
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
	printf("����������:>");
	scanf("%s", p_contact->data[p_contact->size].name);
	printf("����������:>");
	scanf("%d", &(p_contact->data[p_contact->size].age));
	printf("�������Ա�:>");
	scanf("%s", p_contact->data[p_contact->size].sex);
	printf("��������ϵ��ʽ:>");
	scanf("%s", p_contact->data[p_contact->size].tele);
	printf("�������ַ:>");
	scanf("%s", p_contact->data[p_contact->size].adder);
	p_contact->size++;
	printf("��ϵ����ӳɹ�\n");
}

//// ��̬�汾
//// �����ϵ��
//void add(Contact* p_contact)
//{
//	assert(p_contact);
//	if (p_contact->size == MAX_CONTACT)
//	{
//		printf("ͨѶ¼����,�޷�����µ���ϵ��!!!\n");
//		return;
//	}
//	printf("����������:>");
//	scanf("%s", p_contact->data[p_contact->size].name);
//	printf("����������:>");
//	scanf("%d", &(p_contact->data[p_contact->size].age));
//	printf("�������Ա�:>");
//	scanf("%s", p_contact->data[p_contact->size].sex);
//	printf("��������ϵ��ʽ:>");
//	scanf("%s", p_contact->data[p_contact->size].tele);
//	printf("�������ַ:>");
//	scanf("%s", p_contact->data[p_contact->size].adder);
//	p_contact->size++;
//	printf("��ϵ����ӳɹ�\n");
//}

// ��ʾ��ϵ���б�
void show_contact(const Contact* p_contact)
{
	assert(p_contact);
	if (p_contact->size == 0)
	{
		printf("ͨѶ¼��ǰû����ϵ��!!!\n");
		return;
	}
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < p_contact->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n", p_contact->data[i].name,
			p_contact->data[i].age,
			p_contact->data[i].sex,
			p_contact->data[i].tele,
			p_contact->data[i].adder);
	}
}

// ɾ��ָ����ϵ��
void delete_contact(Contact* p_contact)
{
	char name[MAX_NAME];
	assert(p_contact);
	if (p_contact->size == 0)
	{
		printf("ͨѶ¼��ǰû����ϵ��!!!\n");
		return;
	}
	// ����������ɾ��
	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s", name);
	int del = find_name(p_contact, name);
	if (del == -1)
	{
		return;
	}
	// ɾ������Ϊdel����Ϣ
	int i = 0;
	for (i = del; i < p_contact->size - 1; i++)
	{
		p_contact->data[i] = p_contact->data[i + 1];
	}
	p_contact->size--;
	printf("��ϵ���ѱ�ɾ��!!!\n");
}

// ����ָ����ϵ��	
void search_contact(const Contact* p_contact)
{
	assert(p_contact);
	char name[MAX_NAME] = {0};
	printf("������Ҫ�����˵�����:>\n");
	scanf("%s", name);
	int pos = find_name(p_contact, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����!!!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n", p_contact->data[pos].name,
			p_contact->data[pos].age,
			p_contact->data[pos].sex,
			p_contact->data[pos].tele,
			p_contact->data[pos].adder);
	}

}// �޸�ָ����ϵ��
void modify_contact(Contact* p_contact)
{
	assert(p_contact);
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	int pos = find_name(p_contact, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", p_contact->data[pos].name);
		printf("����������:>");
		scanf("%d", &(p_contact->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", p_contact->data[pos].sex);
		printf("��������ϵ��ʽ:>");
		scanf("%s", p_contact->data[pos].tele);
		printf("�������ַ:>");
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
				printf("��Ҫ�޸�\n");
				People_info tmp = p_contact->data[j];
				p_contact->data[j] = p_contact->data[j + 1];
				p_contact->data[j + 1] = tmp;
			}
		}
	}
}

// ����ͨѶ¼
void sort_contact(Contact* p_contact)
{
	if (p_contact->size <= 1)
	{
		printf("ͨѶ¼Ϊ�ջ���ֻ��1λ��ϵ��!!!\n");

		return;
	}
	bubble_sort(p_contact);
	printf("���������������!!!\n");
}

// �ڴ��ͷ�
void destroy_contact(Contact* p_contact)
{
	free(p_contact->data);
	p_contact->capacity = 0;
	p_contact->size = 0;
	p_contact = NULL;
}