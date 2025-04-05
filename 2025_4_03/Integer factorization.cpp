#include<stdio.h>

//输出每个累加和等于 N 的连续的自然数段的第一个数和最后一个数，
//两数之间用符号～隔开，每段一行，所有行按每行的第一个数从小到大升序排列。
//如果没有符合条件的自然数段，则输出None。
void int_fac(int num)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int count = 0;
    for(i = 1; i < num / 2; i++)
    {
        sum = 0;
        for(j = i; sum <= num; j++)
        {
            sum += j;
            if(sum == num)
            {
                printf("%d~%d\n", i, j);
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("None\n");
    }
} 

int main()
{
    int num = 0;
    scanf("%d", &num);
    int_fac(num);
    return 0;
}