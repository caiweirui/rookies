#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int cmp1(const void *e1, const void *e2)
{
    return *((char*)e1) - *((char*)e2);
} 

int cmp2(const void *e1, const void *e2)
{
    return *((char*)e2) - *((char*)e1);
} 

int main()
{
    char arr[11][51] = {"ABCDEFGHIJKLMNabcdefghijklmn",
        "NMLKJIHGFEDcbanmlkjihgfedCBA", 
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB"};
    int row = 4;
    int col = strlen(arr[0]);
    int i = 0;
    int j = 0;

    for(i = 0; i < 4; i++)
    {
        qsort(arr[i], col, sizeof(arr[0][0]), cmp1);
    }
    
    qsort(arr[0], 4, sizeof(arr[0]), cmp2);

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}