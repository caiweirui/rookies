int gcd(int x, int y)
{
    int temp = 0;
    while(x)
    {
        temp = y % x;
        y = x;
        x = temp;
    }
    return y;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    if(deckSize == 1)
    {
        return 0;
    }
    int* hash = (int*)calloc(10000, sizeof(hash));
    int i = 0;
    for(i = 0; i < deckSize; i++)
    {
        hash[deck[i]]++;
    }
    int ret = -1;
    for(i = 0; i < 10000; i++)
    {
        if(hash[i] != 0)
        {
            if(ret == -1)
            {
                ret = hash[i];
            }
            else
            {
                ret = gcd(ret, hash[i]);
            }
        }
    }
    return (ret >= 2);
}