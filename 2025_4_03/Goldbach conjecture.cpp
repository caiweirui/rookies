#include<stdio.h>
#include<math.h>

//验证哥德巴赫猜想：任何大于4的偶数均可分解为两个素数之和
int is_Prime_number(int num)
{
    int i = 0;
    for(i = 2; i < num / 2 ; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int num = 0;
    printf("请输入一个偶数：");
    scanf("%d", &num);
    printf("\n");
    int i = 0;
    if(num % 2 == 0)
    {
        for(i = 2; i < num / 2; i++)
        {
            if(is_Prime_number(i) && is_Prime_number(num - i))
            {
                printf("%d=%d+%d\n", num, i, num - i);
                break;
            }
        }
    }
    else
    {
        printf("请输入偶数。\n");
    }

    return 0;
}