/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int i = 0;
    int temp = 0;
    int *ret = (int*)calloc(10001, sizeof(int));
    *returnSize = 0;
    for(i = left; i <= right; i++)
    {
        temp = i;
        while(temp)
        {
            if(temp % 10 == 0)
            {
                break;
            }
            if(i % (temp % 10) != 0)
            {
                break;
            }
            temp /= 10;
        }
        if(!temp)
        {
            ret[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }
    return ret;
}