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

int main2()
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

// 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
int main4()
{
	int a = 0;
	scanf("%d", &a);
	int sum = 0;
	int tmp = 0;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		tmp = 0;
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			tmp *= 10;
			tmp += a;
		}
		sum += tmp;
	}
	printf("%d\n", sum);
	 
	return 0;
}

#include <assert.h>

// 模拟实现strlen()函数
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int main5()
{
	char* str = "abcdefg";
	printf("%d\n", my_strlen(str));

	return 0;
}

// 输出0～100000之间的所有“水仙花数”
int get_num(int val)
{
	if (val == 0)
	{
		return 1;
	}
	int count = 0;
	while (val > 0)
	{
		count++;
		val /= 10;
	}
	return count;
}

#include <math.h>

int main6()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		int count = get_num(i);
		int res = 0;
		int tmp = i;
		while(tmp > 0)
		{
			res += (int)pow(tmp % 10, count);
			tmp /= 10;
		}
		if (res == i)
		{
			printf("%d ", res);
		}
	}
	return 0;
}

// 打印菱形
int main()
{
	int n = 0;
	scanf("%d", &n);
	// 输出上部分
	int i = 0;
	for (i = 0; i < n / 2 + 1; i++)
	{
		// 输出空格
		int j = 0;
		for (j = 0; j < n / 2 - i; j++)
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
	for (i = 0; i < n / 2; i++)
	{
		// 输出空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		// 输出字符
		for (j = 0; j <= n/2-i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}