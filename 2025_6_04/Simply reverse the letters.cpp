char* reverseOnlyLetters(char* s) {
    int sLen = strlen(s);
    char temp = 0;
    char* p1 = s;
    char* p2 = s + sLen - 1;
    while(p1 < p2)
    {
        while(p1 < p2 && !isalpha(*p1))
        {
            p1++;
        }
        while(p1 < p2 && !isalpha(*p2))
        {
            p2--;
        }
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    return s;
}