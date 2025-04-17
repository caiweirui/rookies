#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


// 2185.统计包含给定前缀的字符串

// 给你—个字符串数组words和一个字符串pref。
// 返回words中以pref作为前缀的字符串的数目。
// 字符串的前缀就是的任一前导连续字符串。

int prefixCount(char** words, int wordsSize, char* pref) {
    int i = 0;
    int count = 0;
    for(i = 0; i < wordsSize; i++)
    {
        if(!strncmp(words[i], pref, strlen(pref)))
        {
            count++;
        }
    }
    return count;
}