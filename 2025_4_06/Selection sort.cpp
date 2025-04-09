#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

//选择排序
//它的工作原理是：首先在未排序序列中找到最小（或最大）元素，存放到排序序列的起始位置，
//然后，再从剩余未排序元素中继续寻找最小（或最大）元素，然后放到已排序序列的末尾。
//以此类推，直到所有元素均排序完毕。
void selection_sort(int *arr, const int n)
{
    int *pend = arr + n - 1;
    int temp = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            if(*(pend - i) < arr[j])
            {
                temp = *(pend - i);
                *(pend - i) = *(arr + j);
                *(arr + j) = temp;
            }

        }
    }
    
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    int i = 0;
    int arr[1000];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}