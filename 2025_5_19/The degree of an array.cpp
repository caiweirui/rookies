int findShortestSubArray(int* nums, int numsSize) {
    int hash[50000] = {0};
    int i = 0;
    int j = 0;
    int left = 0;
    int right = 0;
    int ret = numsSize;
    int dim = 0;
    int hashLen = 0;
    for(i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
        if(dim < hash[nums[i]])
        {
            dim = hash[nums[i]];
        }
    } 
    for(i = 0; i < 50000; i++)
    {
        if(hash[i] == dim)
        {
            hash[hashLen++] = i;
        }
    }
    for(i = 0; i < hashLen; i++)
    {
        left = numsSize;
        right = 0;
        for(j = 0; j < numsSize; j++)
        {
            if(nums[j] == hash[i])
            {
                if(left > j)
                {
                    left = j;
                }
                if(right < j)
                {
                    right = j;
                }
            }
        }
        if(ret > right - left + 1)
        {
            ret = right - left + 1;
        }
    }
    return ret;
}