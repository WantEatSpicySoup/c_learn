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

// β��
void LTPushBack(ListNode* phead, LTDataType x);

// ͷ��
void LTPushFront(ListNode* phead, LTDataType x);

// βɾ
void LTPopBack(ListNode* phead);

// ͷɾ
void LTPopFront(ListNode* phead);

// �������
ListNode* BuyLTNode(LTDataType x);

// ��ӡ����
void LTPrint(ListNode* phead);

// �����ʼ��
ListNode* LTInit();

// �ж������Ƿ�Ϊ��
bool LTEmpty(ListNode* phead);

// ����
ListNode* LTFind(ListNode* phead, LTDataType x);

// ��posλ��ǰ����
void LTInsert(ListNode* pos, LTDataType x);

// ɾ��posλ�ý��
void LTErase(ListNode* phead, ListNode* pos);

// ����˫������
void LTDestroy(ListNode* phead);