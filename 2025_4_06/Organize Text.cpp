#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

// 1.每一句话首字母大写，其余字母小写（默认以’.’分割每一句话）；
// 2.清除多余的空格：
// 每一个单词最后要有一个空格；
// 如果单词后有标点的，只在标点后有一个空格（标点只有’,’’.’）；
// 第一个单词前和最后一个标点后不留空格）。
void organize_text(char *arr)
{
    int i = 0;
    int len = strlen(arr);
    int j = 0;
    int flag = 0;

    //是否有需要保留空格，前面的空格消不掉真的sm了
    for(i = 0; i < len; i++)
    {
        if(arr[i] == ' ' && (!isalpha(arr[i + 1])))
        {
            for(j = i; j < len - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[--len] = '\0';
            i--;
        }
    }

    //大小写转换
    for(i = 0; i < len; i++)
    {
        while(*arr == ' ' && !flag)
        {
            for(j = i; j < len - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[--len] = '\0';
            i--;
            flag = 1;
        }
        *arr = toupper(*arr);
        if(isupper(arr[i]))
        {
            arr[i] = tolower(arr[i]);
        }
        if(islower(arr[i]) && arr[i - 2] == '.')
        {
            arr[i] = toupper(arr[i]);
        }
    }
}

int main()
{   
    char arr[256] = {'0'};
    gets(arr);
    organize_text(arr);
    printf("%s\n", arr);
    return 0;
}