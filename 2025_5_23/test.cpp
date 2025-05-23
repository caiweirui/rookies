#include<stdio.h>
#include<math.h>
#include <string.h>
#include <ctype.h>

// int main()
// {
//     unsigned char i = 7;        // 大于等于0
//     int j = 0;
//     for(; i > 0; i -= 3){       // 只有i == 0循环终止
//         ++j;
//     }
//     printf("%d\n", j);
//     return 0;
// }


// int main()
// {
//     char a = 0, ch;
//     while ((ch = getchar()) != '\n') 
//     {
//         if(a % 2 != 0 && (ch >= 'a' && ch <= 'z'))  // 等效于偶数位toupper()
//             ch = ch - 'a' + 'A';
//         a++;        
//         putchar(ch);
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     int x = 1;
//     do
//     {
//         printf("%2d\n", x++);   // 死循环1
//     } while (x--);
    
//     return 0;
// }

// int main()
// {
//     int a = -3;     
//     // 11111111 11111111 11111111 11111101
//     unsigned int b = 2;
//     // 00000000 00000000 00000000 00000010
//     long c = a + b;
//     // 11111111 11111111 11111111 11111111
//     // -1
//     printf("%ld\n", c);
//     return 0;
// }

// int f(int x)
// {
//     return ((x > 2) ? x * f(x - 1) : 3);
// }

// int main()
// {
//     int i;
//     i=f(f(2));
//     // f(2) = 3;
//     // i = f(3)
//     printf("%d\n", i);
//     return 0;
// }

// int main()
// {
//     int a = 21;
//     // 00010101
//     // 00011111
//     // 00001010 = 10
//     a ^= (1 << 5) - 1;
//     printf("%d\n", a);
//     return 0;
// }

// #define N 3 + 1
// #define Y(n) ((3 + 1 + 1) * n)

// int main()
// {
//     printf("%d\n", 2 * (3 + 1 + ((3 + 1 + 1) * 5 + 1)));
//     return 0;
// }

// int main()
// {
//     int x = 0;
//     scanf("%d", &x);
//     int fib[30] = {0, 1};
//     int i = 0;
//     for(i = 2; i < 30; i++)
//     {   
//         fib[i] = fib[i - 1] + fib[i - 2];
//     }
//     int min = (int)abs(fib[0] - x);
//     int temp = 0;
//     for(i = 0; i < 30; i++)
//     {
//         temp = (int)abs(fib[i] - x);
//         if(temp <= min)
//         {
//             min = temp;
//         }
//         else
//         {
//             break;
//         }
//     }
//     printf("%d\n", min);
//     return 0;
// }

int main()
{
    char* arr = (char*)calloc(1000, sizeof(char));
    char* temp = (char*)calloc(1000, sizeof(char));
    arr = fgets(arr, 1000, stdin);
    int arrLen = strlen(arr);
    arr[--arrLen] = '\0';
    int i = 0;
    for(i = 0; i < arrLen; i++)
    {
        if(isspace(arr[i]))
        {
            strcat(temp, "%%20");       // %要转义
        }
        else
        {
            temp[strlen(temp)] = arr[i];
        }
    }
    strcpy(arr, temp);
    printf(arr);
    printf("\n");
    printf(temp);

    free(arr);
    free(temp);
    arr = NULL;
    temp = NULL;

    return 0;
}