#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//输入格式
// 长度为n的绳子，跟着长度为n的01字符串，1代表有结，0代表没有结。

// 如果无法经过若干次翻转相邻的绳位得到一条空结的绳子，那么输出-1；
// 如果可以通过若干次翻转相邻的绳位得到一条空结的绳子，那么输出最小翻转次数；

//1000100->1001000->1010000->1100000->0000000
//翻转等于向前/后挪了一位
//求每两个1之间的距离并相加
int flip(char *arr1)
{
    char *arr = arr1 + 2;
    int n = arr1[0] - '0';
    int i = 0;
    int count = 0;
    int left = -1;
    int right = -1;
    int ret = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == '1')
        {
            if(left == -1)
            {
                left = i;
                count++;
                continue;
            }
            if((left != -1) && (right == -1))
            {
                right = i;
                count++;
            }
            if((left != -1) && (right != -1))
            {
                ret = right - left;
                left = -1;
                right = -1;
            }
        }
    }
    if(count % 2)
    {
        return -1;
    }
    else
    {
        return ret;
    }
}

int main()
{
    char arr[1000] = {'0'};
    gets(arr);
    int ret = flip(arr);
    printf("%d\n", ret);
    return 0;
}