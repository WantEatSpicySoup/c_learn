#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

int main()
 {
	ListNode* head = LTInit();
	LTPushBack(head, 1);
	LTPushBack(head, 2);
	LTPushBack(head, 3);
	LTPushBack(head, 4);
	LTPushBack(head, 5);
	LTPrint(head);
	LTPushFront(head, 0);
	LTPushFront(head, -1);
	LTPushFront(head, -2);
	LTPushFront(head, -3);
	LTPrint(head);
	LTInsert(head, 6);
	LTErase(head, LTFind(head, -2));
	LTPrint(head);
	LTDestroy(head);
	head = NULL;

	return 0;
}