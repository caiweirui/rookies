int numJewelsInStones(char* jewels, char* stones) {
    int hash[129] = {0};
    int i = 0;
    int ret = 0;
    for(i = 0; i < strlen(jewels); i++)
    {
        hash[jewels[i]] = 1;
    }
    for(i = 0; i < strlen(stones); i++)
    {
        ret += hash[stones[i]];
    }
    return ret;
}