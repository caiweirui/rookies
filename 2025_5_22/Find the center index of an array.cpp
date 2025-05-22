int pivotIndex(int* nums, int numsSize) {
    int i = 0;
    int sum = 0;
    int half = 0;
    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    for(i = 0; i < numsSize; i++)
    {
        if(half * 2 == sum - nums[i])
        {
            return i;
        }
        half += nums[i];
    }
    return -1;
}