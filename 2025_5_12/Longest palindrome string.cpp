int longestPalindrome(char* s) {
    int len = strlen(s); 
    if(len == 1)
    {
        return 1;
    }
    int hash[129] = {0};
    int i = 0;
    int flag = 0;
    int ret = 0;
    for(i = 0; i < len; i++)
    {
        hash[s[i]]++;
    }
    for(i = 0; i < 129; i++)
    {
        if(hash[i] % 2 == 1 && !flag)
        {
            hash[i]--;
            flag = 1;
            ret++;
        }
        if(hash[i] >= 2)
        {
            ret = ret + hash[i] / 2 * 2;
        }
    }
    return ret;
}