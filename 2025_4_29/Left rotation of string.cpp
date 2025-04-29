#include<bits/stdc++.h>

// 解法1：
// 左旋字符串
// 每次左旋1哥单词
// 循环k次

void fun1(char* arr, int k)
{
    int len = strlen(arr);
    k = k % len;
    strncat(arr + len, arr, k);
    memmove(arr, arr + k, len);
    arr[len] = '\0';
}

// 解法2：
// 区分第一部分和第二部分
// 逆序两个部分
// 整体逆序
void reverse(char *p1, char *p2)
{
    char temp = 0;
    while(p1 < p2)
    {
        temp = *p2;
        *p2-- = *p1;
        *p1++ = temp;
    }
}
int main()
{
    int k = 0;
    scanf("%d", &k);
    getchar();
    char arr[1000] = {0};
    gets(arr);
    int len = strlen(arr);

    // fun1(arr, k);
    k = k % len;

    reverse(arr , arr + k - 1);
    reverse(arr + k, arr + len - 1);
    reverse(arr, arr + len - 1);
    
    printf("%s\n", arr);
    return 0;
}