#include<stdio.h>
#include<string.h>

int countBinarySubstrings(char* s) {
    int i = 0;
    int len = strlen(s);
    int count0 = 0;
    int count1 = 0;
    int ret = 0;
    while(s[i] == '1')
    {
        i++;
    }
    while(i < len)
    {
        count0 = 0;
        count1 = 0;
        while(s[i] == '0')
        {
            count0++;
            i++;
        }
        while(s[i] == '1')
        {
            count1++;
            i++;
        }
        ret += (count1 > count0) ? count0 : count1;

    }
    i = 0;
    while(s[i] == '0')
    {
        i++;
    }
    while(i < len)
    {
        count0 = 0;
        count1 = 0;
        while(s[i] == '1')
        {
            count1++;
            i++;
        }
        while(s[i] == '0')
        {
            count0++;
            i++;
        }
        ret += (count1 > count0) ? count0 : count1;
    }
    
    return ret;
}

int main()
{
    char *s = "00110011";
    printf("%d\n", countBinarySubstrings(s));
    return 0;
}