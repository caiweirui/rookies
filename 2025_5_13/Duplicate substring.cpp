#include<bits/stdc++.h>

bool repeatedSubstringPattern(char* s) {
    int sLen = strlen(s);
    if(sLen == 2)
    {
        return s[0] == s[1];
    }
    char* sub = (char*)calloc(sLen * 2, sizeof(char));
    memcpy(sub, s, sLen);
    memcpy(sub + sLen, s, sLen);
    int i = 0;
    for(i = 1 ; i < sLen - 1; i++)
    {
        if(strncmp(sub + i, s, sLen - 1) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char *s = "aba";
    repeatedSubstringPattern(s);
    return 0;
}