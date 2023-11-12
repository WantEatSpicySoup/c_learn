#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// 输出链表所有值
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
	// 创建新结点
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	// 判断结点
	if (NULL == newNode)
	{
		perror("SLTPushFront malloc Fial");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// 头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	// 创建新结点
	SLTNode* newNode = BuySLTNode(x);
	// 结点链接
	newNode->next = *pphead;
	newNode->data = x;
	// 更新main()方法中的结构体指针指向
	*pphead = newNode;
}

// 尾插
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

// 尾删
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

// 头删
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead && pphead);
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
}

// 查找
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

// 指定位置插入
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

// 在pos之前插入
void SLTInsertAfter(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode = phead->next;
	phead->next = newNode;
}

// 删除pos位置的值
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

// 删除pos位置下一个结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

// 销毁链表
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
