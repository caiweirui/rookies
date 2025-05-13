int hammingDistance(int x, int y) {
    int i = 0;
    int ret = 0;
    for(i = 0; i < 32; i++)
    {
        if(((x >> i) & 1) != ((y >> i) & 1))
        {
            ret++;
        }
    }
    return ret;
}