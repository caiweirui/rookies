int ablePlantNumber(int left, int right)
{
    int i = 0;
    int ret = 0;
    for(i = left + 2; i <= right - 2; i += 2)
    {
        ret++;
    }
    return ret;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int left = -1;
    int right = -1;
    int i = 0;
    int count = 0;
    if(n == 0)
    {
        return 1;
    }
    if(flowerbedSize == 1)
    {
        return !flowerbed[0];
    }
    for(i = 0; i < flowerbedSize; i++)
    {
        if(flowerbed[i] == 1 && left == -1)
        {
            left = i;
            continue;
        }
        if(flowerbed[i] == 0 && i == 0)
        {
            left = -2;
            continue;
        }
        if(flowerbed[i] == 1 && left != -1)
        {
            right = i;
        }
        if(i == flowerbedSize - 1 && left != -1 && right == -1)
        {
            right = i + 2;
        }
        if(left != -1 && right != -1)
        {
            count += ablePlantNumber(left, right);
            left = right;
            right = -1;
        }
    }
    return (count >= n);
}