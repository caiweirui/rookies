int titleToNumber(char* columnTitle) {
    int len = strlen(columnTitle);
    int i = 0;
    int ret = 0;
    for(i = 0; i < len; i++)
    {
        ret = columnTitle[i] - 'A' + 1 + ret * 26;
    }
    return ret;
}