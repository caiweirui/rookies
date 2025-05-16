#include<stdio.h>
#include<stdlib.h>

// 个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
// 编写一个函数找出这两个只出现一次的数字。

// 分组
int* test1(int *arr, int arrLen)
{
    int i = 0;    
    int *ret = (int*)calloc(2, sizeof(int));
    int temp = arr[0];
    int* temp1 = (int*)calloc(arrLen, sizeof(int));
    int* temp2 = (int*)calloc(arrLen, sizeof(int));
    int temp1Len = 0;
    int temp2Len = 0;
    int flag = 0;

    // 求flag
    for(i = 1; i < arrLen; i++)
    {
        temp = temp ^ arr[i]; 
    }
    for(i = 0; i < 32; i++)
    {
        if((temp >> i) & 1)
        {
            flag = i;
            break;
        }
    }

    // 分组
    for(i = 0; i < arrLen; i++)
    {
        if((arr[i] >> flag) & 1)
        {
            temp1[temp1Len++] = arr[i];
        }
        else
        {
            temp2[temp2Len++] = arr[i];
        }
    }

    // 异或
    ret[0] = temp1[0];
    ret[1] = temp2[0];
    for(i = 1; i < temp1Len; i++)
    {
        ret[0] = ret[0] ^ temp1[i];
    }

    for(i = 1; i < temp2Len; i++)
    {
        ret[1] = ret[1] ^ temp2[i];
    }

    free(temp1);
    free(temp2);
    temp1 = NULL;
    temp2 = NULL;
    return ret;
}

int main()
{
    int* arr = (int*)calloc(1000, sizeof(int));
    int arrLen = 0;
    int* ret = NULL;
    do
    {
        scanf("%d", &arr[arrLen++]);
    } while (getchar() == ' ');

    ret = test1(arr, arrLen);

    printf("%d %d\n", ret[0], ret[1]);

    free(arr);
    arr = NULL;
    
    return 0;
}