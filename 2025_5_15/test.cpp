#include<bits/stdc++.h>

// int main()
// {
//     int i = 0;
//     for(i = 0; i < 10; i++)
//     {
//         printf("file: %s\t%d\n", __FILE__, i);
//     }
//     printf("%d\n", __STDC__);
//     return 0;
// }

// #define SQUARE(X) ((X) * (X))

// int main()
// {
//     printf("%d\n", SQUARE(5 + 1));
//     return EXIT_SUCCESS;
// }

// #define PRINT(NUM, FORMAT) printf("the value of "#NUM" is "FORMAT"\n", NUM)

// int main()
// {
//     int a = 0;
//     PRINT(a, "%d");
//     return 0;
// }

// #define PRINT(NUM, FORMAT) printf("the value of "#NUM" is " #FORMAT "\n", NUM)

// int main() {
//     int a = 0;
//     PRINT(a, "%d"); // 展开为：printf("the value of ""a"" is " "%d" "\n", a);
//     return 0;
// }

// #define CAT(A, B) A##B

// int main()
// {
//     int ab = 100;
// // 满足条件编译
// #ifdef CAT
//     printf("%d\n", CAT(a, b));
// #endif CAT
//     printf("%d\n", ab);
//     return 0;
// }

#define OFFSETOF(type, m_name) (size_t)&(((type*)0)->m_name)

typedef struct 
{
    char c1;
    int i;
    char c2;
}S;


int main()
{
    S s = {0};
    // printf("%d\n", offsetof(S, i));
    printf("%d\n", OFFSETOF(S, i));
    return 0;
}
