#include<bits/stdc++.h>

// 方法1：旋转对比法
void reverse(char *left, char *right)
{
    char temp = 0;
    while(left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

// 左旋函数
void LeftRotation(char *arr, int k)
{
    int len = strlen(arr);
    reverse(arr, arr + k - 1);
    reverse(arr + k, arr + len - 1);
    reverse(arr, arr + len - 1);
}

// 方法二：
// 用strncat()函数 在arr1后面续接本身，新的arr1包括左旋之后的所有可能性
// 然后用strstr()函数比较arr2
int main()
{
    char arr1[1000] = {0};
    char arr2[1000] = {0};
    gets(arr1);
    gets(arr2);
    int k = 0;
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if(len1 != len2)
    {
        printf("不是\n");
    } 
    else
    {
        for(k = 0; k < len1; k++)
        {
            // 找到第一个相同的字符
            if(arr1[0] == arr2[k])
            {
                break;
            }
        }

        // 没有相同的字符
        if(k == len1)
        {
            printf("不是\n");
        }
        else
        {
            // 左旋判断结果
            LeftRotation(arr2, k);
            if(strcmp(arr1, arr2) == 0)
            {
                printf("是\n");
            }
            else
            {
                printf("不是\n");
            }
        }

    }
    return 0;
}