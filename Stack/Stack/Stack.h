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

// 初始化栈
void STInit(ST* pst);

// 销毁栈
void STDestroy(ST* pst);

// 压栈
void STPush(ST* pst, STDataType x);

// 出栈
void STPop(ST* pst);

// 获取栈顶元素
STDataType STTop(ST* pst);

// 栈是否为空
bool STEmpty(ST* pst);

// 动态增长
bool STSize(ST* pst);