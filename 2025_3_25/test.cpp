#include<stdio.h>

// //递归打印一个整数的每一位
// void depart(int n)
// {
//     //会先进行递归，再进行打印
//     if(n>9)
//     {
//         //这里加return会直接结束递归
//         depart(n/10);
//     }
//     printf("%d ", n%10);
// }

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     depart(n);
//     return 0;   
// }

//递归求字符串长度，模拟strlen，strlen的机制是遍历字符串，每次+1，直到遇到'\0'
// int Strlen(char* str)
// {
//     if(*str == '\0')
//     {
//         return 0;
//     }
//     else
//     {
//         //不要改变str的值，所以用str+1，不能用++str，str++没用
//         return 1 + Strlen(str+1);
//     }
// }

// int main()
// {
//     char arr[100] = {0};
//     scanf("%s", arr);
//     printf("%d\n", Strlen(arr));
//     return 0;
// }

//不用递归求斐波那契数列
// int fib(int n)
// {
//     int num1 = 1, num2 = 1, num3 = 0;
//     if(n == 1 || n == 2)
//     {
//         return 1;
//     }
//     //1 1 2 3 5 8 13 21 34 55
//     for(int i = 2; i < n; i++)
//     {
//         //令num3存储num1+num2的值，然后num1=num2，num2=num3
//         num3 = num1 + num2;
//         num1 = num2;
//         num2 = num3;
//     }
//     return num3;
// }

// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     printf("%d\n",fib(num));
//     return 0;
// }

//死循环输出5
// int main()
// {
//     int i = 0;
//     for(i = 0; i < 10; i++)
//     {
//         if (i = 5)//这里应该用==，而不是=
//         {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }


// int main()
// {
//     for(int i = 1; i <= 100; i++)
//     {
//         if(i % 3 == 0)
//         {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }

// //求两个数的最大公约数和最小公倍数
// int Least_common_divisor(int num1, int num2)
// {
//     int ret = 1;
//     while(ret)
//     {
//         //辗转相除法，用num1%num2的余数替换num1，用num2替换num2，直到num1%num2为0
//         ret = num1 % num2;
//         num1 = num2;
//         num2 = ret;
//     }
//     return num1;
// }
// int main()
// {
//     int num1 = 0, num2 = 0;
//     int ret = 1;
//     scanf("%d %d", &num1, &num2);
//     int LeastCommonDivisor = Least_common_divisor(num1, num2);
//     int MaxCommonMultiple = num1 * num2 / LeastCommonDivisor;
//     printf("%d %d\n", LeastCommonDivisor, MaxCommonMultiple);
//     return 0;
// }

//输出小于num的数中9的个数
// int nine_count(int n)
// { 
//     if(n < 9)
//     {
//         return 0;
//     }
//     else if(n == 9)
//     {
//         return 1;
//     }
//     else
//     {
//         //判断最低位是否为9，如果是，则+1，不是则+0，然后判断前一位，以此类推
//         return nine_count(n / 10) + (n % 10 == 9);
//     }
// }

// int main()
// {
//     int num = 0 ,count = 0;
//     scanf("%d", &num);
//     for(int i = 1; i <= num; i++)
//     {
//         count += nine_count(i);
//     }
//     printf("%d\n", count);
//     return 0;
// }

#include<math.h>
// //计算两个分数的和，用double返回
// double fraction_add(int n1, int m1, int n2, int m2)
// {
//     return (double)(n1 * m2 + n2 * m1) / (m1 * m2);
// }

// int main()
// {
//     int i = 0;
//     double sum = 0.0;
//     for(i = 1; i <= 100; i+=2)
//     {
//         //计算1/1-1/2+1/3-1/4+...+1/99-1/100
//         //sum必须是double类型，否则结果为1
//         sum += fraction_add(1, i, -1, i + 1);
//     }
//     printf("%lf\n", sum);
//     return 0;
// }

//打印九九乘法表
// void print_multiplication_table()
// {
//     int i = 0, j = 0;
//     //打印9行
//     for(i = 1; i <= 9; i++)
//     {
//         //打印9列，j不能大于i
//         for(j = 1; j <= i; j++)
//         {
//             //输出2d，两位右对齐，输出-2d，两位左对齐
//             printf("%d×%d=%2d ", j, i, i * j);
//             //printf("%d×%d=%-2d ", i, j, i * j);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     print_multiplication_table();
//     return 0;
// }




