#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

//返回相同的字符个数
int number(const char *mainarr, const char *arr)
{
    int i = 0;
    int len = strlen(arr);
    int count = 0;
    for(i = 0; i < len; i++)
    {
        if(mainarr[i] == arr[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char mainarr[101] = {'0'};
    char arr[101] = {'0'};
    scanf("%s", mainarr);
    getchar();
    scanf("%s", arr);
    int i = 0;
    int mainlen = strlen(mainarr);
    int len = strlen(arr);
    int count = 0;
    for(i = 0; i <= mainlen - len; i++)
    {
        //找到最大的相同字符个数
        if(count < number(mainarr + i, arr))
        {
            count = number(mainarr + i, arr);
        }
    }
    if(mainlen >= len)
        printf("%d\n", len - count);
    else
        printf("-1\n");

    return 0;
}
