#include <bits/stdc++.h>  
using namespace std;  

// 1. 奇数转换成1，偶数转换成0
// 2. 最前面的0要删除
int main()
{
    char arr[100] = {'0'};
    scanf("%s", arr);
    int i = 0;
    int len = strlen(arr);
    for(i = 0; i < len; i++)
    {
        arr[i] = arr[i] % 2 + '0';
    }
    int flag = 0;
    for(i = 0; i < len; i++)
    {
        if(arr[i] == '1')
        {
            flag = 1;
        }
        if(flag)
        {
            printf("%c", arr[i]);
        }
    }
    if(!flag)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}