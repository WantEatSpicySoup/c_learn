#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

// ��ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

// ����
void HeapDestroy(HP* php)
{
	assert(php);
	assert(php->a);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

// ����
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// ���ϵ���
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

// ���µ���
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

// ��������
void HeapPush(HP* php, HPDataType x)
{
	assert(php);


	// ���ѿռ��Ƿ��㹻/����
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

	// ��������
	php->a[php->size] = x;
	php->size++;

	// ���ϵ���(���߼��ṹ����ΪС����
	AdjustUp(php->a, php->size - 1);
}

// ɾ���Ѷ�����(�Ѷ�����)
void HeapPop(HP* php)
{
	/*
	1.�Ѷ��Ͷѵ׽��н���
	2.�Ѷ��������µ���
	*/
	assert(php);
	assert(!HeapEmpty(php));
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

// ȡ���Ѷ�����
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->a);

	return php->a[0];
}

// �ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

// ���ضѵ�Ԫ�ظ���
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

// ������
void HeapSort(HPDataType* pa, int n)
{
	// ����--�����
	// ����--��С��
	/*int i = 0;
	for (i = 1; i < n; i++)
	{
		AdjustUp(pa, i);
	}*/

	// ���½���
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