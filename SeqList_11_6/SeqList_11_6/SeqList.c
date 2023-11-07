#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

// ���Ա��ʼ��
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

// ���Ա����
void SLDestory(SL* psl)
{
	assert(psl);
	psl->capacity = 0;
	psl->size = 0;
	free(psl->a);
	psl->a = NULL;
}

// ���˳���
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

// �������
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

// ͷ��
void SLPushFront(SL* psl, SLDataType x)
{
	//assert(psl);
	//SLCheckCapacity(psl);
	//// Ų������
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

// β��
void SLPushBack(SL* psl, SLDataType x)
{
	//assert(psl);
	//// �������
	//SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	SLInsert(psl, psl->size, x);
}

// ͷɾ
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

// βɾ
void SLPopBack(SL* psl)
{
	// ����ļ��
	//if (psl->size == 0)
	//{
	//	return;
	//}
	 
	// �����ļ��
	assert(psl->size > 0);
	psl->size--;
}

// ��������
void SLInsert(SL* psl, int pos, SLDataType x)
{
	// ����������֧��:0 <= pos <= psl->size,���ǲ���������д
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

// ɾ������
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

// ����
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

// �޸�
void SLModify(SL* psl, int pos, SLDataType x)
{
	assert(psl && pos >= 0 && pos <= psl->size-1);
	psl->a[pos] = x;
}