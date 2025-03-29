//编写代码实现，模拟用户登录情景，并且只能登录三次。
//（只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。
#include <stdio.h>
#include <string.h>

int main()
{
    char password[] = {"123456"};
    char input[20] = {0};
    int i = 0;
    //三次输入机会
    while(i < 3)
    {
        gets(input);
        //strcmp函数比较两个字符串是否相等，相等返回0，不相等返回1
        if(strcmp(input, password) == 0)
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误，请重新输入\n");
            i++;
        }
    }
    //三次输入错误，退出程序
    if(i == 3)
    {
        printf("密码连续错误三次，退出程序\n");
    }
    return 0;
}
