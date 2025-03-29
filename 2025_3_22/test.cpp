#include<stdio.h>
#include<math.h>
#include<string.h>

//输出年月日
// int main()
// {
//     char ch[100];
//     gets(ch);
//     int len = strlen(ch);
//     int i;
//     printf("year=");
//     for (i = 0; i < 4; i++)
//     {
//         printf("%c", ch[i]);
//     }
//     printf("\nmonth=");
//     for (i = 4; i < 6; i++)
//     {
//         printf("%c", ch[i]);
//     }
//     printf("\ndate=");
//     for (i = 6; i < 8; i++)
//     {
//         printf("%c", ch[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int year = 0, month = 0, day = 0;
//     scanf("%4d%2d%2d", &year, &month, &day);
//     //%md在输入时代表取多少位的十进制整数
//     //%md在输出时代表输出多少位十进制整数，前面加0表示用0补齐，没有加0表示用空格补齐
//     printf("year=%d\nmonth=%02d\ndate=%02d\n",year, month, day);
//     return 0;
// }

//输出学号和成绩
// int main()
// {
//     int number = 0;
//     int flag = ',';
//     float score[100] = {0};
//     //输入学号
//     scanf("%d", &number);
//     int i = 0;
//     //输入学号后面的分号
//     getchar();
//     //输入浮点数成绩，成绩之间用","隔开，最后一个成绩后面是换行符
//     while(','==flag)
//     {
//         scanf("%f", &score[i++]);
//         flag=getchar();
//     }
//     //打印学号和成绩
//     printf("The each subject score of NO. %d is: ", number);
//     //i要重新赋值为0，用while是这样的
//     i = 0;
//     while(score[i]!=0)
//     {
//         printf("%.2f", score[i]);
//         if(score[i+1]!=0)
//         printf(", ");
//         i++;
//     }
//     printf(".\n");
//     return 0;

// }

// int main()
// {
//     //printf函数返回的是打印的字符个数
//     int n = printf("hello world!");
//     printf("\n%d\n", n);
//     return 0;
// }


//'\'表示转义字符
// int main()
// {
//     printf("printf(\"hello world!\\n\");\n");
//     printf("cout << \"hello world!\" << endl;\n");
    
//     return 0;
// }

//输出一串用空格隔开的数字的最大值
// int main()
// {
//     int a[100] = {0};
//     int max = 0;
//     int i = 0;
//     int flag = 0;
//     while(1)
//     {
//         scanf("%d", &a[i]);
//         if(a[i] > max)
//         {
//             max = a[i];
//         }
//         i++;
//         flag = getchar();
//         //如果flag是换行符，则退出输入
//         if(flag == '\n')
//         {
//             break;
//         }
//     }
//     printf("%d\n", max);
//     return 0;
// }

//阶乘
// int factorial(int n)
// {
//     if(n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return n * factorial(n - 1);
//     }
// }

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     printf("%d\n", factorial(n));
//     int i = 0, sum = 0;
//     for (i = 0; i < 10; i++)
//     {
//         sum+=factorial(i+1);
//     }
//     printf("%d\n", sum);
//     return 0;
// }

//用二分查找在数组中查找一个数
// int main()
// {
//     int arr[100] = {0};
//     int need = 0;
//     scanf("%d", &need);
//     int i = 0, j = 0;
//     int begin = 0, end = 0;
//     while(getchar() != '\n')
//     {
//         scanf("%d", &arr[i++]);
//         end++;
//     }
//     //printf("%d\n", end);
//     //转换成有序数列
//     for (i = 0; i < end; i++)
//     {
//         for (j = 0; j < end; j++)
//         {
//             if(arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     //二分查找
//     while(need != arr[(begin + end) / 2] && (end - begin) > 1)
//     {
//         if(need < arr[(begin + end) / 2])
//         {
//             //如果need小于中间值，则end = 中间值
//             end = (begin + end) / 2;
//         }
//         else
//         {
//             //如果need大于中间值，则begin = 中间值
//             begin = (begin + end) / 2;
//         }
//     }
//     //printf("%d %d\n", begin, end);
//     //输出在数组中的位置
//     if(need == arr[(begin + end) / 2])
//     {
//         printf("%d\n", (begin + end) / 2);
//     }
//     else
//     {
//         printf("not found\n");
//     }
//     return 0;
// }

//编写代码，演示多个字符从两端移动，向中间汇聚
// #include <windows.h>
// int main()
// {
//     char str[100] = {0}, str2[100] = {0};
//     int i = 0, j = 0;
//     while(1)
//     {
//         str[i++]=getchar();
//         if(str[i-1] == '\n')
//         {
//             break;
//         }
//     }
//     int len = strlen(str)-1;
//     printf("%d\n", len);
//     for (i = 0; i < len; i++)
//     {
//         str2[i] = '#';
//     }
//     //当长度为偶数时
//     if (len % 2 == 0)
//     {
//         for (i = 0; i < len; i++)
//         {
//             str2[i] = str[i];
//             str2[len-i-1] = str[len-i-1];
//             for(j = 0; j < len; j++)
//             {
//                 printf("%c", str2[j]);
//             }
//             Sleep(1000);//程序暂停1秒
//             printf("\r\n");
//         }
//     }
//     //当长度为奇数时
//     else
//     {
//         for (i = 0; i < (len + 1) / 2; i++)
//         {
//             str2[i] = str[i];
//             str2[len-i-1] = str[len-i-1];
//             for(j = 0; j < len; j++)
//             {
//                 printf("%c", str2[j]);
//             }
//             Sleep(1000);
//             printf("\r\n");
//         }
    
//     }
//     printf("%s\n", str); // 替代逐字符的 for 循环
//     return 0;
// }

//编写代码实现，模拟用户登录情景，并且只能登录三次。
// //（只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。
// int main()
// {
//     char password[] = {"123456"};
//     char input[20] = {0};
//     int i = 0;
//     //三次输入机会
//     while(i < 3)
//     {
//         gets(input);
//         //strcmp函数比较两个字符串是否相等，相等返回0，不相等返回1
//         if(strcmp(input, password) == 0)
//         {
//             printf("登录成功\n");
//             break;
//         }
//         else
//         {
//             printf("密码错误，请重新输入\n");
//             i++;
//         }
//     }
//     //三次输入错误，退出程序
//     if(i == 3)
//     {
//         printf("密码连续错误三次，退出程序\n");
//     }
//     return 0;
// }


//小游戏：猜数字，如果猜测大了，返回“猜大了”，如果猜测小了，返回“猜小了”;
//如果猜对了，返回“恭喜你猜对了”。
// #include <cstdlib>
// #include <time.h>
// #include <stdlib.h>
// int main()
// {
//     int guess = 0;
//     int flag = 1;//是否需要再玩一次
//     char input[20] = {0};
//     char repeat[20] = {0};
//     printf("猜数字游戏开始(yes/no):\n");
//     //是否参与游戏，最多输入三次
//     for(int i = 0; i < 3; i++)
//     {
//         gets(input);
//         if(strcmp(input,"yes")==0)
//         {
//             break;
//         }
//         else if(strcmp(input,"no")==0)
//         {
//             printf("退出游戏\n");
//             return 0;
//         }
//         else
//         {
//             printf("输入错误，请重新输入:\n");
//         }
//     }
//     while(flag)
//     {
//         if(strcmp(input,"yes")==0)
//         {
//             //用srand函数设置随机数种子，用rand函数生成随机数
//             //使用时间戳作为随机数种子，每次运行程序，随机数种子不同，生成的随机数也不同
//             srand((unsigned int)time(NULL));
//             //printf("%zu\n", time(NULL));
//             int x = rand() % 100+1;//rand()生成0~rand_max(32767)之间的不是很随机的随机数
//             //printf("%d\n",x);
//             printf("请输入你猜的数字:\n");
//             //无限循环，直到猜对为止
//             while(1)
//             {
//                 scanf("%d", &guess);
//                 if(guess > x)
//                 {
//                     printf("猜大了。\n");
//                 }
//                 else if(guess < x)
//                 {
//                     printf("猜小了。\n");
//                 }
//                 else
//                 {
//                     printf("恭喜你猜对了!\n");
//                     break;
//                 }
//             }
//         }
//         //是否再玩一次，最多输入三次
//         printf("是否再玩一次(yes/no):\n");
//         for(int j = 0; j < 3; j++)
//         {
//             //清空缓冲区
//             while(getchar()!= '\n');
//             gets(repeat);
//             if(strcmp(repeat,"yes")==0)
//             {
//                 flag = 1;
//                 break;
//             }
//             else if(strcmp(repeat,"no")==0)
//             {
//                 printf("退出游戏\n");
//                 flag = 0;
//                 break;
//             }
//             else
//             {
//                 printf("输入错误，请重新输入:\n");
//             }
//             if(j == 2)
//             {
//                 printf("输入错误三次，退出游戏\n");
//                 flag = 0;
//             }
//         }
//     }
//     return 0;
// }

//关机程序，输入yes，电脑在60s后关机，输入no，取消关机
//#include <windows.h>
// #include <stdlib.h>
// #include <unistd.h>

// 60秒倒计时
// void countdown()
// {
//     for(int i = 60; i > 0; i--)
//     {
//         printf("%02d秒\n", i);
//         Sleep(1000);
//     }
//     fflush(stdout);
//     sleep(1000);
//     printf("时间到\n");
// }

// int main()
// {
//     char input[100];
//     system("shutdown -s -t 60");//关机命令
//     again:
//     printf("电脑在60s关机，输入yes继续，no取消:\n");
//     //countdown();
//     for(int i = 0; i < 3; i++)
//     {
//         gets(input);
//         if(strcmp(input,"yes")==0)
//         {
//             printf("电脑将在5秒后关机\n");
//             Sleep(5000);
//             system("shutdown -s -t 5");
//             break;
//         }
//         else if(strcmp(input,"no")==0)
//         {
//             printf("取消关机\n");
//             system("shutdown -a");//取消关机命令
//             break;
//         }
//         else
//         {
//             printf("输入错误，请重新输入：\n");
//         }
//         if(i == 2)
//         {
//             printf("输入错误三次，再次提示");
//             goto again;
//         }
//     }
//     return 0;
// }



 