#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ʵ��һ������is_prime���ж�һ�����ǲ�������.��������ʵ�ֵ�is_prime��������ӡ100��200֮�������
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
	for (i = 101; i < 200; i += 2) // ż���϶���������
	{
		if (is_prime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n100~200֮����%d������\n", count);

	return 0;
}

// ʵ�ֺ����ж�year�ǲ�������,�������1000~2000֮�������
int is_leap_year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int main2()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year += 2) // �����϶���������
	{
		if (is_leap_year(year))
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\n1000~2000֮����%d������\n", count);

	return 0;
}

// ʵ��һ������������������Ľ���
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
	printf("����ǰ: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("������: a = %d, b = %d\n", a, b);

	return 0;
}

// ��ӡ�˷��ھ����ھ���������������Լ�ָ��
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

// �ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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

// �ǵݹ���n!
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

// �ݹ���n!
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

// �ݹ�ͷǵݹ�ֱ�ʵ��strlen
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

// �����ַ���
void reverse_string(char str[])
{
	char tmp = *str; // ������Ԫ���ַ�
	int len = my_strlen(str); // ��ȡ�ַ�������
	*str = *(str+(len-1)); // �����һ��Ԫ�ظ�ֵ����һ��Ԫ��
	*(str + (len - 1)) = '\0'; // �����һ��Ԫ�ظ�ֵΪ'\0'
	if (my_strlen(str+1) >= 2) // ��֤����һ��Ԫ��
	{
		reverse_string(str+1);
	}
	*(str + (len - 1)) = tmp; // �����ַ���ֵ�����һ��Ԫ��
}

int main9()
{
	char str[] = "abcdef";
	printf("����ǰ���: %s\n", str);
	reverse_string(str);
	printf("��������: %s\n", str);

	return 0;
}

// ����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
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

// �ݹ�ʵ��n��k�η�

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

// �ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
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