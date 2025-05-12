char findTheDifference(char* s, char* t) {
    int hash[129] = {0};
    int i = 0;
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        hash[s[i]]++;
    }
    for(i = 0; i < len + 1; i++)
    {
        if(hash[t[i]])
        {
            hash[t[i]]--;
        }
        else
        {
            return t[i];
        }
    }
    return 0;
}