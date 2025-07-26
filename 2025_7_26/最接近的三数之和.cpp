int cmp(const void *e1, const void *e2)
{
    return *(int*)e1 - *(int*)e2;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    int k = 0;
    int ret = 0;
    int min = 100000;
    for(i = 0; i < numsSize - 2; i++)
    {
        j = i + 1; 
        k = numsSize - 1;
        while(j < k)
        {
            if(min >= abs(nums[i] + nums[j] + nums[k] - target))
            {
                min = abs(nums[i] + nums[j] + nums[k] - target);
                ret = nums[i] + nums[j] + nums[k];
            }
            if(nums[i] + nums[j] + nums[k] == target)
            {
                return target;
            }
            else if(nums[i] + nums[j] + nums[k] > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ret;
}