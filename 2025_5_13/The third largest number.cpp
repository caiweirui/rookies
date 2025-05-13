int cmp(const void *e1, const void *e2)
{
    if(*(int*)e1 > *(int*)e2)
    {
        return -1;
    }
    else if(*(int*)e1 == *(int*)e2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int thirdMax(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int flag = 0;
    for(i = 0; i < numsSize - 1; i++)
    {
        if(nums[i] != nums[i + 1])
        {
            flag++;
        }
        if(flag == 2)
        {
            return nums[i + 1];
        }
    }
    return nums[0];
}