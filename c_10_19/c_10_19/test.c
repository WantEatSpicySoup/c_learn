#define _CRT_SECURE_NO_WARNINGS 1

// ʹ��strcpy()����
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

// ʹ��memset()����
int main2()
{
	char str[] = "hello chinese";
	// ��hello������ַ�ʹ��'#'�滻
	printf("�滻ǰ:%s\n", str);
	memset(str, '#', 5);
	printf("�滻��:%s\n", str);

	return 0;
}

// ʹ��strlen()����
int main3()
{
	char str[] = "hello chinese!";
	size_t len = strlen(str);
	printf("str len = %zd\n", len);

	return 0;
}

// ��д����:��������ֵ�е����ֵ
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

// ��д����:��������������ֵ
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
	printf("����ǰ:%d %d\n", a, b);
	swap(&a, &b);
	printf("������:%d %d\n", a, b);

	return 0;
}