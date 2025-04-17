#include<stdio.h>

// 2183.统计可以被K整除的下标对数目

// 给你一个下标从0开始、长度为的整数数组nums和一个整数，返回满足下述条件的下标对（i，j)的数目：
// nums [i]* nums [j]能被k整除。

long long countPairs(int* nums, int numsSize, int k) {
    int i = 0;
    int j = 0;
    int r1 = 0;
    int r2 = 0;
    long long r = 0;
    int ret = 0;
    for(i = 0; i < numsSize - 1; i++)
    {
        //(a1k + b1)*(a2k + b2) = (a1 * a2 + b1 + b2)k + b1 * b2;
        //保证b1 * b2是k的倍数即可
        r1 = nums[i] % k;
        //刚好可以整除的情况 
        if(r1 == 0)
        {
            ret += numsSize - i;
            continue;
        }

        //不可以整除的情况
        for(j = i + 1; j < numsSize; j++)
        {
            r2 = nums[j] % k;
            r = r1 * r2;
            if(r % k == 0)
            {
                ret++;
            }
        }
    }
    return ret;
}

int main()
{
    int arr[10000] = {1, 2, 3, 4, 5};
    int k = 2;

    long long ret = countPairs(arr, 5, k);
    printf("%lld\n", ret);
    return 0;
}