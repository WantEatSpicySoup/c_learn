#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 判断一个数是否为奇数
int main1()
{
	// 奇数的条件:不能被2整除
	int a = 0;
	// 输入
	printf("请输入你要判断的数:");
	scanf("%d", &a);
	// 输出
	if (a % 2 == 1)
	{
		printf("%d是奇数\n", a);
	}
	else
	{
		printf("%d是偶数\n", a);
	}

	return 0;
}

// 输出1~100中所有的奇数
int main2()
{
	// 1.生成1~100之间的数
	// 2.判断是否为奇数,如果是则输出
	int i = 0;
	while (i <= 100)
	{
		if (i % 2 == 1)
		{
			printf("%d ", i);
		}
		i++;
	}

	return 0;
}

// 输出1~100中所有的奇数2
int main3()
{
	int i = 1;
	while (i <= 100)
	{
		printf("%d ", i);
		i += 2;
	}

	return 0;
}

// 输入一个数字,输出今天星期几
int main4()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("今天星期一\n");
		break;
	case 2:
		printf("今天星期二\n");
		break;
	case 3:
		printf("今天星期三\n");
		break;
	case 4:
		printf("今天星期四\n");
		break;
	case 5:
		printf("今天星期五\n");
		break;
	case 6:
		printf("今天星期六\n");
		break;
	case 7:
		printf("今天星期七\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	return 0;
}

// 输入1~5,输出工作日/输入6~7,输出休息日
int main5()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("今天是工作日\n");
		break;
	case 6:
	case 7:
		printf("今天是休息日\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	return 0;
}

// 在控制台输出1~10
int main6()
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}

	return 0;
}

// 简单使用getchar()
int main7()
{
	int ch = getchar();
	putchar(ch);

	return 0;
}

// 清理缓冲区的'\n'
int main8()
{
	char str[20] = "";
	scanf("%s", str);
	
	// 清空输入缓冲区的'\n'
	while (getchar() != '\n')
	{
		;
	}

	char ch = 0;
	printf("请确认(Y/N):");
	scanf("%c", &ch);
	if ('Y' == ch)
	{
		printf("登陆成功!");
	}
	else
	{
		printf("登录失败!");
	}

	return 0;
 }


// 打印1-100之间所有3的倍数的数字
int main9()
{
	// 1.1到100之间所有的数字进行判断
	//int i = 1;
	//while (i <= 100)
	//{
	//	// 判断是否为3的倍数
	//	if (i % 3 == 0)
	//	{
	//		printf("%d ", i);
	//	}
	//	i++;
	//}

	// 2.i从3开始,每次加3然后输出,这样输出就都是3的倍数
	int i = 3;
	while (i <= 100)
	{
		printf("%d ", i);
		i += 3;
	}

	return 0;
}

// 求10 个整数中最大值
int main10()
{
	int arr[10] = {1,2,3,4,5,10,9,8,7,6}; // 最大值:10
	int max = arr[0]; // 如果赋值显式常量可能不准确,达不到最小或者最大的标准
	int i = 1; // 由于max变量已经记载了下标1的值,就直接从数组第二个元素开始
	while (i < 10)
	{
		if (arr[i] > max)
		{
			int tmp = arr[i];
			arr[i] = max;
			max = tmp;
		}
		i++;
	}
	printf("max = %d\n", max);

	return 0;
}

// 打印100~200之间的素数
int main11()
{
	// 素数判断条件:只能被1/自身整除
	// 生成100~200之间的数字
	int i = 101; // 偶数一定不是素数,所以从101开始
	while (i < 200) // 
	{
		int j = 2;
		while (j < i)
		{
			if (i % j == 0)
			{
				break;
			}
			j++;
		}
		if (i == j)
		{
			printf("%d ", i);
		}
		i += 2; // 保证每次判断的都是奇数
	}

	return 0;
}

// 打印1000年到2000年之间的闰年
int main12()
{
	// 闰年判断条件:能被4整除但是不能被100整除/能被400整除
	int year = 1000;
	while (year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			printf("%d ", year);
		}
		year += 2; // 奇数年一定不是闰年
	}

	return 0;
}

// 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
int main()
{
	double i = 1.0; // 分子
	double j = 1.0; // 分母
	double ret = 0.0; // 计算结果
	while (j <= 100.0)
	{
		ret += i / j;
		j++;
		i = -i;
	}
	printf("%lf", ret);

	return 0;
}
