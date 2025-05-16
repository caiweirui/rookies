#include<stdio.h>

#define SWAP_BIT(num) (((num) & 0x55555555) << 1) + (((num) & 0xaaaaaaaa) >> 1)

int main()
{
    int a = 0;
    scanf("%d", &a);
    printf("%d\n", SWAP_BIT(a));
    return 0;
}
