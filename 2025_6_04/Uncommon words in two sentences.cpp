/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    char ch[400];
    int count;
}Hash;

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    char** ret = (char**)calloc(400, sizeof(char*));
    Hash hash[400] = {0};
    int hashLen = 0;
    *returnSize = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 0; i < strlen(s1); i++)
    {
        char* tempArr = (char*)calloc(200, sizeof(char));
        while(i < strlen(s1) && isalpha(s1[i]))
        {
            tempArr[strlen(tempArr)] = s1[i];
            i++;
        }
        flag = 0;
        for(j = 0; j < hashLen; j++)
        {
            if(strcmp(tempArr, hash[j].ch) == 0)
            {
                hash[j].count++;
                flag = 1;
            }
        }
        if(!flag)
        {
            strcpy(hash[hashLen].ch, tempArr);
            hash[hashLen].count++;
            hashLen++;
        }
        free(tempArr);
        tempArr = NULL;
    }
    
    for(i = 0; i < strlen(s2); i++)
    {
        char* tempArr = (char*)calloc(200, sizeof(char));
        while(i < strlen(s2) && isalpha(s2[i]))
        {
            tempArr[strlen(tempArr)] = s2[i];
            i++;
        }
        flag = 0;
        for(j = 0; j < hashLen; j++)
        {
            if(strcmp(tempArr, hash[j].ch) == 0)
            {
                hash[j].count++;
                flag = 1;
            }
        }
        if(!flag)
        {
            strcpy(hash[hashLen].ch, tempArr);
            hash[hashLen].count++;
            hashLen++;
        }
        free(tempArr);
        tempArr = NULL;
    }

    for(i = 0; i < hashLen; i++)
    {
        if(hash[i].count == 1)
        {
            ret[*returnSize] = (char*)malloc(400 * sizeof(char));
            strcpy(ret[*returnSize],  hash[i].ch);
            *returnSize = *returnSize + 1;
        }
    }

    return ret;
}
