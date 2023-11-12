#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// �����������ֵ
void SLTPrint(const SLTNode* phead)
{
	const SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	// �����½��
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	// �жϽ��
	if (NULL == newNode)
	{
		perror("SLTPushFront malloc Fial");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	// �����½��
	SLTNode* newNode = BuySLTNode(x);
	// �������
	newNode->next = *pphead;
	newNode->data = x;
	// ����main()�����еĽṹ��ָ��ָ��
	*pphead = newNode;
}

// β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newNode = BuySLTNode(x);
	if (NULL == *pphead)
	{
		*pphead = newNode;
		return;
	}
	else
	{
		SLTNode* fail = *pphead;
		while (NULL != fail->next)
		{
			fail = fail->next;
		}
		fail->next = newNode;
	}
}

// βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead && pphead);
	if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* fail = *pphead;
		while (NULL != fail->next->next)
		{
			fail = fail->next;
		}
		free(fail->next);
		fail->next = NULL;
	}

}

// ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead && pphead);
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
}

// ����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (NULL != cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ָ��λ�ò���
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newNode = BuySLTNode(x);
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newNode;
		newNode->next = pos;
	}
}

// ��pos֮ǰ����
void SLTInsertAfter(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode = phead->next;
	phead->next = newNode;
}

// ɾ��posλ�õ�ֵ
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;	 
		}
		prev->next = pos->next;
		free(pos);
	}
}

// ɾ��posλ����һ�����
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

// ��������
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
} 
