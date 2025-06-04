/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int i = 0;
    int j = 0;
    int aliceSizesSum = 0;
    int bobSizesSum = 0;
    int* ret = (int*)calloc(2, sizeof(int));
    *returnSize = 2;
    for(i = 0; i < aliceSizesSize; i++)
    {
        aliceSizesSum += aliceSizes[i];
    }
    for(i = 0; i < bobSizesSize; i++)
    {
        bobSizesSum += bobSizes[i];
    }

    for(i = 0; i < aliceSizesSize; i++)
    {
        for(j = 0; j < bobSizesSize; j++)
        {
            if(aliceSizesSum - aliceSizes[i] + bobSizes[j] == bobSizesSum - bobSizes[j] + aliceSizes[i])
            {
                ret[0] = aliceSizes[i];
                ret[1] = bobSizes[j];
                return ret;
            }
        }
    }
    return ret;
}