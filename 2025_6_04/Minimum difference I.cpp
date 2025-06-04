int smallestRangeI(int* nums, int numsSize, int k) {
    int i = 0;
    int max = nums[0];
    int min = nums[0];
    for(i = 1; i < numsSize; i++)
    {
        if(max < nums[i])
        {
            max = nums[i];
        }
        if(min > nums[i])
        {
            min = nums[i];
        }
    }
    return (max - min - 2 * k > 0 ? max - min - 2 * k : 0);
}