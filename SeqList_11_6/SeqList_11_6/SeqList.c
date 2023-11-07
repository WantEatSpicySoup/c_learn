#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

// 线性表初始化
void SLInit(SL* psl)
{
	assert(psl);
	SLDataType* SLTmp = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (SLTmp == NULL)
	{
		perror("SLInit malloc Fail");
		return;
	}
	psl->a = SLTmp;
	psl->capacity = 4;
	psl->size = 0;
	return;
}

// 线性表清空
void SLDestory(SL* psl)
{
	assert(psl);
	psl->capacity = 0;
	psl->size = 0;
	free(psl->a);
	psl->a = NULL;
}

// 输出顺序表
void SLPrint(const SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

// 检查容量
void SLCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * (psl->capacity * 2));
		if (NULL == tmp)
		{
			perror("SLCheckCapacity relloc Fail");
			return;
		}
		psl->a = tmp;
		psl->capacity *= 2;
	}
}

// 头插
void SLPushFront(SL* psl, SLDataType x)
{
	//assert(psl);
	//SLCheckCapacity(psl);
	//// 挪动数据
	//int end = psl->size - 1;
	//while (end >= 0)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	end--;
	//}
	//psl->a[0] = x;
	//psl->size++;

	SLInsert(psl, 0, x);
}

// 尾插
void SLPushBack(SL* psl, SLDataType x)
{
	//assert(psl);
	//// 检查容量
	//SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	SLInsert(psl, psl->size, x);
}

// 头删
void SLPopFront(SL* psl)
{
	assert(psl);
	int start = 0;
	while (start < psl->size - 1)
	{
		psl->a[start] = psl->a[start - 1];
		start++;
	}
	psl->size--;
}

// 尾删
void SLPopBack(SL* psl)
{
	// 温柔的检查
	//if (psl->size == 0)
	//{
	//	return;
	//}
	 
	// 暴力的检查
	assert(psl->size > 0);
	psl->size--;
}

// 插入数据
void SLInsert(SL* psl, int pos, SLDataType x)
{
	// 其他编译器支持:0 <= pos <= psl->size,但是不建议这样写
	assert(pos >= 0 && pos <= psl->size);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}

// 删除数据
void SLErase(SL* psl, int pos)
{
	assert(pos >= 0 && pos < psl->size);
	int start = pos;
	while (start < psl->size - 1)
	{
		psl->a[start] = psl->a[start];
		start++;
	}
	psl->size--;
}

// 查找
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 修改
void SLModify(SL* psl, int pos, SLDataType x)
{
	assert(psl && pos >= 0 && pos <= psl->size-1);
	psl->a[pos] = x;
}