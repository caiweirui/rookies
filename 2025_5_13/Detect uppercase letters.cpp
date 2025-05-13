bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int i = 0;
    int count = 0;
    for(i = 0; i < len; i++)
    {
        if(isupper(word[i]))
        {
            count++;
        }
    }
    return ((count == 0) || ((count == 1) && isupper(word[0])) || (count == len));

}