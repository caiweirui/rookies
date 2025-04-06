#include<stdio.h>
#include<string.h>

//一个数的二进制数中有多少个1
//用十进制转化成二进制的方法
//参数必须转换成无符号数
// int count_of_1(unsigned int num)
// {
//     int i = 0;
//     int count = 0; 
//     while(num >= 1)
//     {
//         if(num % 2 == 1)
//         {
//             count++;
//         }
//         num /= 2;
//     }
//     return  count;
// }


// //n = n & (n - 1)效果，去除n最右边的一个1
// int count_of_1(unsigned int num)
// {
//     int count = 0;
//     while(num != 0)
//     {
//         num = num & (num - 1); 
//         count++;
//     }
//     return count;
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     int count = count_of_1(num);
//     printf("%d\n", count);
//     return 0;
// }

//求两个不同数之间不同的二进制的个数
//1101
//1011
//&1001
//|1111

// int count_of_1(unsigned int num)
// {
//     int count = 0;
//     // while(num != 0)
//     // {
//     //     num = num & (num - 1); 
//     //     count++;
//     // }
//     //获取一个数二进制的每一位
//     int i = 0;
//     for(i = 0; i < 32; i++)
//     {
//         count += (num >> i) & 1;
//     }
//     return count;
// }

// int main()
// {
//     int num1 = 0;
//     int num2 = 0;
//     scanf("%d %d", &num1, &num2);
//     //按位或的1的个数减去按位与的1的个数
//     // int count1 = count_of_1(num1 & num2);
//     // int count2 = count_of_1(num1 | num2); 
//     // printf("%d\n", count2 - count1);

//     //按位异或的1的个数
//     int count3 = count_of_1(num1 ^ num2);
//     printf("%d\n", count3);

//     return 0;
// }

//打印图形，想象成矩形
// void printX(int num)
// {
//     int i = 0;
//     int j = 0;
//     for(i = 0; i < num; i++)
//     {
//         for(j = 0; j < num; j++)
//         {
//             //满足条件输出题目要求的图形
//             if(i == j || (i + j == num - 1))
//             {
//                 printf("*");
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
//     printX(num);
//     return 0;
// }

// //获取月份天数
// int is_leap_year(int year)
// {
//     return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
// }

// int main()
// {
//     int year = 0;
//     int month = 0;
//     int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30};
//     scanf("%d %d", &year, &month);
//     if(month == 2)
//     {
//         printf("%d\n", arr[month - 1] + is_leap_year(year));
//     }
//     else
//     {
//         printf("%d\n", arr[month - 1]);
//     }
//     return 0;
// }

// //死循环
// int main()
// {
//     int i=0;
//     int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//     //1/0~9
//     for (i = 0; i <= 12; i++)
//     {
//         arr[i]=0;//已用时间<=1ms
//         printf("hehe\n");
//     }
//     return 0;
    
// }


