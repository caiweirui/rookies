#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// int test(int x, int y)
// {
//     return x + y;
// }

// int main()
// {
//     //函数指针
//     int (*pf)(int, int) = &test;
    
//     //函数指针数组
//     int (*pfArr[4])(int, int) = {*pf};

//     printf("%p\n", *pf);
//     printf("%d\n", (***pf)(2, 3));
//     return 0;
// }

// int main()
// {
//     int a[] = { 1,2,3,4 };
//     printf("%d\n", sizeof(a));          //数组的长度，16（只放一个数组名）
//     printf("%d\n", sizeof(a + 0));      //数组首元素的指针，4/8
//     printf("%d\n", sizeof(*a));         //数组首元素，4
//     printf("%d\n", sizeof(a + 1));      //数组第二个元素的指针，4/8
//     printf("%d\n", sizeof(a[1]));       //数组第二个元素，4
//     printf("%d\n", sizeof(&a));         //数组指针，4/8
//     printf("%d\n", sizeof(*&a));        //整个数组，等效a，16
//     printf("%d\n", sizeof(&a + 1));     //数组第二个元素的指针，4/8
//     printf("%d\n", sizeof(&a[0]));      //数组首元素的指针，4/8
//     printf("%d\n", sizeof(&a[0] + 1));  //数组第二个元素的指针，4/8
//     return 0;
// }

// int main()
// {
//     char arr[]= {'a','b','c','d','e','f' };
    // printf("%d\n", sizeof(arr));            //整个数组，6
    // printf("%d\n", sizeof(arr + 0));        //首元素地址，4/8
    // printf("%d\n", sizeof(*arr));           //首元素内容，1
    // printf("%d\n", sizeof(arr[1]));         //第二个元素内容，1
    // printf("%d\n", sizeof(&arr));           //数组地址，4/8
    // printf("%d\n", sizeof(&arr + 1));       //下一个数组的地址，4/8
    // printf("%d\n", sizeof(&arr[0] + 1));    //第二个元素的地址，4/8

    // printf("%d\n", strlen(arr));            //没有'\0'，>=真实长度的随机值
    // printf("%d\n", strlen(arr + 0));        //没有'\0'，>=真实长度的随机值
    // printf("%d\n", strlen(*arr));           //首元素，报错，不报错就是一个数组首元素的值作为地址（野指针）
    // printf("%d\n", strlen(arr[1]));         //第二个元素，报错，不报错就是一个数组第二个元素的值作为地址（野指针）
    // printf("%d\n", strlen(&arr));           //数组指针，报错，不报错就是>=真实长度的随机值
    // printf("%d\n", strlen(&arr + 1));       //数组指针，报错不报错真的随机值
    // printf("%d\n", strlen(&arr[0] + 1));    //第二个元素的地址，>=真实长度-1的随机值
    // return 0;
// }

// int main()
// {
//     char arr[] = "abcdef";
//     //a b c d e f '\0'

//     printf("%d\n", sizeof(arr));            //数组长度+'\0'，7
//     printf("%d\n", sizeof(arr + 0));        //首元素的指针，4/8
//     printf("%d\n", sizeof(*arr));           //首元素，1
//     printf("%d\n", sizeof(arr[1]));         //第二个元素，1
//     printf("%d\n", sizeof(&arr));           //数组指针，4/8
//     printf("%d\n", sizeof(&arr + 1));       //下一个数组的指针，4/8
//     printf("%d\n", sizeof(&arr[0] + 1));    //第二个元素的地址，4/8

//     return 0;
// }


// int main()
// {
//     //等价char *p = &a;
//     char* p = "abcdef";
//     printf("%d\n", sizeof(p));          //首元素指针，4/8
//     printf("%d\n", sizeof(p + 1));      //第二个元素指针，4/8
//     printf("%d\n", sizeof(*p));         //首元素，1
//     printf("%d\n", sizeof(p[0]));       //首元素，1
//     printf("%d\n", sizeof(&p));         //首元素指针的二级指针，4/8
//     printf("%d\n", sizeof(&p + 1));     //首元素指针的二级指针+1，野指针，4/8
//     printf("%d\n", sizeof(&p[0] + 1));  //首元素指针的二级指针+1，野指针，4/8
    
//     printf("%d\n",strlen(p));           //首元素指针，6
//     printf("%d\n", strlen(p + 1));      //第二个元素指针，5
//     printf("%d\n", strlen(*p));         //首元素，报错，不报错是首元素的值作为地址，随机值（野指针）
//     printf("%d\n", strlen(p[0]));       //首元素，报错，不报错是首元素的值作为地址，随机值（野指针）
//     printf("%d\n", strlen(&p));         //首元素地址的二级指针，报错，不报错是随机值（野指针）
//     printf("%d\n", strlen(&p + 1));     //首元素地址的二级指针+1，报错，不报错是随机值（野指针）
//     printf("%d\n", strlen(&p[0] + 1));  //第二个元素指针，5
//     return 0;
// }

// int main()
// {
//     int a[3][4] = { 0 };
//     printf("%d\n", sizeof(a));              //整个二维数组，48
//     printf("%d\n", sizeof(a[0][0]));        //a[0][0]，整型，4
//     printf("%d\n", sizeof(a[0]));           //数组的第一行数组名，16
//     printf("%d\n", sizeof(a[0] + 1));       //a[0][1]的指针，4/8
//     printf("%d\n", sizeof(*(a[0] + 1)));    //a[0][1]，整型，4
//     printf("%d\n", sizeof(a + 1));          //数组的第二行的指针，4/8
//     printf("%d\n", sizeof(*(a + 1)));       //数组的第二行，16
//     printf("%d\n", sizeof(&a[0] + 1));      //数组第二行的指针，4/8
//     printf("%d\n", sizeof(*(&a[0] + 1)));   //数组的第二行，16
//     printf("%d\n", sizeof(*a));             //数组的第一行，16
//     printf("%d\n", sizeof(a[3]));           //越界，但是数组第4行，16
//     return 0;
// }

//2, 5
// int main()
// {
//     int a[5] = { 1, 2, 3, 4, 5 };
//     //下一个数组的指针，转换成int*
//     int *ptr = (int *)(&a + 1);

//     printf("%d,%d", *(a + 1), *(ptr - 1));
//     return 0;
// }

//假设p的地址是0x0012ff40
//0x0012ff54 -> 跳过一个结构体大小
//0x0012ff41 -> +1操作
//0x0012ff44 -> 跳过一个整型
//边界对齐的排列
//int   -       -       - 
//char* -       -       -
//short -       char    -
//short   -
//结构体指针p
// struct Test
// {
//     int Num;
//     char* pcName;
//     short sDate;
//     char cha[2];
//     short sBa[4];
// }*p = (struct Test*)0x0012ff40;

// int main()
// {
//     printf("%p\n", p);
//     printf("%p\n", p + 0x1);
//     //printf("%d\n", (unsigned long)p + 0x1);
//     printf("%p\n", (unsigned int*)p + 0x1);
//     return 0;
// }

//4H, 2 00 00 00H
// int main()
// {
//     int a[4] = { 1, 2, 3, 4 };
//     int *ptr1 = (int *)(&a + 1);
//     //这一坨相当于指针向后移动了一个字节
//     //配合小端存储
//     //00 00 00 02
//     //转化之后就是
//     //02 00 00 00H
//     int *ptr2 = (int *)((int)a + 1);
//     printf( "%x, %x", ptr1[-1], *ptr2);
//     return 0;
// }

//p[0] = a[0][0] = 1
// int main()
// {
//     //弱智逗号表达式数组
//     //1, 3
//     //5, 0
//     //0, 0
//     int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//     int* p;
//     //p是第一行的地址的首地址，相当于&a[0][0]
//     p = a[0];
//     printf("%d\n", p[0]);
//     return 0;
// }

//abcde fghij klmno pqrst uv,w,xy...
//abcd efgh ijkl mnop qr,s,t uv,w,x y...
//FFFFFFFFFFFFFFFC, -4
//%p无符号十六进制数
//地址相减得到元素个数
// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = (int(*)[4])a;
//     printf("%p, %d\n", &p[4][2]- &a[4][2], &p[4][2]- &a[4][2]);
//     return 0;
// }

//1, 2, 3, 4, 5
//6, 7, 8, 9, 10
//10, 5
// int main()
// {
//     int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//     int* ptr1 = (int*)(&aa + 1);
//     int* ptr2 = (int*)(*(aa + 1));
//     printf("%d, %d",*(ptr1- 1), *(ptr2 - 1));
//     return 0;
// }

// at
// int main()
// {
//     //指针数组
//     char* a[] = {"work","at","alibaba" };

//     //指针数组的数组指针，a是首元素地址
//     char** pa = a;

//     pa++;

//     printf("%s\n", *pa);
//     return 0;
// }


// int main()
// {
//     //指针数组
//     char* c[] = {"ENTER","NEW","POINT","FIRST" };
//     //二级指针数组
//     char** cp[] = { c + 3,c + 2,c + 1,c };
//     //二级指针数组的数组指针
//     char*** cpp = cp;
    
//     printf("%s\n", **++cpp);            //POINT
//     printf("%s\n", *-- * ++cpp + 3);    //ER
//     printf("%s\n",*cpp[-2] + 3);        //ST
//     printf("%s\n", cpp[-1][-1] + 1);    //EW
//     return 0;
// }