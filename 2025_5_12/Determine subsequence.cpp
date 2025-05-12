bool isSubsequence(char* s, char* t) {
    char *ps = s;
    char *pt = t;
    while(*pt)
    {
        if(*ps == *pt)
        {
            ps++;
            pt++;
        }
        else
        {
            pt++;
        }
    }
    return !(*ps);
}