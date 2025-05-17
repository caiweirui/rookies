void reverse(char *s, int left, int right)
{
    char temp = 0;
    while(left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int i = 0;
    int len = strlen(s);
    int left = 0;
    int right = -1;
    for(i = 0; i < len; i++)
    {
        if(isspace(s[i]))
        {
            right = i - 1;
        }
        if(i == len - 1)
        {
            right = i;
        }
        if(right != -1)
        {
            reverse(s, left, right);
            left = i + 1;
            right = -1;
        }
    }
    return s;
}