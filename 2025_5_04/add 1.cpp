/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ret = (int *)malloc(4 * 101);
    int i = 0;
    int cf = 0;
    if(digits[digitsSize - 1] == 9)
    {
        cf = 1;
        digits[digitsSize - 1] = 0;
        for(i = digitsSize - 2; i >= 0; i--)
        {
            if(digits[i] + cf == 10)
            {
                digits[i] = 0;
                cf = 1;
            }
            else
            {
                digits[i] += 1;
                cf = 0;
                break;
            }
        }
        if(cf == 1)
        {
            *ret = 1;
            for(i = 0; i < digitsSize; i++)
            {
                ret[i + 1] = digits[i];
            }
            *returnSize = digitsSize + 1;
        }
        else
        {
            for(i = 0; i < digitsSize; i++)
            {
                ret[i] = digits[i];
                *returnSize = digitsSize;
            }
        }
    }
    else
    {
        for(i = 0; i < digitsSize; i++)
        {
            ret[i] = digits[i];
        }
        ret[digitsSize - 1]++;
        *returnSize = digitsSize;
    }
    return ret;
}