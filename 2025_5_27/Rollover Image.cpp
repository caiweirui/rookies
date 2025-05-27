/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)calloc(imageSize, sizeof(int*));
    *returnColumnSizes = (int*)calloc(imageColSize[0], sizeof(int));
    int i = 0;
    int j = 0;
    int temp = 0;
    int left = 0;
    int right = 0;
    for(i = 0; i < imageSize; i++)
    {
        ret[i] = (int*)calloc(imageColSize[i], sizeof(int));
        (*returnColumnSizes)[i] = imageColSize[i];
        memcpy(ret[i], image[i], imageColSize[i] * sizeof(int));
        left = 0;
        right = imageColSize[i] - 1;
        while(left < right)
        {
            temp = ret[i][left];
            ret[i][left] = ret[i][right];
            ret[i][right] = temp;
            left++;
            right--;
        }
        for(j = 0; j < imageColSize[i]; j++)
        {
            ret[i][j] = (ret[i][j] == 0);
        }
    }
    *returnSize = imageSize;
    return ret;
}