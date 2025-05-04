int lengthOfLastWord(char* s) {
    int len = strlen(s);
    char *p1 = s + len - 1;
    while(*p1 == ' ')
    {
        p1--;
    }
    char* temp = p1;
    while(p1 >= s && *p1 != ' ')
    {
        p1--;
    }
    return temp - p1;
}