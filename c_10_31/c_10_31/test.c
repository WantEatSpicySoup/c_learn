#define _CRT_SECURE_NO_WARNINGS 1

// 有序序列判断
#include <stdio.h>

int main1()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    // int arr[n]
    int arr[50] = { 0 };
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int up_flag = 0;
    int down_flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            up_flag = 1;
        }
        if (arr[i] < arr[i + 1])
        {
            down_flag = 1;
        }
    }
    if (up_flag && down_flag)
    {
        printf("unsorted\n");
    }
    else {
        {
            printf("sorted\n");
        }
    }

    return 0;
}

// 获得月份天数
int is_leap_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main2()
{

    /*
        平年2月28天, 闰年2月29天
        4 6 9 11 各是30天
        1 2 5 7 8 10 12 各是31天
    */
    int year = 0;
    int month = 0;
    while (scanf("%d %d", &year, &month) == 2)
    {
        int flag = is_leap_year(year); // 判断是否是闰年
        switch (month)
        {
        case 2:
            if (flag)
            {
                printf("29\n");
            }
            else
            {
                printf("28\n");
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30\n");
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31\n");
            break;
        }
    }

    return 0;
}


// 输出杨辉三角形
#define ROW 10

void init_arr(int arr[ROW][ROW])
{
    //int i = 0;
    //for (i = 0; i < ROW; i++)
    //{
    //    int j = 0;
    //    for (j = 0; j < ROW; j++)
    //    {
    //        if (j == 0 || i == j)
    //        {
    //            arr[i][j] = 1;
    //        }
    //    }
    //}
    int i = 0;
    for (i = 0; i < ROW; i++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
}

void calc_arr(int arr[ROW][ROW])
{
    int i = 0;
    for (i = 2; i < ROW; i++)
    {
        int j = 0;
        for (j = 1; j < ROW - 1; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}

int main3()
{
    int arr[ROW][ROW] = { 0 };
    int i = 0;
    init_arr(arr);
    calc_arr(arr);
    for (i = 0; i < ROW; i++)
    {
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
int main4()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    for (a = 1; a <= 5; a++)
    {
        for (b = 1; b <= 5; b++)
        {
            for (c = 1; c <= 5; c++)
            {
                for (d = 1; d <= 5; d++)
                {
                    for (e = 1; e <= 5; e++)
                    {
                        if (((b == 2) + (a == 3)) == 1 &&
                            (((b == 2) + (e == 4)) == 1) &&
                            (((c == 1) + (d == 2)) == 1) &&
                            (((c == 5) + (d == 3)) == 1) &&
                            (((e == 4) + (a == 1)) == 1))
                        {
                            if ((a * b * c * d * e) == 120)
                            {
                                printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}


//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

int main()
{
    char killer = 0;
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if (((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3)
        {
            printf("%c", killer);
            break;
        }
    }

    return 0;
}