#define _CRT_SECURE_NO_WARNINGS 1

// ʹ��forѭ�����1~10��ֵ
#include <stdio.h>

int main1()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}

	return 0;
}

// ʹ��forѭ����������������ֵ
int main2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

// ʹ��do whileѭ�����1~10��ֵ
int main3()
{
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	}while (i <= 10);

	return 0;
}

// ����n�Ľ׳�
int main4()
{
	int n = 0;
	int ret = 1;
	printf("��������Ҫ����Ľ׳�:");
	scanf("%d", &n);
	int i = 0;
	for (i = 2; i <= n; i++)
	{
		ret *= i;
	}
	printf("ret = %d", ret);

	return 0;
}

// ����1!+2!+3!+4!+5!....+10! -- ʹ������forѭ��
int main5()
{
	int i = 0;
	int ret = 1;
	for (i = 2; i <= 10; i++)
	{
		int j = 0;
		int tmp = 1;
		for (j = 2; j <= i; j++)
		{
			tmp *= j;
		}
		ret += tmp;
	}
	printf("%d", ret);

	return 0;
}

// ����1!+2!+3!+4!+5!....+10! -- ʹ��һ��forѭ��
int main6()
{
	int i = 0;
	int ret = 1;
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		ret *= i;
		sum += ret;
	}
	printf("%d", sum);

	return 0;
}

// ��һ�����������в���ĳ�����������key
int main7()
{
	int key = 11;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] == key)
		{
			printf("�ҵ���,�±�Ϊ%d\n", i);
			break;
		}
	}
	if (i == 10)
	{
		printf("û���ҵ�\n");
	}

	return 0;
}

// ���ֲ��� binary_search
int main8()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 5;
	int left = 0;
	int right = 9;
	int flag = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("�ҵ���,�±�Ϊ%d", mid);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("û���ҵ�!\n");
	}

	return 0;
}

// ��ʾһ���ַ������������м���
#include <windows.h>
#include <string.h>

int main9()
{
	char arr1[] = "welcome chinese!!!!!";
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{

		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
	}
	printf("%s\n", arr2);

	return 0;
}

// ģ���û���¼,�����������֮���˳�����
#define USER_PASSWORD "123456"

int main()
{
	char input[20] = {0};
	int i = 0;
	while (i < 3)
	{
		printf("�������������:\n");
		scanf("%s", input);
		if (strcmp(input, USER_PASSWORD) == 0)
		{
			printf("��½�ɹ�!!!\n");
			break;
		}
		else
		{
			printf("�������!!!\n");
		}
		i++;
	}
	if (3 == i)
	{
		printf("��¼ʧ��,�����˳�!!!");
	}

	return 0;
}