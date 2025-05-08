bool isIsomorphic(char* s, char* t) {
    char temp[129] = {0};
    int len = strlen(s);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(temp[s[i]] == 0)
        {
            temp[s[i]] = t[i];
        }
        else
        {
            if(temp[s[i]] != t[i])
            {
                return false;
            }
        }
    }

    memset(temp, 0, 129);

    for(i = 0; i < len; i++)
    {
        if(temp[t[i]] == 0)
        {
            temp[t[i]] = s[i];
        }
        else
        {
            if(temp[t[i]] != s[i])
            {
                return false;
            }
        }
    }

    return true;
}