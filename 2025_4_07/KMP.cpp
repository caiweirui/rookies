#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

// 给定字符串S与T，规定S上操作REPLACE(i, x)表示为将S中第i个字符更改为x.

// 求最小操作次数a，使得T为S的子串。当任意次操作均不能使得T为S字串时，输出-1.

//幼稚算法：让字串的第一位和主串第一位对齐，比较两个串，如果发现不相等
//字串后移，重新比较
//幼稚原因：指针的回溯

//KMP算法：当发现指针不对等，可以得出两个结论：
//指针左边位置的数据都是对等的
//找到公共前后缀（核心）
//把前缀移动到后缀所在的地方，指针重新从后缀之后开始比较
//找到最长公共前后缀，且长度要小于左边字串的长度

//字串从数组下标1开始的
//1号位发生不匹配，让1号位和主串的下一位进行比较
//2号位发生不匹配，1号位和主串当前位置进行比较
//3号位和以后发生不匹配，让1号位和主串的最长公共前后缀长度的位置上开始比较
//每次开始和主串当前位置比较的位置编号等于最大公共前后缀长度+1
//将每个位置对应的和主串当前位置比较的位置编号对应字串下标用一个数组next存储

//求一个字符串的最大公共前后缀
int mcss(char *arr, int len)
{
    int i = 0;
    int count = 0;
    //当数组长度为1是，返回0，即字串的第0位和主串当前位置进行比较
    if(len == 1)
    {
        return 0;
    }
    else
    {
        //ababa
        for(i = 0; i < len - 1; i++)
        {
            if(!strncmp(arr, arr + len - i - 1, i + 1))
            {
                count = i;
            }
        }
        return count;
    }
}

int KMP(char *mainarr, char *arr)
{
    //next存储的是对应下标最长的公共前后缀的长度
    int next[1000] = {-1};  
    int i = 0;  
    int mainarrlen = strlen(mainarr);
    int arrlen = strlen(arr);
    for(i = 1; i <= arrlen; i++)
    {
        next[i] = mcss(arr, i);
    }
    //初始化两个指针
    char *pmain = mainarr;
    //char *parr = arr;

    int j = 0;

    // while(*pmain)
    // {

    //     // if(!strncmp(pmain, arr, arrlen))
    //     // {
    //     //     return pmain - mainarr - 1;
    //     // }
    // }
    //如果出现不匹配的情况，按照next数组处理办法，将主串当前位置*pmain和next对应下标进行比较
    int count = 0;
    for(j = 0; j < arrlen && *pmain; j++)
    {
        if(arr[j] != *pmain)
        {
            j = next[j];
        }
        pmain++;
        count++;
    }
    printf("count = %d\n", count);

    if(*pmain)
    {
        return (pmain - mainarr - arrlen);
    }
    else
    {
        return 0;
    }
}

int main()
{
    char arr[100] = {'0'};
    char mainarr[100] = {'0'};
    scanf("%s %s", mainarr, arr);
    //printf("%d\n", mcss(arr, strlen(arr)));

    printf("%d\n", KMP(mainarr, arr));

    return 0;
}