#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//// ��̬�汾
//#define MAX_SIZE 100
//typedef int SLDataType;
//struct DeqList
//{
//	SLDataType a[MAX_SIZE];
//	int size;
//};

// ��̬�汾
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size; // ���Ա���ЧԪ�ظ���
	int capacity; // ���Ա��������
}SL;

// ���˳���
void SLPrint(const SL* psl);
// ���Ա��ʼ��
void SLInit(SL* psl);
// ���Ա����
void SLDestory(SL* psl);
// ͷ��
void SLPushFront(SL* psl, SLDataType x);
// β��
void SLPushBack(SL* psl, SLDataType x);
// ͷɾ
void SLPopFront(SL* psl);
// βɾ
void SLPopBack(SL* psl);
// ��������
void SLInsert(SL* psl, int pos, SLDataType x);
// ɾ������
void SLErase(SL* psl, int pos);
// ����
int SLFind(SL* psl, SLDataType x);
// �޸�
void SLModify(SL* psl, int pos, SLDataType x);