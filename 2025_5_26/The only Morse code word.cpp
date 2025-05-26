int cmp(const void* e1, const void* e2)
{
    return strcmp(*(char**)e1, *(char**)e2);
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
    if(wordsSize == 1)
    {
        return 1;
    }
    char* Morse[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char** temp = (char**)calloc(wordsSize, sizeof(char*));
    int i = 0;
    int j = 0;
    int ret = 1;
    for(i = 0; i < wordsSize; i++)
    {
        temp[i] = (char*)calloc(100, sizeof(char));
        for(j = 0; j < strlen(words[i]); j++)
        {
            strcat(temp[i], Morse[words[i][j] - 'a']);
        }
    }
    qsort(temp, wordsSize, sizeof(char**), cmp);
    for(i = 0; i < wordsSize - 1; i++)
    {
        if(strcmp(temp[i], temp[i + 1]))
        {
            ret++;
        }
    }
    return ret;
}