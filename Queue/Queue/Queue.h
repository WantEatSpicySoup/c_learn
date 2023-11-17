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

// 初始化
void QueueInit(Queue* pq);

// 销毁队列
void QueueDestroy(Queue* pq);

// 插入数据
void QueuePush(Queue* pq, QDataType x);

// 出队列
void QueuePop(Queue* pq);

// 判断队列是否为空
bool QueueEmpty(Queue* pq);

// 获取对头值
QDataType QueueFront(Queue* pq);

// 获取队尾值
QDataType QueueBack(Queue* pq);

// 获取队列元素个数
int QueueSize(Queue* pq);