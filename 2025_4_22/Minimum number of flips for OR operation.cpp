#include<stdio.h>

// 或运算的最小翻转次数
void filp(int *n, int left, int right)
{
    int temp = 0;
    int num1 = (*n >> right) & 1;
    int num2 = (*n >> left) & 1;
    *n = *n - (num1 << right);
    *n = *n - (num2 << left);
    temp = num1;
    num1 = num2;
    num2 = temp;
    *n = *n + (num1 << right);
    *n = *n + (num2 << left);
}

int minFlips(int a, int b, int c) {
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    int ret = 0;
    int i = 0;
    for(i = 0; i < 32; i++)
    {
        a1 = (a >> i) & 1;
        b1 = (b >> i) & 1;
        c1 = (c >> i) & 1;
        if((a1 | b1) != c1)
        {
            if(a1 == 0 && b1 == 0)
            {
                ret++;
            }
            else if(a1 == 1 && b1 == 0)
            {
                ret++;
            }
            else if(a1 == 0 && b1 == 1)
            {
                ret++;
            }
            else
            {
                ret += 2;
            }
        }
    }
    return ret;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    int ret = 0;

    ret = minFlips(a, b, c);

    printf("%d\n", ret);

    return 0;
}