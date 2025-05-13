int countSegments(char* s) {
    int i = 0;
    int count = 0;
    int len = strlen(s);
    int flag = 0;
    if(len == 0)
    {
        return 0;
    }
    for(i = 0; i < len; i++)
    {
        if(s[i] != ' ')
        {
            flag = 1;
        }
        if(s[i] == ' ' && flag)
        {
            count++;
            flag = 0;
        }
    }
    return count + flag;
}