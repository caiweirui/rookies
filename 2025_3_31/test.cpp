#include<stdio.h>
#include<string.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

//普通方法实现逆序
// void reverse_string(char *ch)
// {
//     int len = strlen(ch);
//     int i = 0;
//     if(1 != len)
//     {
//         for(i = 0; i < len / 2; i++)
//         {
//             swap(&ch[i], &ch[len-i-1]);
//         }
//     }
// }

//递归实现逆序
//拆分成交换收尾两个字符+交换中间字符串的动作
//具体实现：将ch[0]的内容先转移到临时变量里面，把原来的ch[len-i-1]的内容转移到ch[0]中
//然后将原来的ch[len-i-1]的内容置为'\0'
//逆序中间的字符串，将存储在临时变量中的ch[0]转移到ch[len-i-1]中
// void reverse_string(char *ch)
// {
//     char temp = *ch;
//     int len = 0;
//     len = strlen(ch);
//     *ch = *(ch + len - 1);
//     *(ch + len - 1) = '\0';
//     if(strlen(ch + 1) >= 2)
//     {
//         reverse_string(ch + 1);
//     }
//     *(ch + len - 1) = temp;
// }

// int main()
// {
//     char ch[1000] = {0};
//     gets(ch);
//     reverse_string(ch);
//     for(int i = 0; i < strlen(ch); i++)
//     {
//         printf("%c", ch[i]);
//     }
//     printf("\n");
//     return 0;
// }

//递归多参数版本
// void reverse_string(char *ch, int left, int right)
// {
//     swap(&ch[left], &ch[right]);
//     if(left < right)
//     {
//         reverse_string(ch, left + 1, right - 1);
//     }
// }

// int main()
// {
//     char ch[1000] = {0};
//     gets(ch);
//     reverse_string(ch, 0, strlen(ch) - 1);
//     for(int i = 0; i < strlen(ch); i++)
//     {
//         printf("%c", ch[i]);
//     }
//     printf("\n");
//     return 0;
// }

//计算输入的一个数字的每一位之和
// int digit_sum(int num)
// {
//     if(num <= 9)
//     {
//         return num;
//     }
//     else
//     {
//         return digit_sum(num / 10) + num % 10;
//     }
// }
// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     int sum = digit_sum(num);
//     printf("%d\n", sum);
//     return 0;
// }

int main()
{

    return 0;
}