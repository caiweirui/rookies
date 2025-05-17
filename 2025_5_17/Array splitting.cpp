int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int ret = 0;
    for(i = 0; i < numsSize; i += 2)
    {
        ret += nums[i];
    }
    return ret;
}