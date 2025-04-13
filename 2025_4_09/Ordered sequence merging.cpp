#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//输入描述：
// 输入包含三行，
// 第一行包含两个正整数n，m，用空格分隔。n表示第二行第一个升序序列中数字的个
// 数，m表示第三行第二个升序序列中数字的个数。
// 第工行包含n个整数，用空格分隔。
// 第三行包含m个整数，用空格分隔。

// 输出描述：
// 输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序
// 序列中的元素重新进行升序序列排列合并。

// 输入：5 6
// 1 3 7 9 22
// 2 8 10 17 33 44
// 输出:1 2 3 7 8 9 10 17 22 33 44

//插入排序
void sort(int *arr, const int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int flag = 0;
    for(i = 1; i < len; i++)
    {
        temp = arr[i];
        flag = i;
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                flag = j;
            }
        } 
        arr[flag] = temp;
    } 
}

void Merge(int *arr1, int *arr2, int *arrret, const int n1, const int n2)
{
    int i = 0;
    sort(arr1, n1);
    sort(arr2, n2);

    int *parr1 = arr1;
    int *parr2 = arr2;
    
    while(*parr1 || *parr2)
    {
        //当arr1数组的数字更小
        if(*parr1 >= *parr2 && *parr1 && *parr2)
        {
            *(arrret + i) = *parr2;
            i++;
            parr2++;
        }
        //当arr2数组的数字更小
        else if(*parr1 < *parr2 && *parr1 && *parr2)
        {
            *(arrret + i) = *parr1;
            i++;
            parr1++;
        }
        //当arr1全部终止
        else if(!*parr1 && *parr2)
        {
            *(arrret + i) = *parr2;
            i++;
            parr2++;
        }
        //当arr2全部终止
        else if(!*parr2 && *parr1)
        {
            *(arrret + i) = *parr1;
            i++;
            parr1++;
        }
    }
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    int arr1[1000] = {0};
    int arr2[1000] = {0}; 
    int arrret[1000] = {0};
    scanf("%d %d", &n1, &n2);
    getchar();
    int i = 0;
    for(i = 0; i < n1; i++)
    {
        scanf("%d", arr1 + i);
    }
    getchar();
    for(i = 0; i < n2; i++)
    {
        scanf("%d", arr2+ i);
    }

    Merge(arr1, arr2, arrret, n1, n2);

    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arrret[i]);
    }
    printf("\n");

    return 0;
}