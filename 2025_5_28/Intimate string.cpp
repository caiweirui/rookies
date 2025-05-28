bool buddyStrings(char* s, char* goal) {
    int i = 0;
    int count = 0;
    int hash[26] = {0};
    int sLen = strlen(s);
    int goalLen = strlen(goal);
    if(sLen != goalLen)
    {
        return 0;
    }
    for(i = 0; i < sLen; i++)
    {
        hash[s[i] - 'a']++;
    }

    // 原来就相等，需要两个相同的字符
    if(strncmp(s, goal, sLen) == 0)
    {
        for(i = 0; i < 26; i++)
        {
            if(hash[i] >= 2)
            {
                return 1;
            }
        }
        return 0;
    }

    // 原来不相等，仅存在两个位置不相等
    for(i = 0; i < goalLen; i++)
    {
        hash[goal[i] - 'a']--;
    }
    for(i = 0; i < 26; i++)
    {
        if(hash[i])
        {
            return 0;
        }
    }
    for(i = 0; i < sLen; i++)
    {
        if(s[i] != goal[i])
        {
            count++;
        }
    }
    return (count == 2);
}