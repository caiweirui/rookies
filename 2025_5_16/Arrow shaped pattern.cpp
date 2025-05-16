#include<stdio.h>

//  01234  j
// 0    *
// 1  **
// 2***
// 3  **
// 4    *
// i

int main()
{
    int input = 0;
    fscanf(stdin, "%d", &input);
    int i = 0;
    int j = 0;
    for(i = 0; i < input; i++)
    {
        for(j = 0; j < 2 * (input - i); j++)
        {
            printf(" ");
        }
        for(j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i = 0; i < input + 1; i++)
    {
        printf("*");
    }
    printf("\n");
    for(i = 0; i < input; i++)
    {
        for(j = 0; j < 2 * (i + 1); j++)
        {
            printf(" ");
        }
        for(j = 0; j < input - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}