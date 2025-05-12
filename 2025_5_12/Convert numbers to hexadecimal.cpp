char* toHex(int num) {
    int i = 0;
    int tempArr[32] = {0};
    char* ret = (char*)calloc(9, sizeof(char));
    if(num == 0)
    {
        ret[0] = '0';
        return ret;
    }
    for(i = 31; i >= 0; i--)
    {
        tempArr[31 - i] = (num >> i) & 1;
    }
    for(i = 0; i < 32; i++)
    {
        ret[i / 4] = tempArr[i] + (ret[i / 4] << 1);
    }
    for(i = 0; i < 8; i++)
    {
        if(ret[i] < 10)
        {
            ret[i] = ret[i] + '0';
        }
        else
        {
            ret[i] = ret[i] - 10 + 'a';
        }
    }
    while(*ret == '0')
    {
        ret++;
    }
    return ret;
}