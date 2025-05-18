int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    int temp = 1;
    int ret = nums[0] * nums[1] * nums[2];
    for(i = 0; i < numsSize; i++)
    {
        temp = 1;
        for(j = 0; j < 3; j++)
        {
            temp *= nums[(i + j) % numsSize];
        }
        if(temp > ret)
        {
            ret = temp;
        }
    }
    return ret;
}