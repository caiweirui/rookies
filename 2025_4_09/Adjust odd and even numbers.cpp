#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 输入一个整数数组，实现一个函数，
// 来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
// 所有偶数位于数组的后半部分。
// void adjust(int *arr, const int len)
// {
//     int i = 0;
//     int *p = arr;
//     int temp = 0; 
//     while(*p)
//     {
//         if(*p % 2 == 1)
//         {
//             temp = *p;
//             *p = *(arr + i);
//             *(arr + i) =temp;
//             i++;
//         }
//         p++;
//     }
// }

// 双指针，左边找奇数，右边找偶数，把左右两个交换
void adjust(int *arr, const int len)
{
    int i = 0;
    int *left = arr;
    int *right = arr + len - 1;
    int temp = 0;
    while(1)
    {
        //全是奇数或全是偶数会越界
        while(*left % 2 != 0 && left < right)
        {
            left++;
        }
        while(*right % 2 != 1 && left < right)
        {
            right--;
        }
        if(left < right)
        {
            temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
        else
        {
            break;
        }
    }
}


int main()
{
    int arr[1000] = {0};
    int len = 0;
    do
    {
        scanf("%d", &arr[len++]);
    }while(getchar() != '\n');

    adjust(arr, len);
    
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}