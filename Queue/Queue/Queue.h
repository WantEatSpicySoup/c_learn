#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

// ��ʼ��
void QueueInit(Queue* pq);

// ���ٶ���
void QueueDestroy(Queue* pq);

// ��������
void QueuePush(Queue* pq, QDataType x);

// ������
void QueuePop(Queue* pq);

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

// ��ȡ��ͷֵ
QDataType QueueFront(Queue* pq);

// ��ȡ��βֵ
QDataType QueueBack(Queue* pq);

// ��ȡ����Ԫ�ظ���
int QueueSize(Queue* pq);