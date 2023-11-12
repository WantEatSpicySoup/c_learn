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

// �����������ֵ
void SLTPrint(const SLTNode* phead);
// ͷ��
void SLTPushFront(SLTNode** phead, SLTDataType x);
// β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
// βɾ
void SLTPopBack(SLTNode** pphead);
// ͷɾ
void SLTPopFront(SLTNode** pphead);
// ����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
// ָ��λ�ò���
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
// ɾ��posλ�õ�ֵ
void SLTErase(SLTNode** pphead, SLTNode* pos);
// ɾ��posλ����һ�����
void SLTEraseAfter(SLTNode* pos);
// ��������
void SLTDestroy(SLTNode** pphead);