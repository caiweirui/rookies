/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int *ret = (int*)calloc(2, sizeof(int));
    int i = (int)sqrt((double)area) + 1;
    *returnSize = 2;
    for(;i >= 1; i--)
    {
        if(area % i == 0)
        {
            ret[0] = (area / i) > i ? area / i : i;
            ret[1] = (area / i) <= i ? area / i : i;
            return ret;
        }
    }
    return 0;
}