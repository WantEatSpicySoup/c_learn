#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ��ӡ���������������е�ż��λ������λ
int main1()
{
	int a = 15;
	int i = 0;
	printf("����λ:");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");
	printf("ż��λ:");
	for (i = 31; i > 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}

	return 0;
}

// ����������ʱ������������������������
int main2()
{
	int a = 10;
	int b = 20;
	printf("����ǰ:a = %d, b = %d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	/*a = a ^ b;
	b = a ^ b;
	a = a ^ b;*/
	printf("������:a = %d, b = %d\n", a, b);

	return 0;
}

// ���һ�������Ķ�����λ���ж��ٸ�1
int main()
{
	int a = 0;
	scanf("%d", &a);
	int tmp = a;
	int count = 0;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	printf("%d\n", count);

	return 0;
}