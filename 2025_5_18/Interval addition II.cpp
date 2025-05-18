int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int i = 0;
    int minRow = m;
    int minCol = n;
    for(i = 0; i < opsSize; i++)
    {
        if(minRow > ops[i][0])
        {
            minRow = ops[i][0];
        }
        if(minCol > ops[i][1])
        {
            minCol = ops[i][1];
        }
    }
    return minCol * minRow;
}