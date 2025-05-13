char* licenseKeyFormatting(char* s, int k) {
    char *p1 = s;
    char *p2 = s;
    while(*p1)
    {
        if(*p1 != '-')
        {
            *p2++ = *p1++;
        }
        else
        {
            p1++;
        }
    } 
    *p2 = '\0';
    int len = strlen(s);
    char* ret = (char*)calloc(100000, sizeof(char));
    int retLen = 0;
    int i = 0;
    if(len <= k)
    {
        for(i = 0; i < len; i++)
        {
            ret[i] = toupper(s[i]);
        }
        return ret;
    }
    while(len % k != 0)
    {
        ret[retLen++] = toupper(s[i++]);
        len--;
    }
    s = s + i;
    if(i != 0)
        ret[retLen++] = '-';

    label:
    for(i = 0; i < len; i++)
    {
        ret[retLen++] = toupper(s[i]);
        if(i % k == k - 1  && i != len - 1)
        {
            ret[retLen++] = '-';
        }
    }
    return ret;
}