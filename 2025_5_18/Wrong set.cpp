/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int i = 0;
    int* ret = (int*)calloc(*returnSize, sizeof(int));
    int sum = 0;
    int hash[10001] = {0};
    for(i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    for(i = 1; i <= numsSize; i++)
    {
        if(hash[i] == 0)
        {
            ret[1] = i;
        }
        if(hash[i] == 2)
        {
            ret[0] = i;
        }
    }
    return ret;
}