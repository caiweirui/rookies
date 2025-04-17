#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 2186.字母异位词
// 给你两个字符串和。在一步操作中，你可以给或者追加任一字符。
// 返回使s和t互为字母异位词所需的最少步骤数。
// 字母异位词指字母相同但是顺序不同（或者相同）的字符串。


int cmp(const void *e1, const void *e2)
{
    return (*((char *)e1) - *((char *)e2));
}

int minSteps(char* s, char* t) {
    //两个字符串中加上另一个有，我们没有的部分
    //相同字符的个数
    //一共的个数
    //一共-相同*2
    int len1 = strlen(s);
    int len2 = strlen(t);

    qsort(s, len1, sizeof(char), cmp);
    qsort(t, len2, sizeof(char), cmp);

    char *p1 = s;
    char *p2 = t;

    int same = 0;

    while(*p1 && *p2)
    {
        if(*p1 == *p2)
        {
            same++;
            p1++;
            p2++;
        }
        else if(*p1 > *p2)
        {
            p2++;
        }
        else
        {
            p1++;
        }
    }
    return (len1 + len2 - 2 * same);

}

int main()
{
    char arr1[1000] = {'0'};
    char arr2[1000] = {'0'};
    gets(arr1);
    getchar();
    gets(arr2);
    int ret = minSteps(arr1, arr2);
    printf("%d\n", ret);
    return 0;
}