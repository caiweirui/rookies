char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int hash[26] = {0};
    int i = 0;
    int j = 0;
    int* tempHash = NULL;
    int temp = 0;
    int min = wordsSize;
    int flag = 0;
    for(i = 0; i < strlen(licensePlate); i++)
    {
        if(isalpha(licensePlate[i]))
            hash[tolower(licensePlate[i]) - 'a']++;
    }
    for(i = 0; i < wordsSize; i++)
    {
        tempHash = (int*)calloc(26, sizeof(int));
        temp = 0;
        for(j = 0; j < strlen(words[i]); j++)
        {
            tempHash[tolower(words[i][j]) - 'a']++;
        }
        for(j = 0; j < 26; j++)
        {
            if(tempHash[j] >= hash[j])
            {
                temp += tempHash[j] - hash[j];
            }
            else
            {
                goto label;
            }
        }
        if(temp < min)
        {
            min = temp;
            flag = i;
        }
label:
        memset(tempHash, 0, 26 * sizeof(int));
    }
    return words[flag];
}