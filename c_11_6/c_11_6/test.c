#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// ʹ��malloc()������10��Ԫ�ص���������
int main1()
{
	int* p_arr = (int*)malloc(40); // malloc()����ֵΪvoid*
	if (p_arr == NULL) // ʹ��NULL��Ҫ<stdio.h>ͷ�ļ�
	{
		perror("malloc"); // ������ڴ濪��ʧ�ܵ�ԭ��
		return 1;
	}
	// �ɹ�����
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p_arr + i));
	}
	// �ͷ��ڴ�
	free(p_arr);
	p_arr = NULL;
	
	return 0;
}

// ʹ��calloc()����10��Ԫ�ص���������
int main2()
{
	int* p_arr = (int*)calloc(10, sizeof(int));
	if (p_arr == NULL)
	{
		perror("calloc");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p_arr[i]);
	}

	return 0;
}

// ʹ��realloc()����10��Ԫ�ص���������
int main()
{
	int* p_arr = (int*)realloc(NULL, 40);
	if (p_arr == NULL) 
	{
		perror("realloc");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p_arr[i] = i + 1;
	}
	// realloc()׷�ӿռ�,ʹ����ʱ�������ܷ���ֵ
	int* p_tmp = (int*)realloc(p_arr, 20);
	if (p_tmp == NULL)
	{
		perror("realloc");
		return 1;
	}
	else
	{
		p_arr = p_tmp;
		p_tmp = NULL;

	}
	for (i = 0; i < 20; i++)
	{
		p_arr[i] = i + 1;
		printf("%d ", p_arr[i]);
	}
	// �ͷſռ�
	free(p_arr);
	p_arr = NULL;

	return 0;
}