#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

void find_ac(char *arr, int arrlen)
{
    int i = 0;
    int j = 0;
    int max = 0;
    int count = 0;
    char ch = '0';
    for(i = 0; i < arrlen; i++)
    {
        ch = *(arr + i);
        *(arr + i) = 'A';
        count = 0;
        for(j = 0; j < arrlen - 1; j++)
        {
            if(*(arr + j) == 'A' && *(arr + j + 1) == 'C')
            {
                count++;
            }
        }
        if(count > max)
        {
            max = count;
        }
        *(arr + i) = ch;
    }
    for(i = 0; i < arrlen; i++)
    {
        ch = *(arr + i);
        *(arr + i) = 'C';
        count = 0;
        for(j = 0; j < arrlen - 1; j++)
        {
            if(*(arr + j) == 'A' && *(arr + j + 1) == 'C')
            {
                count++;
            }
        }
        if(count > max)
        {
            max = count;
        }
        *(arr + i) = ch;
    }

    printf("%d\n", max);
}

int main()
{
    char arr[1001] = {'0'};
    gets(arr);
    int arrlen = strlen(arr);

    find_ac(arr, arrlen);

    return 0;
}