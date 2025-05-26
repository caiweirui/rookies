int dominantIndex(int* nums, int numsSize) {
    int i = 0;
    int max = nums[0];
    int ret = -1;
    for(i = 0; i < numsSize; i++)
    {
        if(max <= nums[i])
        {
            max = nums[i];
            ret = i;
        }
    }
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0 && i != ret)
        {
            if(max / nums[i] < 2)
            {
                ret = -1;
            }
        }
    }
    return ret;
}