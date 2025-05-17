int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int distributeCandies(int* candyType, int candyTypeSize) {
    int half = candyTypeSize / 2;
    qsort(candyType, candyTypeSize, sizeof(int), cmp);
    int temp = 1;
    int i = 0;
    for(i = 0; i < candyTypeSize - 1; i++)
    {
        if(candyType[i] != candyType[i + 1])
        {
            temp++;
        }
    }
    return (temp > half) ? half : temp;
}