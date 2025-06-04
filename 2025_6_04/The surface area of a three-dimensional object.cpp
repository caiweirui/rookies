int surfaceArea(int** grid, int gridSize, int* gridColSize) {
    int temp[60][60] = {0};
    int i = 0;
    int j = 0;
    int ret = 0;
    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < gridColSize[i]; j++)
        {
            temp[i + 1][j + 1] = grid[i][j];
        }
    }
    for(i = 1; i < gridSize + 2; i++)
    {
        for(j = 1; j < gridColSize[0] + 2; j++)
        {
            if(temp[i][j] > 0)
            {
                ret += 2;
            }
            ret += (temp[i + 1][j] - temp[i][j] < 0 ? temp[i][j] - temp[i + 1][j] : 0);
            ret += (temp[i - 1][j] - temp[i][j] < 0 ? temp[i][j] - temp[i - 1][j] : 0);
            ret += (temp[i][j + 1] - temp[i][j] < 0 ? temp[i][j] - temp[i][j + 1] : 0);
            ret += (temp[i][j - 1] - temp[i][j] < 0 ? temp[i][j] - temp[i][j - 1] : 0);
        }
    }
    return ret;
}