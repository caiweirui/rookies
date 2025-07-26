/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *e1, const void *e2)
{
    return *(int*)e1 - *(int*)e2;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ret = (int**)malloc(sizeof(int*) * 30000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 30000);
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int retLen = 0;
    long long sum = 0;
    for(i = 0; i < numsSize - 3; i++)
    {
        for(j = i + 1; j < numsSize - 2; j++)
        {
            for(m = j + 1; m < numsSize - 1; m++)
            {
                for(n = m + 1; n < numsSize; n++)
                {
                    sum = 0;
                    sum += nums[i] + nums[j];
                    sum += nums[m] + nums[n];
                    if(sum == target)
                    {
                        int *temp = (int*)malloc(4 * sizeof(int));
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[m];
                        temp[3] = nums[n];
                        ret[retLen] = temp;
                        (*returnColumnSizes)[retLen++] = 4;
                    }
                    while(n < numsSize - 1 && nums[n] == nums[n + 1])
                    {
                        n++;
                    }
                }
                while(m < numsSize - 2 && nums[m] == nums[m + 1])
                {
                    m++;
                }
            }
            while(j < numsSize - 3 && nums[j] == nums[j + 1])
            {
                j++;
            }
        }
        while(i < numsSize - 4 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    *returnSize = retLen;
    return ret;
}