#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

// 尾插
void LTPushBack(ListNode* phead, LTDataType x);

// 头插
void LTPushFront(ListNode* phead, LTDataType x);

// 尾删
void LTPopBack(ListNode* phead);

// 头删
void LTPopFront(ListNode* phead);

// 创建结点
ListNode* BuyLTNode(LTDataType x);

// 打印链表
void LTPrint(ListNode* phead);

// 链表初始化
ListNode* LTInit();

// 判断链表是否为空
bool LTEmpty(ListNode* phead);

// 查找
ListNode* LTFind(ListNode* phead, LTDataType x);

// 在pos位置前插入
void LTInsert(ListNode* pos, LTDataType x);

// 删除pos位置结点
void LTErase(ListNode* phead, ListNode* pos);

// 销毁双向链表
void LTDestroy(ListNode* phead);