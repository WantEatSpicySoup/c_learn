#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// дһ������,���������������ֵ
int get_max(int x, int y)
{
	return x > y ? x : y;
}
int main1()
{
	int a = 0;
	int b = 0;
	int max = 0;
	printf("�������һ��ֵ:");
	scanf("%d", &a);
	printf("������ڶ���ֵ:");
	scanf("%d", &b);
	max = get_max(a, b);
	printf("���ֵ��%d\n", max);

	return 0;
}

// ����һ������,����ʹ��ѭ���������Ԫ��
int main2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}

	printf("%\n", sizeof(arr));

	return 0;
}

