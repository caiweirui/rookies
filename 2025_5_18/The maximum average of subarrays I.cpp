double findMaxAverage(int* nums, int numsSize, int k) {
    double ret = 0.0;
    int i = 0;
    int j = 0;
    int temp = 0;
    int sum = 0;
    for(i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    
    for(i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }
    if(numsSize == k)
    {
        return (double)nums[numsSize - 1] / (double)k;
    }


    for(i = 0; i < numsSize - k; i++)
    {
        temp = nums[i + k] - nums[i];
        if(temp > sum)
        {
            sum = temp;
        }
    }
    ret = (double)sum / (double)k;
    return ret;
}