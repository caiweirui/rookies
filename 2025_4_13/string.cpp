#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

struct str
{
    char ch[1];
    int num;
};

int cmp(const void *e1, const void *e2)
{
    return ((struct str*)e2)->num - ((struct str*)e1)->num; 
}

int main()
{
    char arr[1000] = {'0'};
    gets(arr);
    int len = strlen(arr);
    int i = 0;
    struct str s[1000]; 
    int j = 0;
    int lens = 0;
    int flag = 0;
    for(i = 0; i < len; i++)
    {
        if(isupper(arr[i]))
        {
            flag = 0;
            for(j = 0; j <= lens; j++)
            {
                if(*(s[j].ch) == arr[i])
                {
                    s[j].num++;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                *(s[lens].ch) = arr[i];
                s[lens].num = 1;
                lens++;
            }

        }
    }
    qsort(s, lens, sizeof(s[0]), cmp);

    for(j = 0; j < lens; j++)
    {
        printf("%c %d\n", *(s[j].ch), s[j].num);
    }

    return 0;
}