#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//// 静态版本
//#define MAX_SIZE 100
//typedef int SLDataType;
//struct DeqList
//{
//	SLDataType a[MAX_SIZE];
//	int size;
//};

// 动态版本
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size; // 线性表有效元素个数
	int capacity; // 线性表最大容量
}SL;

// 输出顺序表
void SLPrint(const SL* psl);
// 线性表初始化
void SLInit(SL* psl);
// 线性表清空
void SLDestory(SL* psl);
// 头插
void SLPushFront(SL* psl, SLDataType x);
// 尾插
void SLPushBack(SL* psl, SLDataType x);
// 头删
void SLPopFront(SL* psl);
// 尾删
void SLPopBack(SL* psl);
// 插入数据
void SLInsert(SL* psl, int pos, SLDataType x);
// 删除数据
void SLErase(SL* psl, int pos);
// 查找
int SLFind(SL* psl, SLDataType x);
// 修改
void SLModify(SL* psl, int pos, SLDataType x);