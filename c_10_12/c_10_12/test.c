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
int main9()
{
	enum COLOR color = RED; // ����ö�ٱ���
	printf("%d", RED);
	printf("%d", YEELOW);
	printf("%d", BLUE);
	printf("%d", color);

	return 0;
}

// ��ʹ���ַ���
int main10()
{
	// ��δ洢abcdef��6���ַ�?
	// 1.ʹ���ַ�����
	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// 2.ʹ���ַ�����ʼ��
	char str[] = "abcdef";

	printf("%s\n", arr);
	printf("%s\n", str);

	return 0;
} 


#include <string.h>
// ʹ��string.h�е��ַ�������
int main11()
{
	char str[] = "abcdef";
	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t len1 = strlen(str);
	size_t len2 = strlen(arr);
	printf("%zd\n", len1);
	printf("%zd\n", len2);

	return 0;
}

// ���ʹ��ת���ַ�
int main12()
{
	printf("d:\\test\\test.c\n"); // ��'\'����ת��,����Դ�ӡ
	printf("%c\n", '\'\''); // ��ӡ������
	printf("%s\n", "\"\""); // ��ӡ˫����

	return 0;
}

// ��ʹ��if/else���
int main13()
{
	int flag = 0;
	printf("����ú�ѧϰ��?(1/0)");
	scanf("%d", &flag);
	if (flag == 1)
	{
		printf("�ú�ѧϰ,��ȡ���ջ�ȡ����offer!\n");
	}
	else if (flag == 0) {
		printf("ϣ���㻹�Ǻú�ѧϰ,�ҵ��ù���!\n");
	}
	else
	{
		printf("�������,ѡ��ֻ��1/0\n");
	}

	return 0;
}

// ��ʹ��whileѭ�����
int main()
{
	// �ڿ���̨���1~5000
	int i = 0;
	while (i <= 5000)
	{
		printf("%d ", i);
		i++;
	}

	return 0;
}