#include<stdio.h>
#include<stdlib.h>

// 个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
// 编写一个函数找出这两个只出现一次的数字。

int cmp(const void* e1, const void *e2)
{
    return (*(int*)e1 - *(int*)e2);
}

// 排序法
int test1(int *arr, int arrLen)
{
    int i = 0;    
    int ret = 0;
    qsort(arr, arrLen, sizeof(int), cmp);
    for(i = 0; i < arrLen; i++)
    {
        if((i == 0 && arr[i] != arr[i + 1]) 
        || (i == arrLen - 1 && arr[i] != arr[i - 1]))
        {
            ret = arr[i];
            break;
        }
        else if(arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
        {
            ret = arr[i];
            break;
        }
    }
    return ret;
}

// 异或法
int test2(int* arr, int arrLen)
{
    int i = 0;
    int ret = arr[0];
    for(i = 1; i < arrLen; i++)
    {
        ret = arr[i] ^ ret;
    }
    return ret;
}


int main()
{
    int* arr = (int*)calloc(1000, sizeof(int));
    int arrLen = 0;
    int ret = 0;
    do
    {
        scanf("%d", &arr[arrLen++]);
    } while (getchar() == ' ');

    // ret = test1(arr, arrLen);
    ret = test2(arr, arrLen);

    printf("%d\n", ret);

    free(arr);
    arr = NULL;
    
    return 0;
}