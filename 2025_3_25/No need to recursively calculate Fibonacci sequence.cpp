#include<stdio.h>

//不用递归求斐波那契数列
int fib(int n)
{
    int num1 = 1, num2 = 1, num3 = 0;
    if(n == 1 || n == 2)
    {
        return 1;
    }
    //1 1 2 3 5 8 13 21 34 55
    for(int i = 2; i < n; i++)
    {
        //令num3存储num1+num2的值，然后num1=num2，num2=num3
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    printf("%d\n",fib(num));
    return 0;
}