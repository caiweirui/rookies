/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int* ret = (int*)calloc(100001, sizeof(int));
    int* hash = (int*)calloc(100001, sizeof(int));
    *returnSize = 0;
    for(i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    } 
    for(i = 1; i <= numsSize; i++)
    {
        if(hash[i] == 0)
        {
            ret[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }
    return ret;
}