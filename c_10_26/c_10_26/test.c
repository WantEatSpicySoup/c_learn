#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 打印二进制序列中所有的偶数位和奇数位
int main1()
{
	int a = 15;
	int i = 0;
	printf("奇数位:");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");
	printf("偶数位:");
	for (i = 31; i > 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}

	return 0;
}

// 不允许创建临时变量，交换两个整数的内容
int main2()
{
	int a = 10;
	int b = 20;
	printf("交换前:a = %d, b = %d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	/*a = a ^ b;
	b = a ^ b;
	a = a ^ b;*/
	printf("交换后:a = %d, b = %d\n", a, b);

	return 0;
}

// 输出一个整除的二进制位中有多少个1
int main()
{
	int a = 0;
	scanf("%d", &a);
	int tmp = a;
	int count = 0;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	printf("%d\n", count);

	return 0;
}