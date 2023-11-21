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

// ��ʼ��
void HeapInit(HP* php);

// ����
void HeapDestroy(HP* php);

// ��������
void HeapPush(HP* php, HPDataType x);

// ɾ���Ѷ�����
void HeapPop(HP* php);

// ȡ���Ѷ�����
HPDataType HeapTop(HP* php);

// ���ϵ���
void AdjustUp(HPDataType* pa, int child);

// �ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php);

// ����
void swap(HPDataType* p1, HPDataType* p2);

// ���µ���
void AdjustDown(HPDataType* pa, int size, int parent);

// ������
void HeapSort(HPDataType* pa, int n);