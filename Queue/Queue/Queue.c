#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

// 初始化
void QueueInit(Queue* pq)
{
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}



// 插入数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("QueuePush malloc Fail");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
	pq->size++;
}

// 出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

// 获取对头值
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->data;
}

// 获取队尾值
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->ptail->data;
}

// 获取队列元素个数
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

// 销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	return pq->phead == NULL;
}