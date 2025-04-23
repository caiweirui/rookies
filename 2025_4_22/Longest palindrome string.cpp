#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string.h>

char* longestPalindrome(char* s) {
    int i = 0;
    int j = 0;
    int temp = 0;
    int k = 0;
    int len = strlen(s);
    char *p1 = s;
    char *p2 = s;
    int flag = 0;
    int max = 1;
    char* p = s;
    if(len == 0)
    {
        *p = 0;
        return p;
    }
    if(len == 1)
    {
        *(p + 1) = 0;
        return p;
    }
    if(len == 2)
    {
        if(s[0] == s[1])
        {
            *(p + 2) = 0;
            return p;
        }
        else
        {
            *(p + 1) = 0;
            return p;
        }
    }
    // for(i = 0; i < len - 1; i++)
    // {
    //     p1 = s + i;
    //     for(j = i + 1; j < len; j++)
    //     {
    //         if(s[i] == s[j])
    //         {
    //             p2 = s + j;
    //             break;
    //         }
    //     }
    //     if(s[i] != s[j])
    //     {
    //         continue;
    //     }
    //     while(p1 < p2)
    //     {
    //         if(*p1 != *p2)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //         p1++;
    //         p2--;
    //     }
    //     if(!flag)
    //     {
    //         temp = j - i + 1;
    //         if(temp > max)
    //         {
    //             p = s + i;
    //             max = temp;
    //         }
    //     }
    //     flag = 0;
    //     p2 = s;
    // }
    // *(p + max) = 0;
    // return p;

    for(i = 0; i < len; i++)
    {
        p1 = s + i;
        p2 = s + len - 1;
        for(j = len - 1; j >= i + 1; j--)
        {
            flag = 0;
            if(s[i] == s[j])
            {
                p2 = s + j;
                while(p1 < p2)
                {
                    if(*p1 != *p2)
                    {
                        flag = 1;
                        p1 = s + i;
                        break;
                    }
                    p1++;
                    p2--;
                }
                if(!flag)
                {
                    temp = j - i + 1;
                    if(max < temp)
                    {
                        max = temp;
                        p = s + i;
                    }
                    break;
                }
            }
        }
    }

    *(p + max) = 0;

    return p;
}

int main()
{
    char arr[10000] = {0};
    gets(arr);
    printf("%s\n", longestPalindrome(arr));
    return 0;

}