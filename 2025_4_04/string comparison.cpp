#include<stdio.h>
#include<string.h>

//给定一组字符串，给定一个关键字，请你计算出这些字符串所有的子串中与这个关键字发生重叠的次数。
int main()
{
    char arr1[1000];
    char arr2[1000];
    scanf("%s", arr1);
    getchar();
    scanf("%s", arr2);
    int i = 0;
    int count = 0;
    for(i = 0; i < strlen(arr1) - strlen(arr2) + 1; i++)
    {
        if(strncmp(arr1 + i, arr2, strlen(arr2)) == 0)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}