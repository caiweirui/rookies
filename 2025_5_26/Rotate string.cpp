bool rotateString(char* s, char* goal) {
    int sLen = strlen(s);
    int gLen = strlen(goal);
    if(sLen != gLen)
    {
        return 0;
    }
    char* temp = (char*)calloc(sLen * 2 + 1, sizeof(char));
    strcat(temp, s);
    strcat(temp, s);
    return strstr(temp, goal);
}