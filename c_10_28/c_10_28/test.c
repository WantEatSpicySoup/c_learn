#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 输出指定菱形
int main1()
{
	// 输出上部分
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		// 输出空格
		int j = 0;
		for (j = i; j < 6; j++)
		{
			printf(" ");
		}
		// 输出字符
		for (j = 0; j <= i * 2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	// 输出下部分
	for (i = 0; i < 6; i++)
	{
		// 输出空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		// 输出字符
		for (j = 0; j < 11 - i*2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

// 输出指定行菱形
int main2()
{
	int line = 0;
	scanf("%d", &line);
	// 输出上部分
	int i = 0;
	for (i = 0; i < line; i++)
	{
		// 输出空格
		int j = 0;
		for (j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		// 输出字符
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	// 输出下部分
	for (i = 0; i < line - 1; i++)
	{
		// 输出空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		// 输出字符
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

// 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
int main3()
{
	int money = 0;
	scanf("%d", &money);
	int empty = money;
	int total = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}

	printf("%d块钱喝了%d瓶汽水\n", money, total);

	return 0;
}

// 实现strlen
#include <assert.h>

int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}

	return count;
}

int main4()
{
	char str[] = "abcdef";
	printf("%d\n", my_strlen(str));

	return 0;
}

// 实现strcpy
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}

int main5()
{
	char str1[20] = { 0 };
	char* str2 = "hello!";
	printf("%s", my_strcpy(str1, str2));

	return 0;
}

// 调整奇数偶数顺序
int* reverse_even_odd(int* arr, int size)
{
	assert(arr);
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		while (left < right && arr[left] % 2 == 1)
		{
			left++;
		}
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
	return arr;
}

void print(int* arr, int size)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {1,1,1,1,1,1,2,2,2,1,1,1};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("交换前打印:");
	print(arr, size);
	printf("交换后打印:");
	int* ret = reverse_even_odd(arr, size);
	print(ret, size);

	return 0;
}