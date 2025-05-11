bool canConstruct(char* ransomNote, char* magazine) {
    int hash[129];
    memset(hash, 0, sizeof(int) * 129);
    int i = 0;
    int lenr = strlen(ransomNote);
    int lenm = strlen(magazine);
    for(i = 0; i < lenm; i++)
    {
        hash[magazine[i]]++;
    }
    for(i = 0; i < lenr; i++)
    {
        if(hash[ransomNote[i]] > 0)
        {
            hash[ransomNote[i]]--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}