/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *e1, const void *e2)
{
    return *(int*)e1 - *(int*)e2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    int k = 0;
    int retLen = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 30000);
    int **ret = (int**)malloc(sizeof(int*) * 30000);

    for(i = 0; i < numsSize - 2; i++)
    {
        j = i + 1;
        k = numsSize - 1;
        while(j < k)
        {
            if(nums[i] + nums[j] + nums[k] == 0)
            {
                (*returnColumnSizes)[retLen] = 3;
                int *temp = (int*)malloc(sizeof(int) * 3);
                temp[0] = nums[i];
                temp[1] = nums[j];
                temp[2] = nums[k];

                ret[retLen++] = temp;

                while(j < k && nums[j] == nums[j + 1])
                {
                    j++;
                }
                while(j < k && nums[k] == nums[k - 1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if(nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        while(i < numsSize - 2 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    *returnSize = retLen;
    return ret;
}