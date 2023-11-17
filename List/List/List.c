#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

// 链表初始化
ListNode* LTInit()
{
	ListNode* phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;
	
	return phead;
}

// 尾插
void LTPushBack(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newNode = BuyLTNode(x);
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;*/
	
	LTInsert(phead, x);
}

// 头插
void LTPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	/*ListNode* newNode = BuyLTNode(x);
	newNode->next = phead->next;
	newNode->prev = phead;
	phead->next->prev = newNode;
	phead->next = newNode;*/

	LTInsert(phead->next, x);
}

// 尾删
void LTPopBack(ListNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	/*ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);*/

	LTErase(phead, phead->prev);
}

// 头删
void LTPopFront(ListNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	/*ListNode* del = phead->next;
	ListNode* next = del->next;
	next->prev = del->prev;
	phead->next = next;
	free(del);*/

	LTErase(phead, phead->next);
}

// 创建结点 
ListNode* BuyLTNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("BuyLTNode malloc Fail");
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
} 

// 打印链表
void LTPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while(cur != phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 判断链表是否为空
bool LTEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

// 查找
ListNode* LTFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

// 在pos位置前插入
void LTInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newNode = BuyLTNode(x);
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}

// 删除pos位置结点
void LTErase(ListNode* phead, ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

// 销毁双向链表
void LTDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}