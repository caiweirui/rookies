/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    char ch1[] = "qwertyuiop";
    char ch2[] = "asdfghjkl";
    char ch3[] = "zxcvbnm";
    *returnSize = 0;
    int ch1Len = strlen(ch1);
    int ch2Len = strlen(ch2);
    int ch3Len = strlen(ch3);
    int i = 0;
    int j = 0;
    int hash[30] = {0};
    int wordLen = 0;
    int flag = 0;
    for(i = 0; i < ch1Len; i++)
    {
        hash[ch1[i] - 'a'] = 1;
    }
    for(i = 0; i < ch2Len; i++)
    {
        hash[ch2[i] - 'a'] = 2;
    }
    for(i = 0; i < ch3Len; i++)
    {
        hash[ch3[i] - 'a'] = 3;
    }

    char** ret = (char**)calloc(21, sizeof(char*));

    for(i = 0; i < wordsSize; i++)
    {
        flag = 1;
        wordLen = strlen(words[i]);

        for(j = 0; j < wordLen - 1; j++)
        {
            if(hash[tolower(words[i][j]) - 'a'] != hash[tolower(words[i][j + 1]) - 'a'])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            ret[*returnSize] = words[i];
            *returnSize = *returnSize + 1;
        }
    }

    return ret;
}