#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

// 初始化
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

// 销毁
void HeapDestroy(HP* php)
{
	assert(php);
	assert(php->a);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

// 交换
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 向上调整
void AdjustUp(HPDataType* pa, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (pa[child] < pa[parent])
		{
			swap(&pa[child], &pa[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 向下调整
void AdjustDown(HPDataType* pa, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && pa[child + 1] < pa[child])
		{
			child++;
		}
		if (pa[child] < pa[parent])
		{
			swap(&pa[child], &pa[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 插入数据
void HeapPush(HP* php, HPDataType x)
{
	assert(php);


	// 检查堆空间是否足够/扩容
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("HeapPush realloc Fail");
			return;
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}

	// 插入数据
	php->a[php->size] = x;
	php->size++;

	// 向上调整(将逻辑结构调整为小根堆
	AdjustUp(php->a, php->size - 1);
}

// 删除堆顶数据(堆顶数据)
void HeapPop(HP* php)
{
	/*
	1.堆顶和堆底进行交换
	2.堆顶进行向下调整
	*/
	assert(php);
	assert(!HeapEmpty(php));
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

// 取出堆顶数据
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->a);

	return php->a[0];
}

// 判断堆是否为空
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

// 返回堆的元素个数
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

// 堆排序
void HeapSort(HPDataType* pa, int n)
{
	// 升序--建大堆
	// 降序--建小堆
	/*int i = 0;
	for (i = 1; i < n; i++)
	{
		AdjustUp(pa, i);
	}*/

	// 向下建堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(pa, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&pa[0], &pa[end]);
		AdjustDown(pa, end, 0);
		end--;
	}
}