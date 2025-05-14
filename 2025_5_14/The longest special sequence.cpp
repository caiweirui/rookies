int findLUSlength(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);

    if(strcmp(a, b))
    {
        return ((lena > lenb) ? lena : lenb);
    }

    return -1;
}