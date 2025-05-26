char nextGreatestLetter(char* letters, int lettersSize, char target) {
    char ret = letters[0];
    char tempArr[10000] = {0};
    int tempArrLen = 0;
    int i = 0;
    int flag = 0;
    for(i = 0; i < lettersSize; i++)
    {
        if(letters[i] > target)
        {
            tempArr[tempArrLen++] = letters[i];
        }
    }
    if(tempArrLen == 0)
    {
        return ret;
    }
    ret = tempArr[0];
    for(i = 0; i < tempArrLen; i++)
    {
        if(tempArr[i] < ret)
        {
            ret = tempArr[i];
        }
    }
    return ret;
}