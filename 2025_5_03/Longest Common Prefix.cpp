#include<bits/stdc++.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *ret = (char *)calloc(200, sizeof(char));
    int i = 0;
    int j = 0;
    for(i = 0; i < 200; i++)
    {
        for(j = 0; j < strsSize; j++)
        {
            if(strs[j][i] == 0 || strs[j][i] != strs[0][i])
            {
                return ret;
            }
        }
        ret[i] = strs[0][i];
    }
    return ret;
}

int main()
{
    char *strs[3] = {"flower","flow","flight"};
    printf(longestCommonPrefix(strs, 3));
    return 0;
}