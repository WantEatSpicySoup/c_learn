#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 定义一维数组并且遍历

int main1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	

	return 0;
}

// 定义二维数组并且遍历
int main()
{
	
	int arr[3][4] = { {1,2,3,4}, {2,3,4,5}, {3,4,5,6} };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

