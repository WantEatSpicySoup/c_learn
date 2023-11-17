#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

// ��ʼ��
void QueueInit(Queue* pq)
{
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}



// ��������
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

// ������
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

// ��ȡ��ͷֵ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->data;
}

// ��ȡ��βֵ
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->ptail->data;
}

// ��ȡ����Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

// ���ٶ���
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

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	return pq->phead == NULL;
}