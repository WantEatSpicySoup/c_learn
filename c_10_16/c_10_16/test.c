#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// �ж�һ�����Ƿ�Ϊ����
int main1()
{
	// ����������:���ܱ�2����
	int a = 0;
	// ����
	printf("��������Ҫ�жϵ���:");
	scanf("%d", &a);
	// ���
	if (a % 2 == 1)
	{
		printf("%d������\n", a);
	}
	else
	{
		printf("%d��ż��\n", a);
	}

	return 0;
}

// ���1~100�����е�����
int main2()
{
	// 1.����1~100֮�����
	// 2.�ж��Ƿ�Ϊ����,����������
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

// ���1~100�����е�����2
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

// ����һ������,����������ڼ�
int main4()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("��������һ\n");
		break;
	case 2:
		printf("�������ڶ�\n");
		break;
	case 3:
		printf("����������\n");
		break;
	case 4:
		printf("����������\n");
		break;
	case 5:
		printf("����������\n");
		break;
	case 6:
		printf("����������\n");
		break;
	case 7:
		printf("����������\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	return 0;
}

// ����1~5,���������/����6~7,�����Ϣ��
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
		printf("�����ǹ�����\n");
		break;
	case 6:
	case 7:
		printf("��������Ϣ��\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	return 0;
}

// �ڿ���̨���1~10
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

// ��ʹ��getchar()
int main7()
{
	int ch = getchar();
	putchar(ch);

	return 0;
}

// ����������'\n'
int main8()
{
	char str[20] = "";
	scanf("%s", str);
	
	// ������뻺������'\n'
	while (getchar() != '\n')
	{
		;
	}

	char ch = 0;
	printf("��ȷ��(Y/N):");
	scanf("%c", &ch);
	if ('Y' == ch)
	{
		printf("��½�ɹ�!");
	}
	else
	{
		printf("��¼ʧ��!");
	}

	return 0;
 }


// ��ӡ1-100֮������3�ı���������
int main9()
{
	// 1.1��100֮�����е����ֽ����ж�
	//int i = 1;
	//while (i <= 100)
	//{
	//	// �ж��Ƿ�Ϊ3�ı���
	//	if (i % 3 == 0)
	//	{
	//		printf("%d ", i);
	//	}
	//	i++;
	//}

	// 2.i��3��ʼ,ÿ�μ�3Ȼ�����,��������Ͷ���3�ı���
	int i = 3;
	while (i <= 100)
	{
		printf("%d ", i);
		i += 3;
	}

	return 0;
}

// ��10 �����������ֵ
int main10()
{
	int arr[10] = {1,2,3,4,5,10,9,8,7,6}; // ���ֵ:10
	int max = arr[0]; // �����ֵ��ʽ�������ܲ�׼ȷ,�ﲻ����С�������ı�׼
	int i = 1; // ����max�����Ѿ��������±�1��ֵ,��ֱ�Ӵ�����ڶ���Ԫ�ؿ�ʼ
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

// ��ӡ100~200֮�������
int main11()
{
	// �����ж�����:ֻ�ܱ�1/��������
	// ����100~200֮�������
	int i = 101; // ż��һ����������,���Դ�101��ʼ
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
		i += 2; // ��֤ÿ���жϵĶ�������
	}

	return 0;
}

// ��ӡ1000�굽2000��֮�������
int main12()
{
	// �����ж�����:�ܱ�4�������ǲ��ܱ�100����/�ܱ�400����
	int year = 1000;
	while (year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			printf("%d ", year);
		}
		year += 2; // ������һ����������
	}

	return 0;
}

// ����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
int main()
{
	double i = 1.0; // ����
	double j = 1.0; // ��ĸ
	double ret = 0.0; // ������
	while (j <= 100.0)
	{
		ret += i / j;
		j++;
		i = -i;
	}
	printf("%lf", ret);

	return 0;
}
