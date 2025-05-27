/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int i = 0;
    int left = 0;
    int right = -1;
    int sLen = strlen(s);
    *returnSize = 0;
    int** ret = (int**)calloc(10000, sizeof(int*));
    *returnColumnSizes = (int*)calloc(10000, sizeof(int));
    while(i < sLen)
    {
        while(i < sLen && s[left] == s[i])
        {
            right = i++;
        }
        if(right - left >= 2)
        {
            ret[*returnSize] = (int*)malloc(8);
            (*returnColumnSizes)[*returnSize] = 2;
            ret[*returnSize][0] = left;
            ret[*returnSize][1] = right;
            *returnSize = *returnSize + 1;
        }
        left = i;
        right = -1;
    }
    return ret;
}
