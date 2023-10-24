#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ��������ʱ����,��������������ֵ
int main1()
{
	int a = 10;
	int b = 20;
	// �Ӽ�����
	// ȱ��:��a+b���������α�ʾ���ֵ,�ᷢ���ض�
	a = a + b;
	b = a - b;
	a = a - b;

	// ��λ��򽻻�
	

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

// ð������
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
	printf("����ǰ:");
	display(arr, size);
	printf("�����:");
	bubble_sort(arr, size);
	display(arr, size);

	return 0;
}

// 1.ʵ�ֺ���init() ��ʼ������Ϊȫ0
// 2.ʵ��print()  ��ӡ�����ÿ��Ԫ��
// 3.ʵ��reverse()  �����������Ԫ�ص����á�
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
	printf("����ǰ:");
	print(arr, size);
	printf("������:");
	reverse(arr, size);
	print(arr, size);

	return 0;
}

// ������A�е����ݺ�����B�е����ݽ��н���
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
	printf("����ǰ:\n");
	printf("arr1 = ");
	print(arr1, size);
	printf("arr2 = ");
	print(arr2, size);
	swap_arr(arr1, arr2, size);
	printf("����ǰ:\n");
	printf("arr1 = ");
	print(arr1, size);
	printf("arr2 = ");
	print(arr2, size);

	return 0;
}