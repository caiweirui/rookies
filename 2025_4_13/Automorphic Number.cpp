#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
    long long num = 0;
    scanf("%ld", &num);
    long long temp = num;
    int div = 1;
    while(temp / 10)
    {
        temp /= 10;
        div *= 10;
    }

    if((num * num - num) % div == 0 && num != div)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}