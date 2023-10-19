#define _CRT_SECURE_NO_WARNINGS 1

// 使用strcpy()函数
#include <stdio.h>
#include <string.h>

int main1()
{
	char str1[] = "hello chinese";
	char str2[20] = { 0 };
	strcpy(str2, str1);
	printf("%s\n", str2);
	printf("%d", str2[13]);

	return 0;
}

// 使用memset()函数
int main2()
{
	char str[] = "hello chinese";
	// 将hello这五个字符使用'#'替换
	printf("替换前:%s\n", str);
	memset(str, '#', 5);
	printf("替换后:%s\n", str);

	return 0;
}

// 使用strlen()函数
int main3()
{
	char str[] = "hello chinese!";
	size_t len = strlen(str);
	printf("str len = %zd\n", len);

	return 0;
}

// 编写函数:返回两个值中的最大值
int get_max(int x, int y)
{
	return x > y ? x : y;
}

int main4()   
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int max = get_max(a, b);
	printf("a,b | max = %d\n", max);

	return 0;
}

// 编写函数:交换两个变量的值
void swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前:%d %d\n", a, b);
	swap(&a, &b);
	printf("交换后:%d %d\n", a, b);

	return 0;
}