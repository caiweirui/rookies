#include<stdio.h>

//输出小于num的数中9的个数
int nine_count(int n)
{ 
    if(n < 9)
    {
        return 0;
    }
    else if(n == 9)
    {
        return 1;
    }
    else
    {
        //判断最低位是否为9，如果是，则+1，不是则+0，然后判断前一位，以此类推
        return nine_count(n / 10) + (n % 10 == 9);
    }
}

int main()
{
    int num = 0 ,count = 0;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    {
        count += nine_count(i);
    }
    printf("%d\n", count);
    return 0;
}