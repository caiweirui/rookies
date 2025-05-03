#include<bits/stdc++.h>

// // 枚举的定义
// enum Day
// {
//     Mon = 1,   
//     Tues,
//     Wed,
//     Thur,
//     Fri,
//     Sat,
//     Sun
// };

// int main()
// {
//     enum Day d = Fri;
//     printf("%d\n", Mon);    // 默认从0开始，按照定义从规定的开始


//     return 0;
// }

// 联合，所有类型共用一个存储空间
// union Un
// {
//     int a;
//     char c;
// };

// // int main()
// // {
// //     union Un u;
// //     printf("%d\n", sizeof(u));  // 大小为4

// //     // 00000000005ffe5c
// //     // 00000000005ffe5c
// //     // 00000000005ffe5c
// //     printf("%p\n", &u);
// //     printf("%p\n", &(u.a));
// //     printf("%p\n", &(u.c));
// //     return 0;
// // }

// // // 判断大小端
// // int check_sys()
// // {
// //     // 指针法
// //     // int a = 1;
// //     // return *(char*)&a;      // 返回1就是小端，返回2就是大端

// //     // 联合法
// //     union Un u;
// //     u.a = 1;
// //     return u.c;
// // }

// // int main()
// // {
// //     int ret = check_sys();
// //     if(ret == 1)
// //     {
// //         printf("小端\n");
// //     }
// //     else
// //     {
// //         printf("大端\n");
// //     }
// //     return 0;
// // }

// union U2
// {
//     short arr[7];
//     int i;
// };

// int main()
// {
//     printf("%d\n", sizeof(union U2));   // 大小为16
//     return 0;
// }

// int main()
// {
//     int *p1 = (int *)malloc(40);
//     int *p2 = (int *)calloc(10, sizeof(int));

//     // 修改大小为80字节
//     int *p3 = (int *)realloc(p1, 80);
//     if(p3 != NULL)
//     {
//         p1 = p3;
//     }


//     // 有效性判断
//     if(p2 == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 1;       // 异常返回
//     }
//     else
//     {
//         int i = 0;
//         // for(i = 0; i < 10; i++)
//         // {
//         //     p[i] = i;
//         // }
//         for(i = 0; i < 10; i++)
//         {
//             printf("%d ", p2[i]);
//         }
//         printf("\n");

//         free(p2);
//         p2 = NULL;
//     }
//     return 0;
// }

void GetMemory(char** p)
{
    int n = 100;
    *p = (char*)malloc(n);
}
void Test(void)
{
    char* str = NULL;
    GetMemory(&str);     // 需要用二级指针传址调用
    // str == NULL，解引用时会崩溃
    // p被销毁，存在内存泄漏
    strcpy(str, "hello world");
    printf(str);
    free(str);
    str = nullptr;
}

int main()
{
    Test();
    return 0;
}
