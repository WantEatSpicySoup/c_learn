#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	HeapSort(arr, 10);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
 }