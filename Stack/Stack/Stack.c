#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

// 初始化栈
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

// 销毁栈
void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

// 压栈
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

// 出栈
void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	pst->top--;
}

// 获取栈顶元素
STDataType STTop(ST* pst)
{
	assert(pst);

	return pst->a[pst->top - 1];
}

// 栈是否为空
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// 动态增长
bool STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}