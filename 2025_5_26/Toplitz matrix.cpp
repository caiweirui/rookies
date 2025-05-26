bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < matrixSize; i++)
    {
        temp = matrix[i][0];
        for(j = 0; j < matrixColSize[i] && (i + j) < matrixSize; j++)
        {
            if(matrix[i + j][j] != temp)
            {
                return 0;
            }
        }
    }
    for(j = 0; j < matrixColSize[0]; j++)
    {
        temp = matrix[0][j];
        for(i = 0; i < matrixSize && (i + j) < matrixColSize[0]; i++)
        {
            if(matrix[i][i + j] != temp)
            {
                return 0;
            }
        }
    }
    return 1;
}