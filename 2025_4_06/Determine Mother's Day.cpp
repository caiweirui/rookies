#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

//根据日期求星期 1900年1月1日为星期1

int is_leap_year(int year)
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

int weekday(const int year, const int month)
{
    int i = 0;
    int day1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dday = 1;
    //判断和1900差多少年
    for(i = 1900; i < year; i++)
    {
        if(is_leap_year(i))
        {
            dday += 366; 
        }
        else
        {
            dday += 365;
        }
    }
    //计算今年过了几个月
    for(i = 1; i < month; i++)
    {
        if(is_leap_year(year))
        {
            dday += day2[i - 1];
        }
        else
        {
            dday += day1[i - 1];
        }
    }
    int j = 0;
    int count = 0;
    while(count!=2)
    {
        if((dday + j) % 7 == 5)
        {
            count++;
        }
        j++;
    }
    return j + 2;
}

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    scanf("%d", &year);
    month = 5;
    printf("%d\n", weekday(year, month));
    return 0;
}