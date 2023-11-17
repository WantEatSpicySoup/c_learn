#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);

	printf("%d ", QueueFront(&queue));
	QueuePop(&queue);
	printf("%d ", QueueFront(&queue));
	QueuePop(&queue);

	printf("%d ", QueueFront(&queue));
	QueuePop(&queue);

	printf("%d ", QueueFront(&queue));
	QueuePop(&queue);

	printf("%d ", QueueFront(&queue));
}