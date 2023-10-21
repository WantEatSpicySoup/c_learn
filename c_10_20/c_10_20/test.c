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
int main()
{
	int n = 0;
	scanf("%d", &n);
	print_mult_table(n);

	return 0;
}