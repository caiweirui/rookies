bool backspaceCompare(char* s, char* t) {
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int tLen = strlen(t);
    for(i = sLen - 1; i >= 0; i--)
    {
        while(i >= 0 && s[i] != '#')
        {
            i--;
        }
        if(i >= 0 && s[i] == '#')
        {
            s[i] = 0;
        }
        for(j = i - 1; j >= 0; j--)
        {
            if(s[j] != '#' && s[j] != 0)
            {
                s[j] = 0;
                break;
            }
        }
    }
    j = 0;
    for(i = 0; i < sLen; i++)
    {
        if(s[i] != 0)
        {
            s[j++] = s[i];
        }
    }
    s[j] = 0;

    for(i = tLen - 1; i >= 0; i--)
    {
        while(i >= 0 && t[i] != '#')
        {
            i--;
        }
        if(i >= 0 && t[i] == '#')
        {
            t[i] = 0;
        }
        for(j = i - 1; j >= 0; j--)
        {
            if(t[j] != '#' && t[j] != 0)
            {
                t[j] = 0;
                break;
            }
        }
    }
    j = 0;
    for(i = 0; i < tLen; i++)
    {
        if(t[i] != 0)
        {
            t[j++] = t[i];
        }
    }
    t[j] = 0;

    return !(strcmp(s, t));
}