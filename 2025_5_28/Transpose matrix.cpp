/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int i = 0;
    int j = 0;
    *returnSize = *matrixColSize;
    int** ret = (int**)calloc(*matrixColSize, sizeof(int*));
    *returnColumnSizes = (int*)calloc(*matrixColSize, sizeof(int));

    for(i = 0; i < *matrixColSize; i++)
    {
        ret[i] = (int*)calloc(matrixSize, sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
        for(j = 0; j < matrixSize; j++)
        {
            ret[i][j] = matrix[j][i];
        }
    }
    return ret;
}