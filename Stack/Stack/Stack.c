#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

// ��ʼ��ջ
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

// ����ջ
void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

// ѹջ
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("STPush realloc Fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

// ��ջ
void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	pst->top--;
}

// ��ȡջ��Ԫ��
STDataType STTop(ST* pst)
{
	assert(pst);

	return pst->a[pst->top - 1];
}

// ջ�Ƿ�Ϊ��
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// ��̬����
bool STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}