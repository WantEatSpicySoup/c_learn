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

// 实现一个函数，可以左旋字符串中的k个字符。
int main1()
{
	char str[] = "abcdef";
	int revolve_len = 7;
	printf("旋转前:%s\n", str);
	printf("旋转后:%s\n", str_revolve(str, revolve_len));

	return 0;
}

// 有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
int main2()
{
	int arr[5][5] = { 0 };
	// 创建杨氏矩阵
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = i + j + 1;
		}
	}
	// 输出杨氏矩阵
	for (i = 0; i < 5; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	// 输出key的值
	int key = 0;
	scanf("%d", &key);
	for (i = 0; i < 5; i++)
	{
		if (arr[0][i] == key)
		{
			printf("找到了,下标为[%d][%d]\n", 0, i);
			break;
		}
		if (arr[i][4] == key)
		{
			printf("找到了,下标为[%d][%d]\n", i, 4);
			break;
		}
	}
	if (i == 5)
	{
		printf("抱歉杨氏矩阵中没有你要查找的值\n");
	}

	return 0;
}

// 输出一维数组
void print_arr(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// 比较规则
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}

// 两数交换
void swap(void* p1, void* p2, int size)
{
	int tmp = *(int*)p1;
	*(int*)p1 = *(int*)p2;
	*(int*)p2 = tmp;
}

// 冒泡版快速排序
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

// qsort模拟实现
int main3()
{
	int arr[] = { 1,3,2,4,6,5,9,7,8,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前输出:");
	print_arr(arr, size);
	bubble_qsort(arr, size, sizeof(int), int_cmp);
	printf("排序后输出:");
	print_arr(arr, size);

	return 0;
}

// 练习使用库函数，qsort排序各种类型的数据
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
	char name[10];
	int age;
	int score;
}Stu;

// 输出结构体数组
void print_stu(Stu* p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++, p++)
	{
		printf("name = %s , age = %d, score=%d\n", p->name, p->age, p->score);
	}
}

// 比较字符串规则
int str_cmp(const void* p1, const void* p2)
{
	return strcmp(((Stu*)p1)->name, ((Stu*)p2)->name);
}

// 年龄比较
int age_cmp(const void* p1, const void* p2)
{
	return (((Stu*)p1)->age) - (((Stu*)p2)->age);
}

// 成绩比较
int score_cmp(const void* p1, const void* p2)
{
	return (((Stu*)p1)->score) - (((Stu*)p2)->score);
}

int main4()
{
	Stu arr_stu[5] = { {"汪淼", 35, 98}, {"史强", 40, 82}, {"杨冰", 23, 99}, {"坎特", 52, 85}, {"罗辑", 23, 70}};
	int size = sizeof(arr_stu) / sizeof(arr_stu[0]);
	printf("排序前:\n");
	print_stu(arr_stu, size);
	printf("根据姓名排序:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), str_cmp);
	print_stu(arr_stu, size);
	printf("根据年龄排序:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), age_cmp);
	print_stu(arr_stu, size);
	printf("根据成绩排序:\n");
	qsort(arr_stu, size, sizeof(arr_stu[0]), score_cmp);
	print_stu(arr_stu, size);

	return 0;
}

// 字符串翻转
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

// 写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
void left_move(char* str, int len)
{
	// 左侧逆序
	reverse(str, str + len - 1);
	// 右侧逆序
	reverse(str + len, str + strlen(str) - 1);
	// 整体逆序
	reverse(str, str + strlen(str) - 1);
}

int main5()
{
	char str[] = "abcdef";
	left_move(str, 2);
	printf("%s\n", str);

	return 0;
}


// 写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
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
		printf("%s 是 %s 的翻转字符串", str1, str2);
	}
	else
	{
		printf("%s 不是 %s 的翻转字符串", str1, str2);
	}

	return 0;
}