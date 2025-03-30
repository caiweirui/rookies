#include<stdio.h>

//形参x和y的改变不会影响实参a和b
// void swap(int a, int b)
// {
//     int temp = 0;
//     temp = a;
//     a = b;
//     b = temp;
// }

// int main()
// {
//     int a = 0, b = 0;
//     scanf("%d %d", &a, &b);
//     printf("交换前：a=%d b=%d\n", a, b);
//     swap(a, b);
//     printf("交换后：a=%d b=%d\n", a, b);
//     return 0;
// }

//能通过函数的形参改变实参的方法
//1.使用指针
//2.使用数组
//3.使用结构体
//4.使用全局变量
//5.使用引用
//6.使用函数返回值
//7.使用位运算
//8.使用函数参数传递

//使用指针
// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
// int main()
// {
//     int a = 0, b = 0;
//     scanf("%d %d", &a, &b);
//     printf("交换前：a=%d b=%d\n", a, b);
//     swap(&a, &b);
//     printf("交换后：a=%d b=%d\n", a, b);
//     return 0;
// }


#include <math.h>
//判断是否是素数（传值函数）
// int isPrime(int num)
// {
//     int i = 0, count = 0;
//     if (num > 1)
//     {
//         //判断num是否是素数，当num能被2~sqrt(num)之间的数整除时，num不是素数
//         for (i = 2; i <= sqrt(num); i++)
//         {
//             if (num % i == 0)
//             {
//                 //如果是素数，count==0，否则count>0，跳出循环
//                 count++;
//                 //break;
//                 //比break更高效
//                 return 1;
//             }                  
//         }        
//     }
//     return count;
// }

// int main()
// {
//     int num = 0, i = 0, count = 0;
//     scanf("%d", &num);
//     count = isPrime(num);
//     //当输入的数不是大于二的整数或素数时，输出“不是素数”
//     if (num<=1 || count>0)
//     {
//         printf("不是素数\n");
//     }
//     else
//     {
//         printf("是素数\n");
//     }
//     return 0;
// }


// //判断是否是闰年，如果是闰年返回1，否则返回0（传值函数）
// int if_leap_year(int year)
// {
//     //闰年：能被4整除但不能被100整除，或者能被400整除
//     //能被400整除的情况
//     if(year % 400 == 0)
//     {
//         return 1;
//     }
//     //能被4整除但不能被100整除的情况
//     //下面这个else if的条件不能被上面的条件包括，否则永远不会执行
//     else if(year % 4==0 && year % 100 != 0)
//     {
//         return 1;
//     }
//     //其他情况
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     int year = 0;
//     scanf("%d", &year);
//     if (if_leap_year(year))
//     {
//         printf("%d是闰年\n", year);
//     }
//     else
//     {
//         printf("%d不是闰年\n", year);
//     }
//     return 0;
// }

//二分查找函数版本
//arr[]形式上是数组，实际上传的是指针
// int binary_search(int arr[], int need_to_find, int len)
//{
//     int begin = 0, end = len - 1, mid = 0;
//     while(begin <= end)
//     {
//         mid = (begin + end) / 2;
//         // printf("mid=%d\n", mid);
//         // printf("arr[mid]=%d\n", arr[mid]);
//         if(need_to_find < arr[mid])
//         {
//             //如果need小于中间值，则end = 中间值
//             end = mid - 1;
//             //printf("大了\n");
//         }
//         else if(need_to_find > arr[mid])
//         {
//             //如果need大于中间值，则begin = 中间值
//             begin = mid + 1;
//             //printf("小了\n");
//         }
//         else
//         {
//             //printf("%d\n", mid);
//             return mid;
//         }
//     }
//     //printf("%d %d %d\n", begin, mid, end);
//     if(begin > end)
//     {
//         //printf("no found.");
//         return -1;
//     }
// }

// int main()
// {
//     int arr[100] = {0};
//     int len = 0;
//     int need_to_find = 0;
//     int i = 0;
//     scanf("%d", &need_to_find);
//     while(getchar() != '\n')
//     {
//         scanf("%d", &arr[i++]);
//         len++;
//     }
//     // for (i = 0; i < len; i++)
//     // {
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("len=%d\n", len);

//     if (binary_search(arr, need_to_find, len) == -1)
//     {
//         printf("no found.");
//     }
//     else
//         printf("%d\n", binary_search(arr, need_to_find, len));
//     return 0;
// }

