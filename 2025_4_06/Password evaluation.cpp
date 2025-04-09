#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

//其密码强度的规则如下:密码至少要有6位，且包含数字和字母，否则该密码无效；
//在有效密码中，若密码位数大于10位、大小写字母均有、含有特殊符号这三种条件均不满足，该密码强度为弱；
//满足这三种条件任意一个或者两个，则该密码强度为中；
//三种条件均满足，该密码强度为强。
int main()
{
    int num = 0;
    scanf("%d", &num);
    int i = 0;
    int j = 0;
    int len = 0;
    int n = 0;
    char arr[21] = {'0'};
    for(i = 0; i < num; i++)
    {
        int alphaflag = 0;
        int upperflag = 0;
        int lowerflag = 0;
        int numflag = 0;
        int otherflag = 0;
        int count = 0;
        scanf("%d %s", &n, arr);

        //少于6位
        if(n < 6)
        {
            printf("INVALID\n");
        }
        else
        {
            len = strlen(arr);
            for(j = 0; j < len; j++)
            {
                //是否是字母
                if(isalpha(arr[j]))
                {
                    alphaflag = 1;
                    if(isupper(arr[j]))
                    {
                        upperflag = 1;
                    }
                    if(islower(arr[j]))
                    {
                        lowerflag = 1;
                    }
                }
                //是否是数字
                else if(isdigit(arr[j]))
                {
                    numflag = 1;
                }
                //是否是其他符号
                else
                {
                    otherflag = 1;
                }
            }
            //判断是否同时含有字母和数字
            if(numflag && alphaflag)
            {
                count = (upperflag && lowerflag) + otherflag + len / 11;
                switch(count)
                {
                    case 0: printf("RUO\n");break;
                    case 1:
                    case 2: printf("ZHONG\n");break;
                    case 3: printf("QIANG\n");break;
                    default:break;
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    return 0;
}