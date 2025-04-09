#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

//相互攻击，知道有一个变成0，刚开始y必定大于x
int gcd(int x, int y)
{
    int diff = 0;
    while(x != 0)
    {
        diff = y % x;
        y = x;
        x = diff;
    }
    return y;

}

// //返回荣誉殿堂人数
// long long fight(const int N, const long long D)
// {
//     int i = 0;
//     int j = 0;
//     long long count = 0;
//     for(i = 1; i <= N; i++)
//     {
//         for(j = i; j <= N; j++)
//         {
//             //整除即可
//             if(!(D % gcd(i, j)))
//             {
//                 count++;
//             }
            
//         }
//     }
//     return count;
// }

//欧拉函数：表示的是小于等于 n 和 n 互质的数的个数。
long long Euler(int n)
{
    int i = 0;
    long long count = 0;
    for(i = 1; i <= n; i++)
    {
        if(gcd(i, n) == 1)
        {
            count++;
        }
    }
    return count;
}

//对D分解因式

long long fight(const int N, const long long D)
{

}
int main()
{
    int T = 0;
    scanf("%d", &T);
    getchar();
    int i = 0;
    int N = 0;
    long long  D = 0;
    for(i = 0; i < T; i++)
    {
        scanf("%d %lld", &N, &D);
        getchar();

        //战斗结果
        printf("%lld\n", fight(N, D));

    }

    return 0;
}

