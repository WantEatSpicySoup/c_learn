#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 输出链表所有值
void SLTPrint(const SLTNode* phead);
// 头插
void SLTPushFront(SLTNode** phead, SLTDataType x);
// 尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);
// 尾删
void SLTPopBack(SLTNode** pphead);
// 头删
void SLTPopFront(SLTNode** pphead);
// 查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
// 指定位置插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
// 删除pos位置的值
void SLTErase(SLTNode** pphead, SLTNode* pos);
// 删除pos位置下一个结点
void SLTEraseAfter(SLTNode* pos);
// 销毁链表
void SLTDestroy(SLTNode** pphead);