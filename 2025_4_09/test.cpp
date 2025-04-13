#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//判断大小端
// int check_sys()
// {
//     int a = 1;
//     char *p = (char*) &a;
//     if(*p)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
//     //return *p;
// }

// int main()
// {
//     //printf("%zu\n", sizeof(long));
//     if(check_sys())
//     {
//         printf("大端。\n");
//     }
//     else
//     {
//         printf("小端。\n");
//     }

    

//     return 0;
// }

//-1 = 1000 0001
// 1111 1111
//a=-1,b=-1,c=255
//a, b, c 在截断后的内存中的存储都是1111 1111
//但是在打印过程中，由于需要按照%d的形式进行打印，需要整型提升
//a, b整型提升后的结果是FF FF FF FFH = -1
//c整型提升后的结果是00 00 00 FFH = 255
// int main()
// {
//     char a = -1;
//     signed char b = -1;
//     unsigned char c = -1;
//     printf("a=%d,b=%d,c=%d", a, b, c);
//     return 0;
// }

//4294967168
//char类型的a是可以存储-128 = 1000 0000
//在用%u打印，先进行整型提升，-128高位补1 = FFFFFF80H
//无符号数打印结果就是4294967168
// int main()
// {
//     char a = -128;
//     printf("%u\n", a);
//     return 0;
// }

//a = 128 = 1000 0000 = FFFFFF80H
//无符号数打印和上面的结果一样
// int main()
// {
//     char a = -128;
//     printf("%u\n", a);
//     return 0;
// }

//i = -20 = 1001 0100 = 1110 1100 = FFFF FFECH  整型提升
//j = 10 = 0000 1010 = 0000 000AH  整型提升
//i + j = FFFFFFECH + 0000000AH = FFFF FFF6H  整型提升
//原码 = 8000 000AH = -10
// int main()
// {
//     int i=-20;
//     unsigned int j = 10;
//     printf("%d\n",i + j);
//     return 0;
// }

//死循环
//i是无符号整型，永远不会小于0
// int main()
// {
//     unsigned int i;
//     for (i = 9; i >= 0; i--)
//         printf("%u\n", i);
//     return 0;
// }

//unsigned类型的死循环
// int main()
// {
//     unsigned char i = 0;
//     for (i = 0; i <= 255; i++)
//         printf("hello world\n");
//     return 0;
// }


//-1 - i = -1, -2, ..., -128, 127, 126, ..., 1, 0
//255
//strlen(a)读取直到'\0'，也就是0，strlen返回的类型是无符号整型
//char类型只能读出-128~127
// int main()
// {
//     char a[1000];
//     int i;
//     for(i = 0; i <1000; i++)
//     {
//         a[i]=-1- i;
//     }
//     printf("%d\n", strlen(a));
//     return 0;
// }

//9 = 1001.0000 = (-1)^0 * 1.001 * 2^3
//9     = 0,000 0000 0,000 0000 0000 0000 0000 1001（视作整数）
//9.0 = 0,100 0001 0,001 0000 0000 0000 0000 0000（IEEE 754标准下的浮点数）
// int main()
// {
//     int n = 9;
//     float *p1 = (float*)&n;
//     printf("%d\n%f\n", n, *p1);

//     float m = 9.0f;
//     int *p2 = (int *)&m;
    
//     printf("%d\n%f", *p2, m);
//     return 0;
// }



