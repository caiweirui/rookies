// 小游戏：猜数字，如果猜测大了，返回“猜大了”，如果猜测小了，返回“猜小了”;
// 如果猜对了，返回“恭喜你猜对了”。
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int guess = 0;
    int flag = 1;//是否需要再玩一次
    char input[20] = {0};
    char repeat[20] = {0};
    printf("猜数字游戏开始(yes/no):\n");
    //是否参与游戏，最多输入三次
    for(int i = 0; i < 3; i++)
    {
        gets(input);
        if(strcmp(input,"yes")==0)
        {
            break;
        }
        else if(strcmp(input,"no")==0)
        {
            printf("退出游戏\n");
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入:\n");
        }
    }
    while(flag)
    {
        if(strcmp(input,"yes")==0)
        {
            //用srand函数设置随机数种子，用rand函数生成随机数
            //使用时间戳作为随机数种子，每次运行程序，随机数种子不同，生成的随机数也不同
            srand((unsigned int)time(NULL));
            //printf("%zu\n", time(NULL));
            int x = rand() % 100+1;//rand()生成0~rand_max(32767)之间的不是很随机的随机数
            //printf("%d\n",x);
            printf("请输入你猜的数字:\n");
            //无限循环，直到猜对为止
            while(1)
            {
                scanf("%d", &guess);
                if(guess > x)
                {
                    printf("猜大了。\n");
                }
                else if(guess < x)
                {
                    printf("猜小了。\n");
                }
                else
                {
                    printf("恭喜你猜对了!\n");
                    break;
                }
            }
        }
        //是否再玩一次，最多输入三次
        printf("是否再玩一次(yes/no):\n");
        for(int j = 0; j < 3; j++)
        {
            //清空缓冲区
            while(getchar()!= '\n');
            gets(repeat);
            if(strcmp(repeat,"yes")==0)
            {
                flag = 1;
                break;
            }
            else if(strcmp(repeat,"no")==0)
            {
                printf("退出游戏\n");
                flag = 0;
                break;
            }
            else
            {
                printf("输入错误，请重新输入:\n");
            }
            if(j == 2)
            {
                printf("输入错误三次，自动退出游戏\n");
                flag = 0;
            }
        }
    }
    return 0;
}