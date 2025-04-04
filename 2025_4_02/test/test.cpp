#include<stdio.h>

// int fun()
// {
//     static int count = 0;
//     return ++count;
// }

// int main()
// {
//     int a = 1;
//     //问题表达式1
//     int b = (++a) + (++a) + (++a);
    
//     a = 2;
//     //问题表达式2
//     int c = a + --a;

//     //问题表达式3
//     int d = fun() + fun() * fun();

//     printf("b = %d\n", b);
//     printf("c = %d\n", c);
//     printf("d = %d\n", d);
//     return 0;
// }

//序列中删除指定数字
//普通方法
// void Delete(int arr[], int len, int delete_num)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     for(i = 0; i < len; i++)
//     {
//         if(arr[i] == delete_num)
//         {
//             //全部左移一位，len--，i也要--
//             for(j = i; j < len; j++)
//             {
//                 arr[j] = arr[j + 1];
//             }
//             len--;
//             i--;
//         }
//     }
//     for(i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

//线性表两个指针
//i代表一次遍历，j表示要输出的下标
//如果不是要找的数字，给arr[j]赋值arr[i],j++
//如果是要找的数字，就不进行赋值和j++，只需要一次遍历
// void Delete(int arr[], int len, int delete_num)
// {
//     int i = 0;
//     int j = 0;
//     for(i = 0; i < len; i++)
//     {
//         if(arr[i] != delete_num)
//         {
//             arr[j] = arr[i];
//             j++;
//         }
//     }
//     for(i = 0; i < j; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int len = 0;
//     int arr[50] = {0};
//     int delete_num = 0;
//     int i = 0;
//     scanf("%d", &len);
//     getchar();
//     for(i = 0; i < len; i++)
//     {
//         scanf("%d", &arr[i]);
//         getchar();
//     }
//     scanf("%d", &delete_num);
//     Delete(arr, len, delete_num);

//     return 0;
// }

//最高分和最低分之差
// void sub_max_min(int arr[], int len)
// {
//     int max = 0;
//     int min = 100;
//     int i = 0;
//     int diff = 0;
//     for(i = 0; i < len; i++)
//     {
//         if(arr[i] < min)
//         {
//             min = arr[i];
//         }
//         if(arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     diff = max - min;
//     printf("%d\n", diff);
// }

// int main()
// {
//     int len = 0;
//     int arr[10000];
//     int i = 0;
//     scanf("%d", &len);
//     getchar();
//     for(i = 0; i < len; i++)
//     {
//         scanf("%d", &arr[i]);
//         getchar();
//     }
//     sub_max_min(arr, len);

//     return 0;
// }


//大小写字母的转换
//scanf读取成功返回读取数据的个数，读取失败返回EOF
//islower(ch)和isupper(ch)判断大小写，是返回1，不是返回0
//isalpha(ch)判断是不是字母
//tolower(ch)和toupper(ch)大小写转换
//头文件是#include<ctype.h>

//%c的前面加空格
//跳过下一个字符之前的所有空白字符
// int main()
// {
//     char ch = '0';
//     while(scanf("%c", &ch) != EOF)
//     {
//         if(ch >= 'a' && ch <= 'z')
//         {
//             printf("%c\n", ch - 32);
//         }
//         else if(ch >= 'A' && ch <= 'Z')
//         {
//             printf("%c\n", ch + 32);
//         }
//         getchar();
//     }

//     return 0;
// }

#include<math.h>

//低于num的水仙花数
// void lily_number(int num)
// {
//     int i = 0;
//     int j = 0;
//     int num1 = 0;
//     int num2 = 0;
//     int div = 0;
//     int sum = 0;
//     for(i = 1; i <= num; i++)
//     {
//         sum = 0;
//         for(j = 1; i > (int)pow(10, j); j++)
//         {
//             //10, 100, 1000
//             div = (int)pow(10, j);
//             //越来越小
//             num1 = i / div;
//             //越来越大
//             num2 = i % div;
//             sum = num1 * num2 + sum;
//         }
//         if(sum == i)
//         {
//             printf("%d ", i);
//         }
//     }
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     lily_number(num);
//     return 0;
// }

