#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 写一个函数,求两个整数的最大值
int get_max(int x, int y)
{
	return x > y ? x : y;
}
int main1()
{
	int a = 0;
	int b = 0;
	int max = 0;
	printf("请输入第一个值:");
	scanf("%d", &a);
	printf("请输入第二个值:");
	scanf("%d", &b);
	max = get_max(a, b);
	printf("最大值是%d\n", max);

	return 0;
}

// 创建一个数组,并且使用循环输出所有元素
int main2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}

	printf("%\n", sizeof(arr));

	return 0;
}

