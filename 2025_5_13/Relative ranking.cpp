/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 1000000

char* convertToRank(int rank) {
    char* str = malloc(16 * sizeof(char));
    sprintf(str, "%d", rank);
    return str;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char **ret = (char**)calloc(scoreSize, sizeof(char*));

    *returnSize = scoreSize;
    int hash[MAX] = {0};
    int i = 0;
    int ranking = 1;
    int nLen = 0;

    for(i = 0; i < scoreSize; i++)
    {
        hash[score[i]] = 1;
    }

    for(i = MAX - 1; i >= 0; i--)
    {
        if(hash[i])
        {
            hash[i] = ranking++;
        }
    }

    for(i = 0; i < scoreSize; i++)
    {
        if(hash[score[i]] == 1)
        {
            ret[i] = strdup("Gold Medal");
        }
        else if(hash[score[i]] == 2)
        {
            ret[i] = strdup("Silver Medal");
        }
        else if(hash[score[i]] == 3)
        {
            ret[i] = strdup("Bronze Medal");
        }
        else
        {
            ret[i] = strdup(convertToRank(hash[score[i]]));
        }
    }
    return ret;
}

