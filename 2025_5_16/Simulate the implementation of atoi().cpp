#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

enum Status
{
    VALID,
    INVALID
}status;

// ①	可以用于转换正负数
// ②	遇到字母会停止
// ③	数字前面的空格会无视
// ④	超过int的可表示范围显示极值

int my_atoi(const char* str)
{
    // 空指针
    assert(str);

    int begin = 0;
    // 无视数字或符号前面的空格
    while(isspace(str[begin]))
    {
        begin++;
    }

    // 判断正负数
    int sf = str[begin];
    if(sf == '-')
    {
        sf = 1;
        begin++;
    }
    else
    {
        begin = (sf == '+') + begin;
        sf = 0;
    }

    int i = begin;
    long long ret = 0;

    // 空字符串
    if(strlen(str + begin) == 0)
    {
        return INVALID;
    }
    else
    {
        status = VALID;
    }

    while(isdigit(str[i]))
    {
        if(ret <= (long long)2147483647 + sf)
        {
            ret = ret * 10 - '0' + str[i++];
        }
        else
        {
            return 2147483647 * (sf ? -1 : 1) - sf;
        }
    }
    return ret * (sf ? -1 : 1);
}

int main()
{
    char* arr = (char*)calloc(1000, sizeof(char));
    arr = fgets(arr, 1000, stdin);
    int std = atoi(arr);
    int ret = my_atoi(arr);
    fprintf(stdout, "%d\n", std);
    fprintf(stdout, "%d\n", ret);
    return 0;
}