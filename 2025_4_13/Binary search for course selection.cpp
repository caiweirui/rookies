#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2)
{
    return *((int *)e1) - *((int *)e2);
}

int main()
{
    int n = 0;
    int t = 0;
    scanf("%d %d", &n, &t);
    getchar();
    int i = 0;
    int arr[301][2] = {0};
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        getchar();
    }
    int row = i;

    qsort(arr, row, sizeof(arr[0]), cmp);

    int t1 = 0;
    int t2 = 0;
    for(i = 0; i < t; i++)
    {
        scanf("%d %d", &t1, &t2);
        int flag = 0;
        int left = 0;
        int right = row - 1;
        // 二分查找
        while(left <= right)
        {
            if(t1 > arr[(left + right) / 2][0])
            {
                left = (left + right) / 2 + 1;
            }
            else if(t1 < arr[(left + right) / 2][0])
            {
                right = (left + right) / 2 - 1;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            printf("ERR\n");
        }
        else
        {
            if(arr[(left + right) / 2][1] - t2 >= 0)
            {
                printf("Succeeded\n");
            }
            else
            {
                printf("Failed\n");
            }
        }
    }
    return 0;
}