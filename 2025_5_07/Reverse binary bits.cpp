uint32_t reverseBits(uint32_t n) {
    size_t ret = 0;
    int i = 0;
    char temp[32] = {0};
    for(i = 0; i < 32; i++)
    {
        temp[i] = (n >> i) & 1;
    }
    for(i = 0; i < 32; i++)
    {
        ret = ret * 2 + temp[i];
    }
    return ret;
}