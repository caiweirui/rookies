#include <stdio.h>
#include <string.h>
#include <ctype.h>

//分离两个操作数
void detch(char *arr, char *arr1, char *arr2, int len)
{
    int i = 0;
    //存储第一个加数
    while(arr[i] != '+' && arr[i] != '-')
    {
        arr1[i] = arr[i];
        i++;
    }
    i++;
    int len1 = strlen(arr1);
    while(i < len)
    {
        arr2[i - len1 - 1] = arr[i]; 
        i++;
    }

}

//对阶，小阶化大阶
void match(char *arr1, char *arr2, int *lenret)
{
    int i = 0;
    int len1 = 0;
    int len2 = 0;
    int lensub = 0;
    len1 = strlen(arr1);
    len2 = strlen(arr2);
    //第一个数字长
    if(len1 > len2)
    {
        lensub = len1 - len2;
        //strncmp(arr2 + lensub, arr2, len2);
        for(i = len2 - 1; i >= 0; i--)
        {
            arr2[i + lensub] = arr2[i]; 
        }
        //前面补充0
        for(i = 0; i < lensub; i++)
        {
            arr2[i] = '0';
        }
        *lenret = len1;
    }
    else if(len1 < len2)
    {
        lensub = len2 - len1;
        //strncmp(arr1 + lensub, arr1, len1);

        for(i = len1 - 1; i >= 0; i--)
        {
            arr1[i + lensub] = arr1[i]; 
        }

        for(i = 0; i < lensub; i++)
        {
            arr1[i] = '0';
        }
        *lenret = len2;
    }
    else
    {
        *lenret = len1;
    }
}

//加法操作
void add(char *arr, int len)
{
    int i = 0;
    int j = 0;
    int cf = 0;
    char arr1[1000] = {'0'};
    char arr2[1000] = {'0'};
    char ret[1000] = {'0'};
    int lenret = 0;

    //分开和对阶
    detch(arr, arr1, arr2, len);
    match(arr1, arr2, &lenret);

    //两个操作数从后往前
    //ret从前往后接收，最后要反着打印
    for(i = lenret - 1; i >= 0; i--)
    {
        //cf+两个操作数 - '0' * 2 + '0'
        ret[j] = cf + arr1[i] + arr2[i] - '0';
        //判断进位，要加上cf一起判断
        if((arr1[i] + arr2[i] - 2 * '0' + cf) >= 10)
        {
            //有进位要cf置1，同时要减去10
            cf = 1;
            ret[j] = ret[j] - 10;

        }
        else
        {
            cf = 0;
        }
        //不要忘记ret的下标++
        j++;
    }

    //最后检查进位标记，是的话还要最后一位加'1'
    if(cf == 1)
    {
        ret[lenret] = '1';
    }
    //ret的更新长度
    lenret = strlen(ret);

    //打印ret
    for(i = lenret - 1; i >=0; i--)
    {
        printf("%c", ret[i]);
    }
    printf("\n");
}

//减法操作
void sub(char *arr, int len)
{
    int i = 0;
    int j = 0;
    int cf = 0;
    char arr1[1000] = {'0'};
    char arr2[1000] = {'0'};
    char ret[1000] = {'0'};
    int lenret = 0;
    int sflag = 0;
    int zflag = 0;

    //分开和对阶
    detch(arr, arr1, arr2, len);
    match(arr1, arr2, &lenret);

    //保证arr1 > arr2
    if(strcmp(arr1, arr2) < 0)
    {
        char temp[1000] = {'0'};
        strcpy(temp, arr1);
        strcpy(arr1, arr2);
        strcpy(arr2, temp);
        sflag = -1;
    }

    //借位
    for(i = lenret - 1; i >= 0; i--)
    {
        //cf+两个操作数 - '0' * 2 + '0'
        ret[j] = arr1[i] - arr2[i] - cf + '0';
        //判断进位，要加上cf一起判断
        if((arr1[i] - arr2[i]  - cf) < 0)
        {
            //有借位要置1
            cf = 1;
            ret[j] = ret[j] + 10;

        }
        else
        {
            cf = 0;
        }
        //不要忘记ret的下标++
        j++;
    }

    //打印ret
    //判断正负
    if(sflag)
    {
        printf("-");
    }

    //前面0不能输出
    for(i = lenret - 1; i >=0; i--)
    {
        //当出现第一个非0时输出
        while(ret[i] == '0' && !zflag && i >= 0)
        {
            i--;
        }
        if(i >= 0)
        {
            printf("%c", ret[i]);
            zflag = 1;
        }
    }
    if(!zflag)
    {
        printf("0");
    }
    printf("\n");
}

int main()
{
    int num = 0;
    char arr[2000] = {'0'};
    int i = 0;
    int j = 0;
    int len = 0;
    scanf("%d", &num);
    getchar();
    for(i = 0; i < num; i++)
    {
        scanf("%s", &arr);
        len = strlen(arr);
        for(j = 0; j < len; j++)
        {
            if(arr[j] == '+')
            {
                add(arr, len);
            }
            if(arr[j] == '-')
            {
                sub(arr, len);
            }
        }
        getchar();
    }
    return 0;
} 