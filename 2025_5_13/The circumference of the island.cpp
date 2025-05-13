int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int i = 0; 
    int j = 0;
    int ret = 0;
    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < *gridColSize; j++)
        {
            if(grid[i][j])
            {
                if((i == 0) || grid[i - 1][j] == 0)
                {
                    ret += 1;
                }
                if((i == gridSize - 1) || grid[i + 1][j] == 0)
                {
                    ret += 1;
                }
                if((j == 0) || grid[i][j - 1] == 0)
                {
                    ret += 1;
                }
                if((j == *gridColSize - 1) || grid[i][j + 1] == 0)
                {
                    ret += 1;
                }
            }
        }
    }
    return ret;
}