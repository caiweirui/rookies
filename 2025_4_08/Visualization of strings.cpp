#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

//判断每个字母有多少个
//排序：1. 按照个数     2. 按照字母序
//可视化输出，最后一行输出大写

// #                                                 
// #                                                 
// #                                                 
// # # # # # #                                       
// # # # # # # # #                                   
// # # # # # # # # # # # # # # # # # # #             
// E A H I N U D O B C G J L Q S T W Y Z F K M P R V X

void print(const char *arr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int number[2][30] = {0};
    int len = strlen(arr);
    int max = 0;
    int flag = 0;

    //构建数组
    for(i = 0; i < len; i++)
    {
        number[1][toupper(arr[i]) - 'A']++;
    }
    for(i = 0; i < 26; i++)
    {
        number[0][i] = 'A' + i;
    }

    //排序，从A到E已经默认字母序了
    for(i = 0; i < 25; i++)
    {
        for(j = 0; j < 25; j++)
        {
            if(number[1][j] < number[1][j + 1])
            {
                for(k = 0; k < 2; k++)
                {
                    temp = number[k][j];
                    number[k][j] = number[k][j + 1];
                    number[k][j + 1] = temp;
                }

            }
        }
    }

    //有数字打印"#"，没数字打印 
    while(flag != 26)
    {
        flag = 0;
        max = number[1][0];
        for(i = 0; i < 26; i++)
        {
            if(max == number[1][i])
            {
                printf("# ");
                number[1][i]--;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
        for(j = 0; j < 26; j++)
        {
            if(number[1][j] == 0)
            {
                flag++;
            }
        }
    }

    //打印"坐标轴"
    for(i = 0; i < 26; i++)
    {
        printf("%c ", number[0][i]);
    }


    // for(i = 0; i < 26; i++)
    // {
    //     printarr[10000][i] = 'A' + i;
    // }
    // int j = 0;
    // for(i = 0; i < 26; i++)
    // {

    // }
}

int main()
{
    char arr[10001] = {'0'};
    scanf("%s", arr);
    print(arr);
    return 0;
}