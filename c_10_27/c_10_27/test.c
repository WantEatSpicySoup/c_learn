#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main1()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}

// 使用指针打印数组内容
void print_arr(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(arr+i));
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, size);

	return 0;
}

// 字符串逆序
int main3()
{
	char str[10000] = { 0 };
	gets(str);
	int start = 0;
	int end = strlen(str) - 1;
	while (start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	printf("%s", str);

	return 0;
}