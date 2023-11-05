#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

char* str_revolve(char* arr, int revolve_len)
{
	size_t len = strlen(arr);
	while (revolve_len != 0)
	{
		char tmp = arr[0];
		int i = 0;
		for (i = 0; i < len - 1; i++)
		{
			*(arr+i) = *(arr+i+1);

		}
		arr[len - 1] = tmp;
		revolve_len--;
	}
	return arr;
}

// ʵ��һ�����������������ַ����е�k���ַ���
int main1()
{
	char str[] = "abcdef";
	int revolve_len = 7;
	printf("��תǰ:%s\n", str);
	printf("��ת��:%s\n", str_revolve(str, revolve_len));

	return 0;
}

// ��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
int main2()
{
	int arr[5][5] = { 0 };
	// �������Ͼ���
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = i + j + 1;
		}
	}
	// ������Ͼ���
	for (i = 0; i < 5; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	// ���key��ֵ
	int key = 0;
	scanf("%d", &key);
	for (i = 0; i < 5; i++)
	{
		if (arr[0][i] == key)
		{
			printf("�ҵ���,�±�Ϊ[%d][%d]\n", 0, i);
			break;
		}
		if (arr[i][4] == key)
		{
			printf("�ҵ���,�±�Ϊ[%d][%d]\n", i, 4);
			break;
		}
	}
	if (i == 5)
	{
		printf("��Ǹ���Ͼ�����û����Ҫ���ҵ�ֵ\n");
	}

	return 0;
}

// ���һά����
void print_arr(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// �ȽϹ���
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

// ��������
void swap(void* p1, void* p2, int size)
{
	int tmp = *(int*)p1;
	*(int*)p1 = *(int*)p2;
	*(int*)p2 = tmp;
}

// ð�ݰ��������
void bubble_qsort(void* base, int count, int size, int (*cmp_func)(void*, void*))
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < count - i - 1; j++)
		{
			if (int_cmp(((char*)base + (size * j)), ((char*)base + (size * (j + 1)))) > 0)
			{
				swap(((char*)base + (size * j)), ((char*)base + (size * (j + 1))), size);
			}
		}
	}
}

// qsortģ��ʵ��
int main3()
{
	int arr[] = { 1,3,2,4,6,5,9,7,8,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ���:");
	print_arr(arr, size);
	bubble_qsort(arr, size, sizeof(int), int_cmp);
	printf("��������:");
	print_arr(arr, size);

	return 0;
}

// ��ϰʹ�ÿ⺯����qsort����������͵�����
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
	char name[10];
	int age;
	int score;
}Stu;

// ����ṹ������
void print_stu(Stu* p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++, p++)
	{
		printf("name = %s , age = %d, score=%d\n", p->name, p->age, p->score);
	}
}

// �Ƚ��ַ�������
int str_cmp(const void* p1, const void* p2)
{
	return strcmp(((Stu*)p1)->name, ((Stu*)p2)->name);
}

// ����Ƚ�
int age_cmp(const void* p1, const void* p2)
{
	return (((Stu*)p1)->age) - (((Stu*)p2)->age);
}

// �ɼ��Ƚ�
int score_cmp(const void* p1, const void* p2)
{
	return (((Stu*)p1)->score) - (((Stu*)p2)->score);
}

int main4()
{
	Stu arr_stu[5] = { {"���", 35, 98}, {"ʷǿ", 40, 82}, {"���", 23, 99}, {"����", 52, 85}, {"�޼�", 23, 70}};
	int size = sizeof(arr_stu) / sizeof(arr_stu[0]);
	printf("����ǰ:\n");
	print_stu(arr_stu, size);
	printf("������������:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), str_cmp);
	print_stu(arr_stu, size);
	printf("������������:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), age_cmp);
	print_stu(arr_stu, size);
	printf("���ݳɼ�����:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), score_cmp);
	print_stu(arr_stu, size);

	return 0;
}

// �ַ�����ת
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

// дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
void left_move(char* str, int len)
{
	// �������
	reverse(str, str + len - 1);
	// �Ҳ�����
	reverse(str + len, str + strlen(str) - 1);
	// ��������
	reverse(str, str + strlen(str) - 1);
}

int main5()
{
	char str[] = "abcdef";
	left_move(str, 2);
	printf("%s\n", str);

	return 0;
}


// дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
int is_left_move(char* str1, char* str2)
{
	int len = strlen(str1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		char tmp = *str1;
		int len = strlen(str1);
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(str1 + j) = *(str1 + j + 1);
		}
		*(str1 + len - 1) = tmp;
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char str1[] = "defabc";
	char str2[] = "bcdef";
	if (is_left_move(str1, str2))
	{
		printf("%s �� %s �ķ�ת�ַ���", str1, str2);
	}
	else
	{
		printf("%s ���� %s �ķ�ת�ַ���", str1, str2);
	}

	return 0;
}