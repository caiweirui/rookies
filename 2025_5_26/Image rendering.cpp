/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** image, int imageSize, int* imageColSize, int sr, int sc, int originColor, int color)
{
    // 检查边界条件
    if(sr < 0 || sr >= imageSize || sc < 0 || sc >= imageColSize[sr])
    {
        return;
    }

    // 检查颜色
    if(originColor != image[sr][sc])
    {
        return;
    }

    // 改变颜色
    image[sr][sc] = color;

    // 上下左右
    dfs(image, imageSize, imageColSize, sr - 1, sc, originColor, color);
    dfs(image, imageSize, imageColSize, sr + 1, sc, originColor, color);
    dfs(image, imageSize, imageColSize, sr, sc - 1, originColor, color);
    dfs(image, imageSize, imageColSize, sr, sc + 1, originColor, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = (int*)calloc(imageSize, sizeof(int*));
    int **ret = (int**)calloc(imageSize, sizeof(int*));
    *returnSize = imageSize;

    int row = 0;
    for(row = 0; row < imageSize; row++)
    {
        (*returnColumnSizes)[row] = imageColSize[row];
        ret[row] = (int*)malloc(imageColSize[row] * sizeof(int));
        memmove(ret[row], image[row], imageColSize[row] * sizeof(int));
    }

    if(color == image[sr][sc])
    {
        return ret;
    }
    
    dfs(ret, *returnSize, *returnColumnSizes, sr, sc, image[sr][sc], color);

    return ret;
}
