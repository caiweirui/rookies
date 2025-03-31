#include<stdio.h>

//递归求字符串长度，模拟strlen，strlen的机制是遍历字符串，每次+1，直到遇到'\0'
int Strlen(char* str)
{
    if(*str == '\0')
    {
        return 0;
    }
    else
    {
        //不要改变str的值，所以用str+1，不能用++str，str++没用
        return 1 + Strlen(str+1);
    }
}

int main()
{
    char arr[100] = {0};
    scanf("%s", arr);
    printf("%d\n", Strlen(arr));
    return 0;
}