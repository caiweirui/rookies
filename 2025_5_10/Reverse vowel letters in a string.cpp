bool isVowelLetter(char ch)
{
    return toupper(ch) == 'A' || toupper(ch) == 'E' || 
    toupper(ch) == 'I' || toupper(ch) == 'O' || toupper(ch) == 'U';
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    char* p1 = s;
    char* p2 = s + len - 1;
    char temp = 0;
    while(p1 < p2)
    {
        while(!isVowelLetter(*p1) && p1 < p2)
        {
            p1++;
        }
        while(!isVowelLetter(*p2) && p1 < p2)
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