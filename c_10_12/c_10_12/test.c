#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// �ڿ���̨�����hello world
int main1()
{
	printf("hello world\n");
	// printf()��һ���⺯��,�������ڿ���̨���һ���ַ���,ʹ��˫�����������ľ����ַ���,����:"hello world"
	// �����Ҫʹ�ÿ⺯��,����Ҫ�����Ӧ�Ŀ�,ʹ��printf()��������Ҫ����stdio.h��,ʹ��#include�봦���������


	return 0;
}

// ʹ��sizeof()������ڿ���̨����������������͵Ĵ�С
int main2()
{
	printf("%zd\n", sizeof(char));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(long));
	printf("%zd\n", sizeof(long long));
	printf("%zd\n", sizeof(float));
	printf("%zd\n", sizeof(double));

	return 0;
}


int a = 10; // ȫ�ֱ���

// ���������ķ�ʽ
int main3()
{
	// ���¾�Ϊ�ֲ�����
	int age; // ����
	int age2 = 20; // ����
	float weight = 55.5f;
	// �����ͳ�����������Ĭ��ʶ��Ϊdouble����,���������f/F��ʾΪfloat����
	age = 30; // =�Ǹ�ֵ����

	// �����ж���ı����Ǿֲ�����, �����ں�����ı�������ȫ�ֱ���
	int a = 30;
	printf("%d", a);
	// ���ֲ�������ȫ�ֱ���������ͻʱ,ʹ�øñ���������ʹ�þֲ�����,����c���Ե�����
	// ��Ȼ�ֲ���ȫ�����ֿ���һ��,�������ѽ���������Ҫ��ͻ,���ⲻ��Ҫ������

	return 0;
}

// ���������α����ĺ�
int main4()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);

	return 0;
}

// ʹ��scanf��ȡһ��������ֵ,����ʹ��printf������ֵ
int main5()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", a);

	return 0;
}

// �����������������������ʾ
int main6()
{
	int a = 10;
	printf("%d\n", a); // �˴��ᱨ��,����Ϊa������������ֻ���ڱ���a��������Ĵ�������

	return 0;
}    

int main7()
{
	const int n = 10;
	// char str[n]; error:��Ȼn��const������,ӵ���˳���������,��n����һ������

	return 0;
}

// ʹ��#define�����ʶ������,ע��ĩβû�зֺ�;
#define SIZE 10
#define CH 'B'
int main8()
{
	printf("%d\n", SIZE);
	printf("%c\n", CH);

	int arr[SIZE] = {0}; // ���������Ԫ�ض��ᱻ��ʼ��Ϊ0

	return 0;
}

// ����ö�ٳ���
enum COLOR{
	RED = 2,
	YEELOW,
	BLUE
};
int main()
{
	enum COLOR color = RED; // ����ö�ٱ���
	printf("%d", RED);
	printf("%d", YEELOW);
	printf("%d", BLUE);
	printf("%d", color);
}