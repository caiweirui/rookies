#include <stdio.h>
#include <string.h>
#include <assert.h>
#include<math.h>

//1
//1+11
//1+11+111
// int add(const int a, const int n)
// {
//     int sum = 0;
//     if(n > 1)
//     {
//         int i = 0;
//         int j = 0;
//         for(i = 0; i < n; i++)
//         {
//             j += a * (int)pow(10, i);
//         }
//         return j + add(a, n - 1);
//     }
//     else
//     {
//         return a;
//     }
// }

// int main()
// {
//     int a = 0;
//     int n = 0;
//     scanf("%d %d", &a, &n);
//     int sum = add(a, n);
//     printf("%d\n",sum);
//     return 0;
// }

// int is_lily_number(const int num)
// {
//     int dight = 0;
//     int i = 0;
//     int j = 1;
//     int sum = 0;
//     //获取位数
//     while(j <= num)
//     {
//         j *= 10;
//         dight++;
//     }
//     //计算每一项的n次方相加
//     j = num;
//     while(j > 0)
//     {
//         sum += (int)pow(j % 10, dight);
//         j /= 10;
//     } 
//     return sum == num;
//     // if(sum == num)
//     // {
//     //     return 1;
//     // }
//     // else
//     // {
//     //     return 0;
//     // }
// }

// int main()
// {
//     int i = 0;
//     for(i = 0; i < 100000; i++)
//     {
//         if(is_lily_number(i))
//         {
//             printf("%d ", i);
//         }
//     }
//     printf("\n");
//     return 0;
// }

// 打印菱形
//  *
// ***
//*****
// ***
//  *
// void print_diamond(const int num)
// {
//     char arr[1000][1000] = {"0"};
//     int i = 0;
//     int j = 0;
//     for(i = 0; i < 2 * num - 1; i++)
//     {
//         for(j = 0; j < 2 * num - 1; j++)
//         {
//             if((i + j >= num - 1) && (abs(j - i) <= num - 1) && (i + j <= 3 * (num - 1)))
//             {
//                 printf("%c", '*');
//             }
//             else
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     print_diamond(num);
//     return 0;
// }

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给n元，可以多少汽水
//count = 2 * n - 1
//20+10+5+2+1+1=39
// int drink_cola(const int n)
// {
//     int bottle = n;
//     int rbottle = 0;//上次除以2的余数
//     int sum = n;
//     while(bottle >= 2)
//     {
//         rbottle = bottle % 2;
//         bottle = bottle / 2;
//         sum += bottle;
//         bottle += rbottle; 
//     }
//     return sum;
// }

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     int count = drink_cola(n);   
//     printf("%d\n", count);
//     return 0;
// }

//倒置字符串
//普通方法，遇到空格，赋值新的数组输出
// void Inversion(char *arr)
// {
//     int len = strlen(arr);
//     int i = 0;
//     char ret[101] = {'0'};
//     int retlen = 0;
//     //int begin = 0;
//     int end = len;
//     for(i = len -1 ; i >= 0; i--)
//     {
//         //遇到空格，把空格位置的i置为begin
//         if(arr[i] == ' ' || i == 0)
//         {
//             //将空格i-end复制给ret，在i=0时，因为前面没有空格，所以需要自己创造空格
//             strncpy(ret + retlen + (i == 0), arr + i, end - i + (i == 0));
//             retlen = retlen + end - i + (i == 0);
//             //其实只有i=0有用的一条
//             *(ret + retlen) = ' ';
//             end = i;
//         }
//     }
//     printf("%s\n", ret + 1);
// }

//先整体逆序，然后每个单词分别逆序
// void Reverse(char *arr, int left, int right)
// {
//     int len = strlen(arr);
//     int i = 0;
//     while(left < right)
//     {
//         char temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;
//         left++;
//         right--;
//     }
// }

// void Inversion(char *arr)
// {
//     int i = 0;
//     int len = strlen(arr);
//     int left = 0;
//     int right = 0;
//     Reverse(arr, 0, len - 1);
//     //检测到空格，把空格前面的逆序
//     for(i = 0; i < len; i++)
//     {
//         if(arr[i] == ' ')
//         {
//             right = i - 1;
//             Reverse(arr, left, right);
//             left = ++i;
//         }
//     }
//     //最后逆序
//     Reverse(arr, left, len - 1);
//     printf("%s\n", arr);

// }

// int main()
// {
//     char arr[101] = {'0'};
//     gets(arr);
//     Inversion(arr);
//     return 0;
// }


