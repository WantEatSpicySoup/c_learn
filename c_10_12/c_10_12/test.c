#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 在控制台中输出hello world
int main1()
{
	printf("hello world\n");
	// printf()是一个库函数,功能是在控制台输出一个字符串,使用双引号引起来的就是字符串,例如:"hello world"
	// 如果需要使用库函数,则需要引入对应的库,使用printf()函数则需要包含stdio.h库,使用#include与处理命令包含


	return 0;
}

// 使用sizeof()运算符在控制台中输出各种数据类型的大小
int main2()
{
	printf("%zd\n", sizeof(char));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(long));
	printf("%zd\n", sizeof(long long));
	printf("%zd\n", sizeof(float));
	printf("%zd\n", sizeof(double));

	return 0;
}


int a = 10; // 全局变量

// 创建变量的方式
int main3()
{
	// 以下均为局部变量
	int age; // 年龄
	int age2 = 20; // 年龄
	float weight = 55.5f;
	// 浮点型常量编译器会默认识别为double类型,常量后加上f/F表示为float类型
	age = 30; // =是赋值符号

	// 函数中定义的变量是局部变量, 定义在函数外的变量叫做全局变量
	int a = 30;
	printf("%d", a);
	// 当局部变量和全局变量命名冲突时,使用该变量会优先使用局部变量,这是c语言的特性
	// 虽然局部和全局名字可以一样,但还是已建议命名不要冲突,避免不必要的争议

	return 0;
}

// 求两个整形变量的和
int main4()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf("%d %d", &a, &b);
	sum = a + b;
	printf("sum = %d\n", sum);

	return 0;
}

// 使用scanf读取一个整数的值,并且使用printf输出这个值
int main5()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", a);

	return 0;
}

// 变量的作用域和生命周期演示
int main6()
{
	int a = 10;
	printf("%d\n", a); // 此处会报错,是因为a变量的作用域只限于变量a定义区域的大括号内

	return 0;
}    

int main7()
{
	const int n = 10;
	// char str[n]; error:虽然n被const修饰了,拥有了常量的属性,但n还是一个变量

	return 0;
}

// 使用#define定义标识符常量,注意末尾没有分号;
#define SIZE 10
#define CH 'B'
int main8()
{
	printf("%d\n", SIZE);
	printf("%c\n", CH);

	int arr[SIZE] = {0}; // 数组的所有元素都会被初始化为0

	return 0;
}

// 定义枚举常量
enum COLOR{
	RED = 2,
	YEELOW,
	BLUE
};
int main9()
{
	enum COLOR color = RED; // 定义枚举变量
	printf("%d", RED);
	printf("%d", YEELOW);
	printf("%d", BLUE);
	printf("%d", color);

	return 0;
}

// 简单使用字符串
int main10()
{
	// 如何存储abcdef这6个字符?
	// 1.使用字符数组
	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// 2.使用字符串初始化
	char str[] = "abcdef";

	printf("%s\n", arr);
	printf("%s\n", str);

	return 0;
} 


#include <string.h>
// 使用string.h中的字符串函数
int main11()
{
	char str[] = "abcdef";
	char arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t len1 = strlen(str);
	size_t len2 = strlen(arr);
	printf("%zd\n", len1);
	printf("%zd\n", len2);

	return 0;
}

// 如何使用转义字符
int main12()
{
	printf("d:\\test\\test.c\n"); // 将'\'进行转义,则可以打印
	printf("%c\n", '\'\''); // 打印单引号
	printf("%s\n", "\"\""); // 打印双引号

	return 0;
}

// 简单使用if/else语句
int main13()
{
	int flag = 0;
	printf("你想好好学习吗?(1/0)");
	scanf("%d", &flag);
	if (flag == 1)
	{
		printf("好好学习,争取早日获取满意offer!\n");
	}
	else if (flag == 0) {
		printf("希望你还是好好学习,找到好工作!\n");
	}
	else
	{
		printf("输入错误,选项只有1/0\n");
	}

	return 0;
}

// 简单使用while循环语句
int main()
{
	// 在控制台输出1~5000
	int i = 0;
	while (i <= 5000)
	{
		printf("%d ", i);
		i++;
	}

	return 0;
}