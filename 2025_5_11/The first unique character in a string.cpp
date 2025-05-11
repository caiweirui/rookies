int firstUniqChar(char* s) {
    int hash[129] = {0};
    int i = 0;
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        hash[s[i]]++;
    }
    for(i = 0; i < len; i++)
    {
        if(hash[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}