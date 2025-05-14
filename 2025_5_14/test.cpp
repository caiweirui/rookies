#include<bits/stdc++.h>

// typedef struct
// {
//     char name[10];
//     int age;
//     float score;
// }Stu;

// int main()
// {
//     Stu s = {"zhangsan", 20, 55.5f};
//     Stu temp = {0};
//     char arr[100] = {0};
//     sprintf(arr, "%s %d %f", s.name, s.age, s.score);
//     fprintf(stdout, arr);
//     sscanf(arr, "%s %d %f", temp.name, &(temp.age), &(temp.score));
//     fprintf(stdout, "\n%s %d %f\n", (temp.name), (temp.age), (temp.score));
// }

// int main()
// {
//     FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_14\\test.txt", "r");
//     if(pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }

//     // 定位
//     fseek(pf, 2, SEEK_SET);
//     char ch = fgetc(pf);
//     printf("%c\n", ch);

//     printf("%ld\n", ftell(pf));

//     fseek(pf, 2, SEEK_CUR);
//     ch = fgetc(pf);
//     printf("%c\n", ch);
//     printf("%ld\n", ftell(pf));

//     rewind(pf);
//     ch = fgetc(pf);
//     printf("%c\n", ch);

//     return 0;
// }

int main()
{
    // int a = 10000;
    // FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_14\\test.txt", "wb");
    // fwrite(&a, sizeof(a), 1, pf);
    // fclose(pf);
    // pf = NULL;

    int a = 10000;
    FILE* pf = fopen("D:\\University documents\\C language programming\\exercise\\2025_5_14\\test.txt", "w");
    fprintf(pf, "%d", a);
    fclose(pf);
    pf = NULL;

    return 0;
}