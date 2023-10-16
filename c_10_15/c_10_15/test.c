#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// 使用三目操作符求两个整数的最大值
int main1()
{
	int a = 10;
	int b = 20;
	int max = a > b ? a : b;
	printf("%d\n", max);

	return 0;
}

// 使用typedef将unsigned int类类重命名为u_int
typedef unsigned int u_int;

int main2()
{
	u_int val = 10;
	printf("%u\n", val);

	return 0;
}


// static简单使用
void add()
{
	static int a = 5;
	a++;
	printf("%d ", a);
}

int main3()
{
	int i = 0;
	while (i < 10)
	{
		add();
		i++;
	}

	return 0;
}

// 使用结构体描述一个学生对象
struct Student 
{
	char name[10];
	int age;
	char sex[10];
};

// 使用结构体描述一本书
struct Book 
{
	char name[20];
	char author[10];
	float price;
};
// 简单使用结构体
int main4()
{
	struct Student stu1 = { "曹杰", 20, "男" };
	struct Book book1 = { "《认知觉醒》", "周岭", 50.0 };
	printf("%s %d %s\n", stu1.name, stu1.age, stu1.sex);
	printf("%s %s %.1f\n", book1.name, book1.author, book1.price);
	
	return 0;
}

// 写代码将三个整数数按从大到小输出,例如:2,1,3
int main5()
{
	int a = 2;
	int b = 1;
	int c = 3;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}

// 结构体成员访问方式
struct Duck 
{
	char name[10];
	char sex[10];
	int age;
};

void print1(struct Duck t)
{
	printf("%s %d %s\n", t.name, t.age, t.sex);
}

void print2(struct Duck * t)
{
	printf("%s %d %s\n", (*t).name, (*t).age, (*t).sex);
	printf("%s %d %s\n", t->name, t->age, t->sex);
}

int main()
{
	struct Duck duck = { "郭晓丽", "女", 18 };
	print1(duck);
	print2(&duck);

	return 0;
}