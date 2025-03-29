//编写代码，演示多个字符从两端移动，向中间汇聚
#include <windows.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100] = {0}, str2[100] = {0};
    int i = 0, j = 0;
    while(1)
    {
        str[i++]=getchar();
        if(str[i-1] == '\n')
        {
            break;
        }
    }
    int len = strlen(str)-1;
    printf("%d\n", len);
    for (i = 0; i < len; i++)
    {
        str2[i] = '#';
    }
    //当长度为偶数时
    if (len % 2 == 0)
    {
        for (i = 0; i < len; i++)
        {
            str2[i] = str[i];
            str2[len-i-1] = str[len-i-1];
            for(j = 0; j < len; j++)
            {
                printf("%c", str2[j]);
            }
            Sleep(1000);//程序暂停1秒
            printf("\r\n");
        }
    }
    //当长度为奇数时
    else
    {
        for (i = 0; i < (len + 1) / 2; i++)
        {
            str2[i] = str[i];
            str2[len-i-1] = str[len-i-1];
            for(j = 0; j < len; j++)
            {
                printf("%c", str2[j]);
            }
            Sleep(1000);
            printf("\r\n");
        }
    
    }
    printf("%s\n", str); // 替代逐字符的 for 循环
    return 0;
}