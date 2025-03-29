//关机程序，输入yes，电脑在60s后关机，输入no，取消关机
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//60秒倒计时
void countdown()
{
    for(int i = 60; i > 0; i--)
    {
        printf("%02d秒\n", i);
        Sleep(1000);
    }
    fflush(stdout);
    sleep(1000);
    printf("时间到\n");
}

int main()
{
    char input[100];
    system("shutdown -s -t 60");//关机命令
    again:
    printf("电脑在60s关机，输入yes继续，no取消:\n");
    //countdown();
    for(int i = 0; i < 3; i++)
    {
        gets(input);
        if(strcmp(input,"yes")==0)
        {
            printf("电脑将在5秒后关机\n");
            system("shutdown -s -t 5");
            break;
        }
        else if(strcmp(input,"no")==0)
        {
            printf("取消关机\n");
            system("shutdown -a");//取消关机命令
            break;
        }
        else
        {
            printf("输入错误，请重新输入：\n");
        }
        if(i == 2)
        {
            printf("输入错误三次，再次提示");
            goto again;
        }
    }
    return 0;
}