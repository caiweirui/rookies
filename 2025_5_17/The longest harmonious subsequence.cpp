int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int count = 0;
    int ret = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < numsSize; i++)
    {
        temp = nums[i];
        count = 0;
        for(j = i; j < numsSize; j++)
        {
            if(nums[j] - nums[i] <= 1)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if(count > ret && (nums[j - 1] - nums[i] == 1))
        {
            ret = count;
        }
        while(i < numsSize && nums[i] == temp)
        {
            i++;
        }
        i--;
    }
    return ret;
}