#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string.h>

int lengthOfLongestSubstring(char* s) {
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = '0';
    int len = strlen(s);
    int arr[128];
    int ret = 0;
    memset(arr, 0, sizeof(arr));
    if(!len)
    {
        return 0;
    }
    if(len == 1)
    {
        return 1;
    }
    for(k = 0; k < len; k++)
    {
        memset(arr, 0, sizeof(arr));
        for(i = k; i < len; i++)
        {
            temp = 0;
            if(arr[s[i]] == 0)
            {
                arr[s[i]] = 1;
            }
            else
            {
                for(j = 0; j < 128; j++)
                {
                    if(arr[j] == 1)
                    {
                        temp++;
                    }
                }
                if(temp > ret)
                {
                    ret = temp;
                }
                break;
            }
            if(i == len - 1)
            {
                if(arr[s[i]] == 0)
                {
                    arr[s[i]] = 1;
                    for(j = 0; j < 128; j++)
                    {
                        if(arr[j] == 1)
                        {
                            temp++;
                        }
                    }
                    if(temp > ret)
                    {
                        ret = temp;
                    }
                }
                else
                {
                    for(j = 0; j < 128; j++)
                    {
                        if(arr[j] == 1)
                        {
                            temp++;
                        }
                    }
                    if(temp > ret)
                    {
                        ret = temp;
                    }
                }
            }
        }
    }
    return ret;
}

int main()
{
    char arr[] = "abcabcbb";
    int ret = lengthOfLongestSubstring(arr);
    printf("%d\n", ret);
    return 0;
}