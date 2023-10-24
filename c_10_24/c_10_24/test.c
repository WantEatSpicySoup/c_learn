#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 不创建临时变量,交换两个变量的值
int main1()
{
	int a = 10;
	int b = 20;
	// 加减交换
	// 缺陷:当a+b超过了整形表示最大值,会发生截断
	a = a + b;
	b = a - b;
	a = a - b;

	// 按位异或交换
	

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

// 冒泡排序
void bubble_sort(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void display(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main2()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前:");
	display(arr, size);
	printf("排序后:");
	bubble_sort(arr, size);
	display(arr, size);

	return 0;
}

// 1.实现函数init() 初始化数组为全0
// 2.实现print()  打印数组的每个元素
// 3.实现reverse()  函数完成数组元素的逆置。
void init_all(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main3()
{
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	init_all(arr, size);
	print(arr, size);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	printf("交换前:");
	print(arr, size);
	printf("交换后:");
	reverse(arr, size);
	print(arr, size);

	return 0;
}

// 将数组A中的内容和数组B中的内容进行交换
void swap_arr(int arr1[], int arr2[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main4()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr1) / sizeof(arr1[0]);
	printf("交换前:\n");
	printf("arr1 = ");
	print(arr1, size);
	printf("arr2 = ");
	print(arr2, size);
	swap_arr(arr1, arr2, size);
	printf("交换前:\n");
	printf("arr1 = ");
	print(arr1, size);
	printf("arr2 = ");
	print(arr2, size);

	return 0;
}