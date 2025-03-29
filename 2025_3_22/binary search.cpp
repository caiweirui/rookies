#include <stdio.h>

int main()
{
    int arr[100] = {0};
    int need = 0;
    int mid = 0;
    scanf("%d", &need);
    int i = 0, j = 0;
    int begin = 0, end = 0;
    while(getchar() != '\n')
    {
        scanf("%d", &arr[i++]);
        end++;
    }
    // printf("\n");
    // printf("end=%d\n", end);
    //转换成有序数列
    for (i = 0; i < end; i++)
    {
        for (j = 0; j < end; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //二分查找
    end--;
    //printf("need=%d\n", need);
    while(begin <= end)
    {
        mid = (begin + end) / 2;
        // printf("mid=%d\n", mid);
        // printf("arr[mid]=%d\n", arr[mid]);
        if(need < arr[mid])
        {
            //如果need小于中间值，则end = 中间值
            end = mid - 1;
            //printf("大了\n");
        }
        else if(need > arr[mid])
        {
            //如果need大于中间值，则begin = 中间值
            begin = mid + 1;
            //printf("小了\n");
        }
        else
        {
            printf("%d\n", mid);
            break;
        }
    }
    //printf("%d %d %d\n", begin, mid, end);
    if(begin > end)
    {
        printf("no found.");
    }
    return 0;
}