#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

int main()
{
	SL s = {0};
	SLInit(&s);
	SLPushFront(&s, 6);
	SLPushFront(&s, 5);
	SLPushFront(&s, 4);
	SLPushFront(&s, 3);
	SLPushFront(&s, 2);
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 2);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);
	SLPrint(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLErase(&s, 0);
	SLPrint(&s);
	return 0;
}