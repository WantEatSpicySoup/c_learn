#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// ͨ������Ԫ�ص�ַ����������
int main1()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int* pa = arr;
	for (pa = arr; pa < &arr[10]; pa++)
	{
		printf("%d ", *pa);
	}

	return 0;
} 

// ��֤p+i��&arr[i]�ĵ�ַ��ͬ
int main2()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("arr[%d] = %p == %p\n", i, p+i, &arr[i]);
	}

	return 0;
}

// �����ʹ�ö༶ָ��
int main()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;
	int*** ppp = &pp;
	printf("%d", ***ppp);

	return 0;
}