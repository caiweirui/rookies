int cmp(const void *e1, const void *e2)
{
    return (*(int *)e1 - *(int *)e2);
}

int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    if(numsSize == 1)
    {
        return nums[0];
    }
    if(nums[0] != nums[1])
    {
        return nums[0];
    }
    if(nums[numsSize - 1] != nums[numsSize - 2])
    {
        return nums[numsSize - 1];
    }
    for(i = 1; i < numsSize - 1; i++)
    {
        if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return 0;
}