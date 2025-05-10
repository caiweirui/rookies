#include<bits/stdc++.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int n)
{
    int i = 0;
    int ret = 0;
    for(i = 0; i < 32; i++)
    {
        if(((n >> i) & 1) == 1)
        {
            ret++;
        }
    }
    return ret;
}

int* countBits(int n, int* returnSize) {
    int i = 0;
    int* ret = (int*)malloc((n + 1) * sizeof(int));
    for(i = 0; i <= n; i++)
    {
        ret[i] = count(i);
    }
    *returnSize = n + 1;
    return ret;
}

int main()
{
    int len = 0;
    int i = 0;
    int n = 0;
    fscanf(stdin, "%d", &n);
    // int* ret = countBits(n, &len);

    // for(i = 0; i < len; i++)
    // {
    //     printf("%d ", ret[i]);
    // }
    // printf("\n");

    printf("%d\n", count(n));

    return 0;
}