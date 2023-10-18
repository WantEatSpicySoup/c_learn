#define _CRT_SECURE_NO_WARNINGS 1

// 使用for循环输出1~10的值
#include <stdio.h>

int main1()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}

	return 0;
}

// 使用for循环来依次输出数组的值
int main2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

// 使用do while循环输出1~10的值
int main3()
{
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	}while (i <= 10);

	return 0;
}

// 计算n的阶乘
int main4()
{
	int n = 0;
	int ret = 1;
	printf("请输入你要计算的阶乘:");
	scanf("%d", &n);
	int i = 0;
	for (i = 2; i <= n; i++)
	{
		ret *= i;
	}
	printf("ret = %d", ret);

	return 0;
}

// 计算1!+2!+3!+4!+5!....+10! -- 使用两个for循环
int main5()
{
	int i = 0;
	int ret = 1;
	for (i = 2; i <= 10; i++)
	{
		int j = 0;
		int tmp = 1;
		for (j = 2; j <= i; j++)
		{
			tmp *= j;
		}
		ret += tmp;
	}
	printf("%d", ret);

	return 0;
}

// 计算1!+2!+3!+4!+5!....+10! -- 使用一个for循环
int main6()
{
	int i = 0;
	int ret = 1;
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		ret *= i;
		sum += ret;
	}
	printf("%d", sum);

	return 0;
}

// 在一个有序数组中查找某个具体的数字key
int main7()
{
	int key = 11;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] == key)
		{
			printf("找到了,下标为%d\n", i);
			break;
		}
	}
	if (i == 10)
	{
		printf("没有找到\n");
	}

	return 0;
}

// 二分查找 binary_search
int main8()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 5;
	int left = 0;
	int right = 9;
	int flag = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了,下标为%d", mid);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有找到!\n");
	}

	return 0;
}

// 演示一个字符串从两端向中间汇聚
#include <windows.h>
#include <string.h>

int main9()
{
	char arr1[] = "welcome chinese!!!!!";
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{

		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
	}
	printf("%s\n", arr2);

	return 0;
}

// 模拟用户登录,密码错误三次之后退出程序
#define USER_PASSWORD "123456"

int main()
{
	char input[20] = {0};
	int i = 0;
	while (i < 3)
	{
		printf("请输入你的密码:\n");
		scanf("%s", input);
		if (strcmp(input, USER_PASSWORD) == 0)
		{
			printf("登陆成功!!!\n");
			break;
		}
		else
		{
			printf("密码错误!!!\n");
		}
		i++;
	}
	if (3 == i)
	{
		printf("登录失败,程序退出!!!");
	}

	return 0;
}