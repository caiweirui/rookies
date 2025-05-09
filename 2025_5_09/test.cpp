#include<bits/stdc++.h>

// // acc
// // char* GetMemory(void)
// // {
// //     static char p[] = "hello world";
// //     return p;
// // }

// // acc
// char* GetMemory(void)
// {
//     char *p = "hello world";
//     return p;
// }

// // err
// // char* GetMemory(void)
// // {
// //     char p[] = "hello world";
// //     return p;
// // }

// void Test(void)
// {
//     char* str = NULL;
//     str = GetMemory();      // str是野指针
//     printf(str);
// }

// int main()
// {
//     Test();
//     return 0;
// }

// void GetMemory(char** p, int num)
// {
//     *p = (char*)malloc(num);
// }

// void Test(void)
// {
//     char* str = NULL;
//     GetMemory(&str, 100);
//     strcpy(str, "hello");
//     printf(str);
//     free(str);
//     str = NULL;
// }

// int main()
// {
//     Test();
//     return 0;
// }

// void Test(void)
// {
//     char* str = (char*)malloc(100);
//     strcpy(str, "hello");
//     free(str);      // 野指针
//     if (str != NULL)
//     {
//         strcpy(str, "world");
//         printf(str);
//     }
// }

// int main()
// {
//     Test();
//     return 0;
// }

// typedef struct st_type1
// {
//     int i;
//     int a[0];       // 柔性数组成员
// }type_a1;

// typedef struct st_type2
// {
//     int i;
//     int a[];        // 柔性数组成员
// }type_a2;

// int main()
// {
//     // printf("%d\n", sizeof(type_a1));    // 大小为4

//     // 柔性数组的使用
//     // type_a1 *p = (type_a1*)malloc(sizeof(type_a1) + 40);
//     type_a1 *p = (type_a1*)malloc(sizeof(type_a1) + 40);

//     // 柔性数组大小的改变
//     type_a1* temp = (type_a1*)realloc(p, sizeof(type_a1) + 40);
//     if(temp != NULL)
//     {
//         p = temp;
//         temp = NULL;
//     }

//     p->i = 10;
//     int i = 0;
//     for(i = 0; i < p->i; i++)
//     {
//         p->a[i] = i;
//     }
//     printf("%d\n", p->i);
//     for(i = 0; i < p->i; i++)
//     {
//         printf("%d ", p->a[i]);
//     }
//     printf("\n");

//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", "w");
//     if(pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 1;
//     }

//     // 操作文件
//     int i = 0;
//     for(i = 'a'; i <= 'z'; i++)
//         fputc(i, pf);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "r");
//     if(pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 1;
//     }

//     // 操作文件
//     int i = 0;
//     char ch = '0';
//     while((ch = fgetc(pf)) != EOF)
//         printf("%c ", ch);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "w");
//     if(pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 1;
//     }

//     // 操作文件
//     fputs("hello world\n", pf);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "r");
//     if(pf == NULL)
//     {
//         // printf("%s\n", strerror(errno));
//         perror(NULL);
//         return 1;
//     }

//     // 操作文件
//     char arr[20] = {0};
//     fgets(arr, 20, pf);      // 5包括一个'\0'
//     printf(arr);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

typedef struct Stu
{
    char arr[20];
    int age;
    float score;
}Stu;

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "w");
//     if(pf == NULL)
//     {
//         // printf("%s\n", strerror(errno));
//         perror(NULL);
//         return 1;
//     }

//     // 操作文件
//     Stu stu = {"zhangsan", 18, 90.5f};
//     fprintf(pf, "%s %d %.2f\n", stu.arr, stu.age, stu.score);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "r");
//     if(pf == NULL)
//     {
//         // printf("%s\n", strerror(errno));
//         perror(NULL);
//         return 1;
//     }

//     // 操作文件
//     Stu stu;
//     memset(&stu, 0, sizeof(Stu));
//     fscanf(pf, "%s %d %f", stu.arr, &stu.age, &stu.score);
//     // printf("%s %d %.2f\n", stu.arr, stu.age, stu.score);
//     fprintf(stdout, "%s %d %.2f\n", stu.arr, stu.age, stu.score);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// int main()
// {
//     // 打开文件
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
//                     "wb");
//     if(pf == NULL)
//     {
//         // printf("%s\n", strerror(errno));
//         perror(NULL);
//         return 1;
//     }

//     // 操作文件
//     Stu stu = {"zhangsan", 18, 90.5f};
//     fwrite(&stu, sizeof(stu), 1, pf);

//     // 关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

int main()
{
    // 打开文件
    FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_09\\test.txt", 
                    "r");
    if(pf == NULL)
    {
        // printf("%s\n", strerror(errno));
        perror(NULL);
        return 1;
    }

    // 操作文件
    Stu stu;
    memset(&stu, 0, sizeof(Stu));
    fread(&stu, sizeof(stu), 1, pf);
    // printf("%s %d %.2f\n", stu.arr, stu.age, stu.score);
    fprintf(stdout, "%s %d %.2f\n", stu.arr, stu.age, stu.score);

    // 关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}