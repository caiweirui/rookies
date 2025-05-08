#include<bits/stdc++.h>
int cmp(const void *e1, const void *e2)
{
    return (*(int*)e1 - *(int*)e2);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    for(i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
    calloc()
}
