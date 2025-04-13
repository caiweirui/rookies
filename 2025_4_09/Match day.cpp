#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 1. 求出两个日期之间的所有日期，遍历所有的年份之间的日期，满足在之间的就进行操作
// 2. 求出星期数
// 3. 和日期相对应，输出吻合日的总数和每个星期的“吻合日”

static int arr1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int arr2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year)
{
    return year % 400 == 0 ||(year % 4 == 0) && (year % 100 != 0);
}

//判断星期数
int weekday(int dday)
{
    if(dday % 7)
    {
        return dday % 7;
    }
    else
    {
        return 7;
    }
}

int days(int year, int month, int day)
{
    int dday = 0;
    int i = 0;
    for(i = 1900; i < year; i++)
    {
        if(is_leap_year(i))
        {
            dday += 366;
        }
        else
        {
            dday +=365;
        }
    }
    for(i = 0; i < month; i++)
    {
        if(is_leap_year(year))
        {
            dday += arr2[i];
        }
        else
        {
            dday += arr1[i];
        }
    }

    dday = dday + day - 1;

    return dday;

}

int main()
{
    int year1 = 0;
    int month1 = 0;
    int day1 = 0;
    int year2 = 0;
    int month2 = 0;
    int day2 = 0;

    int i = 0;
    int j = 0;
    int k = 0;

    while(scanf("%d %d %d", &year1, &month1, &day1) != EOF)
    {
        getchar();
        scanf("%d %d %d", &year2, &month2, &day2);
        int days1 = days(year1, month1, day1) + 1;
        int days2 = days(year2, month2, day2) + 1;
        int daysijk = 0;

        int arr[8] = {0};

        for(i = year1; i <= year2; i++)
        {
            for(j = 1; j <=12; j++)
            {
                for(k = 1; k <= (is_leap_year(i) ? arr2[j] : arr1[j]); k++)
                {
                    daysijk = days(i, j ,k) + 1;
                    if(daysijk >= days1 && daysijk < days2)
                    {
                        if(k % 10 == weekday(daysijk))
                        {
                            arr[weekday(daysijk)]++;
                            arr[0]++; 
                        }
                    }

                }
            }
        }
        int t = 0;
        for(t = 0; t < 8; t++)
        {
            printf("%d ", arr[t]);
        }
        printf("\n");
    }


    return 0;
}