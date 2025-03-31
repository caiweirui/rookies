#include<stdio.h>

//打印九九乘法表
void print_multiplication_table()
{
    int i = 0, j = 0;
    //打印9行
    for(i = 1; i <= 9; i++)
    {
        //打印9列，j不能大于i
        for(j = 1; j <= i; j++)
        {
            //输出2d，两位右对齐，输出-2d，两位左对齐
            printf("%d×%d=%2d ", j, i, i * j);
            //printf("%d×%d=%-2d ", i, j, i * j);
        }
        printf("\n");
    }
}

int main()
{
    print_multiplication_table();
    return 0;
}