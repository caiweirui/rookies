int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int left = -1;
    int right = -1;
    int flag = 0;
    int max = 0;
    if(numsSize == 1)
    {
        return nums[0];
    }
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1 && !flag)
        {
            left = i;
            flag = 1;
        }

        if(nums[i] != 1 && flag)
        {
            right = i - 1;
            flag = 0;
        }

        if(i == numsSize - 1 && flag)
        {
            right = i;
            flag = 0;
        }

        if(left != -1 && right != -1)
        {
            if(max < right - left + 1)
            {
                max = right - left + 1;
            }
            left = -1;
            right = -1;
        }
    }
    return max;
}