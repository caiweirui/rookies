bool isMonotonic(int* nums, int numsSize) {
    if(numsSize == 1)
    {
        return 1;
    }
    int flag = nums[1] - nums[0];
    int i = 0;
    for(i = 1; i < numsSize - 1; i++)
    {
        if(flag == 0)
        {
            flag = nums[i + 1] - nums[i];
            continue;
        }
        if((flag > 0 && (nums[i + 1] - nums[i]) < 0) || (flag < 0 && (nums[i + 1] - nums[i]) > 0))
        {
            return 0;
        }
    }
    return 1;
}