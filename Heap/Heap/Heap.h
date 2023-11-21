#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

// 初始化
void HeapInit(HP* php);

// 销毁
void HeapDestroy(HP* php);

// 插入数据
void HeapPush(HP* php, HPDataType x);

// 删除堆顶数据
void HeapPop(HP* php);

// 取出堆顶数据
HPDataType HeapTop(HP* php);

// 向上调整
void AdjustUp(HPDataType* pa, int child);

// 判断堆是否为空
bool HeapEmpty(HP* php);

// 交换
void swap(HPDataType* p1, HPDataType* p2);

// 向下调整
void AdjustDown(HPDataType* pa, int size, int parent);

// 堆排序
void HeapSort(HPDataType* pa, int n);