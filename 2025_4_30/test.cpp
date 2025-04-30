#include<bits/stdc++.h>

// // 仅仅创造类型，不需要初始化
// struct Stu
// {
//     //member-list
//     char name[20];
//     int age;
// }s1, s2;//variable-list，是全局变量

// // 匿名结构体
// struct
// {
//     char id[10];
// }s4, s5;

// struct
// {
//     char id[10];
// }arr[10], *p;       // 结构体数组和结构体指针
// // p和&x会被认为是两个不同的数据类型，即使结构体的内容一样

// // 结构体表示链表和重命名
// typedef struct Node
// {
//     int data;
//     struct Node *next;
// }Node;

// //定义结构体指针
// Node *listlink = NULL;

// // 初始化
// struct Stu2
// {
//     double name;
//     char c;
//     int age;
//     // char ch;
// }s6;  

// struct S1
// {
//     char c1;
//     struct Stu2 s7;
//     double xy;
// };

// #pragma pack(1)
// struct S2
// {
//     char x;
//     int i;
//     char x2;
// };
// #pragma pack()

// struct S
// {
//     int data[100];
//     int num;
// };

// // 传值调用
// void print1(struct S s)
// {
//     int i = 0;
//     for(i = 0; i < 3; i++)
//     {
//         printf("%d ", s.data[i]);
//     }
//     printf("%d\n", s.num);
// }

// // 传址调用
// void print2(struct S *ps)
// {
//     int i = 0;
//     for(i = 0; i < 3; i++)
//     {
//         printf("%d ", ps->data[i]);
//     }
//     printf("%d\n", ps->num);
// }

// 位段
// struct A
// {
//     int _a:2;
//     int _b:5;
//     int _c:10;
//     int _d:30;
// };


// int main()
// {
//     // printf("%d\n", offsetof(struct Stu2, name));    // 0
//     // printf("%d\n", offsetof(struct Stu2, c));       // 1
//     // printf("%d\n", offsetof(struct Stu2, age));     // 4

//     printf("%d\n", sizeof(struct A));

//     // struct S s = {{1,2,3}, 10};

//     // // print1(s);

//     // print2(&s);


//     return 0;
// }

struct S
{
    char a: 3;
    char b: 4;
    char c : 5;
    char d : 4;
};

int main()
{
    struct S s = { 0 };
    s.a= 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;
    printf("%d\n", sizeof(struct S));
    
    return 0;
}