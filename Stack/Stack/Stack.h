#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// ��ʼ��ջ
void STInit(ST* pst);

// ����ջ
void STDestroy(ST* pst);

// ѹջ
void STPush(ST* pst, STDataType x);

// ��ջ
void STPop(ST* pst);

// ��ȡջ��Ԫ��
STDataType STTop(ST* pst);

// ջ�Ƿ�Ϊ��
bool STEmpty(ST* pst);

// ��̬����
bool STSize(ST* pst);