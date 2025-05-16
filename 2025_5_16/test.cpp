#include<stdio.h>
#include<string.h>

// typedef struct A
// {
//     int a;
//     short b;
//     int c;
//     char d;
// }A;

// typedef struct B
// {
//     int a;
//     short b;
//     char c;
//     int d;
// }B;

// int main()
// {
//     fprintf(stdout, "%d\n", sizeof(A));
//     fprintf(stdout, "%d\n", sizeof(B));
//     return 0;
// }

// 0x02 29 00 00
// 0000 0010 0010 1001 0000 0000 0000 0000
// int main()
// {
//     unsigned char puc[4];
//     struct tagPIM   // 一共占用2字节
//     {
//         unsigned char ucPiml;
//         unsigned char ucData0 : 1;
//         unsigned char ucDatal : 2;
//         unsigned char ucData2 : 3;
//     }*pstPimData;
//     pstPimData = (struct tagPIM*)puc;
//     memset(puc, 0, 4);
//     pstPimData->ucPiml = 2;
//     pstPimData->ucData0 = 3;
//     pstPimData->ucDatal = 4;
//     pstPimData->ucData2 = 5;
//     printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//     return 0;
// }

// int main()
// {
//     // 联合体
//     // 小端存储
//     union
//     {
//         short k;
//         char i[2];
//     }*s, a;
//     s = &a;
//     s->i[0]= 0x39;
//     s->i[1]= 0x38;
//     printf("%x\n", a.k);

//     return 0;
// }

// #define  N 4
// #define Y(n) ((N + 2) * n)

// int main()
// {
//     int z = 2 * (N + Y(5 + 1));
//     //  z = 2 * (4 + ((4 + 2) * 5 + 1))     //70
//     printf("%d\n", z);
//     return 0;
// }
