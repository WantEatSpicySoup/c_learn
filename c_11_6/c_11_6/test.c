#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// 使用malloc()创建有10个元素的整形数组
int main1()
{
	int* p_arr = (int*)malloc(40); // malloc()返回值为void*
	if (p_arr == NULL) // 使用NULL需要<stdio.h>头文件
	{
		perror("malloc"); // 会输出内存开辟失败的原因
		return 1;
	}
	// 成功开辟
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p_arr + i));
	}
	// 释放内存
	free(p_arr);
	p_arr = NULL;
	
	return 0;
}

// 使用calloc()创建10个元素的整形数组
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

// 使用realloc()创建10个元素的整形数组
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
	// realloc()追加空间,使用临时变量接受返回值
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
	// 释放空间
	free(p_arr);
	p_arr = NULL;

	return 0;
}