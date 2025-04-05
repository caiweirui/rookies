#include<stdio.h>
#include<string.h>
#include<math.h>

//返回身份证的校验位
char efficient(char *idcard)
{
    int sum = 0;
    int arr[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int i = 0;
    for(i = 0; i < 17; i++)
    {
        sum += arr[i] * (idcard[i] - '0');
    }
    // switch(sum % 11)
    // {
    //     case 0: return '1';break;
    //     case 1: return '0';break;
    //     case 2: return 'X';break;
    //     case 3: return '9';break;
    //     case 4: return '8';break;
    //     case 5: return '7';break;
    //     case 6: return '6';break;
    //     case 7: return '5';break;
    //     case 8: return '4';break;
    //     case 9: return '3';break;
    //     case 10: return '2';break;
    //     default:break;
    // }

    char codes[] = "10X98765432";
    return codes[sum % 11];
}

//15位身份证
//1. 判断世纪
//2. 升级成正确的18位身份证
//3. 输出升级之后的身份证号码
void idcard15(char *idcard)
{
    int i = 0;
    //判断世纪
    //strncmp(id + 12, "996", 3) 是返回0，不是返回1
    //strncpy(new_id + 8, id + 6, 6); 复制字符串
    //isdigit(char ch)判断是不是数字（头文件是ctype.h）
    //strcspn(id, "\n")去除换行符
    if(*(idcard + 12) == '9' && *(idcard + 13) == '9' && (*(idcard + 14) >= '6' && *(idcard + 14) <= '9'))
    {
        //18世纪老人：下标 6-14 -> 8-16
        //6-7 -> 18
        for(i = 14; i >= 6; i--)
        {
            *(i + idcard + 2) = *(i + idcard);
        }
        *(idcard + 6) = '1';
        *(idcard + 7) = '8';
        *(idcard + 17) = efficient(idcard);
    }
    else
    {
        //19世纪老人
        for(i = 14; i >= 6; i--)
        {
            *(i + idcard + 2) = *(i + idcard);
        }
        *(idcard + 6) = '1';
        *(idcard + 7) = '9';
        *(idcard + 17) = efficient(idcard);
    }
    printf("%s\n", idcard);
}

//18位身份证，判断是否有效即可
void idcard18(char *idcard)
{
    if(idcard[17] == efficient(idcard))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

int main()
{
    int num = 0;
    char idcard[20] = {'0'};
    int i = 0;
    int j = 0;
    int len = 0;
    scanf("%d", &num);
    getchar();
    for(i = 0; i < num; i++)
    {
        len = 0;
        gets(idcard);
        len = strlen(idcard);
        if(len == 15)
        {
            idcard15(idcard);
        }
        else if(len == 18)
        {
            idcard18(idcard);
        }
        else
        {
            printf("Invalid\n");
        }
        
    }
    return 0;
}