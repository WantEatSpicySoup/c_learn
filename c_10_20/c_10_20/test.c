#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 实现一个函数is_prime，判断一个数是不是素数.利用上面实现的is_prime函数，打印100到200之间的素数
int is_prime(int val)
{
	int i = 0;
	for (i = 2; i < val; i++)
	{
		if(val % i == 0)
		{ 
			return 0;
		}
	}
	return 1;
}
int main1()
{
	int i = 0;
	int count = 0;
	for (i = 101; i < 200; i += 2) // 偶数肯定不是素数
	{
		if (is_prime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n100~200之间有%d个素数\n", count);

	return 0;
}

// 实现函数判断year是不是闰年,并且输出1000~2000之间的闰年
int is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int main2()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year += 2) // 奇数肯定不是闰年
	{
		if (is_leap_year(year))
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\n1000~2000之间有%d个闰年\n", count);

	return 0;
}

// 实现一个函数完成两个整数的交换
void swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main3()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("交换后: a = %d, b = %d\n", a, b);

	return 0;
}

// 打印乘法口诀表，口诀表的行数和列数自己指定
int get_tab(int number)
{
	int count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return -count;
}
void print_mult_table(int number)
{

	int i = 0;
	int tab = get_tab(number);
	for (i = 1; i <= number; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%*d*%*d=%*d ", tab, j, tab, i, tab-1, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	print_mult_table(n);

	return 0;
}