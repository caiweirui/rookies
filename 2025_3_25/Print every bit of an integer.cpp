#include<stdio.h>

//递归打印一个整数的每一位
void depart(int n)
{
    //会先进行递归，再进行打印
    if(n>9)
    {
        //这里加return会直接结束递归
        depart(n/10);
    }
    printf("%d ", n%10);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    depart(n);
    return 0;   
}