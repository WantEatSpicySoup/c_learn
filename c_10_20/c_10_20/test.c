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
int main4()
{
	int n = 0;
	scanf("%d", &n);
	print_mult_table(n);

	return 0;
}

// 递归方式实现打印一个整数的每一位
void print_one(size_t a)
{
	if (a > 9)
	{
		print_one(a / 10);
	}
	printf("%zd ", a % 10);
}

int main5()
{
	size_t a = 1234;
	print_one(a);

	return 0;
}

// 非递归求n!
int main6()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int ret = 1;
	for (i = 2; i <= n; i++)
	{
		ret *= i;
	}
	printf("%d\n", ret);

	return 0;
}

// 递归求n!
int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

int main7()
{
	int n = 0;
	scanf("%d", &n);
	int ret = factorial(n);
	printf("%d\n", ret);

	return 0;
}

// 递归和非递归分别实现strlen
int my_strlen(char str[])
{
	int count = 0;
	while ('\0' != *str)
	{
		str++;
		count++;
	}
	return count;
}

int my_strlen_recur(char str[])
{
	if ('\0' == *str)
	{
		return 0;
	}
	return 1 + my_strlen_recur(str + 1);
}

int main8()
{
	char str[20] = "abcdefg";
	int len1 = my_strlen(str);
	int len2 = my_strlen_recur(str);
	printf("my_strlen = %d\n", len1);
	printf("my_strlen_recur = %d\n", len2);

	return 0;
}

// 逆序字符串
void reverse_string(char str[])
{
	char tmp = *str; // 保存首元素字符
	int len = my_strlen(str); // 获取字符串长度
	*str = *(str+(len-1)); // 将最后一个元素赋值给第一个元素
	*(str + (len - 1)) = '\0'; // 将最后一个元素赋值为'\0'
	if (my_strlen(str+1) >= 2) // 保证还有一个元素
	{
		reverse_string(str+1);
	}
	*(str + (len - 1)) = tmp; // 将首字符赋值给最后一个元素
}

int main9()
{
	char str[] = "abcdef";
	printf("逆序前输出: %s\n", str);
	reverse_string(str);
	printf("逆序后输出: %s\n", str);

	return 0;
}

// 计算一个数的每位之和（递归实现）
int add_one(n)
{
	if (n < 10)
	{
		return n;
	}
	return n % 10 + add_one(n / 10);
}

int main10()
{
	int n = 0;
	scanf("%d", &n);
	int ret = add_one(n);
	printf("%d\n", ret);

	return 0;
}

// 递归实现n的k次方

double n_power(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k > 0)
	{
		return n * n_power(n, k - 1);
	}
	else
	{
		return 1.0 / n_power(n, -k);
	}
}
int main11()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double ret = n_power(n, k);
	printf("%lf\n", ret);

	return 0;
}

// 递归和非递归分别实现求第n个斐波那契数
int fabonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int fabonacci_recur(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	return fabonacci_recur(n - 1) + fabonacci_recur(n - 2);
}


int main12()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = fabonacci(n);
	printf("faboncci = %d\n", ret1);
	int ret2 = fabonacci_recur(n);
	printf("faboncci_recur = %d\n", ret2);

	return 0;
}