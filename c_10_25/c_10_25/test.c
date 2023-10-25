#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int* pa = arr;
	for (pa = arr; pa < &arr[10]; pa++)
	{
		printf("%d ", *pa);
	}

	return 0;
} 