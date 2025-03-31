#include<stdio.h>

//求两个数的最大公约数和最小公倍数
int Least_common_divisor(int num1, int num2)
{
    int ret = 1;
    while(ret)
    {
        //辗转相除法，用num1%num2的余数替换num1，用num2替换num2，直到num1%num2为0
        ret = num1 % num2;
        num1 = num2;
        num2 = ret;
    }
    return num1;
}
int main()
{
    int num1 = 0, num2 = 0;
    int ret = 1;
    scanf("%d %d", &num1, &num2);
    int LeastCommonDivisor = Least_common_divisor(num1, num2);
    int MaxCommonMultiple = num1 * num2 / LeastCommonDivisor;
    printf("%d %d\n", LeastCommonDivisor, MaxCommonMultiple);
    return 0;
}