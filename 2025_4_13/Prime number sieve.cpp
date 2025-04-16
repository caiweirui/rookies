#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//质数筛，创建一个只含有质数的数组
int prime[1000000] = {0};
int len = 0;
long long vis[100000000] = {0};

void sieve(long long n)
{
    if(n < 2)
    {
        return;
    }
    else
    {
        long long i = 0;
        long long j = 0;
        int k = 0;
        memset(vis, 0, sizeof(long long));
        vis[0] = 1;
        vis[1] = 1;
        vis[2] = 0;

        // 把所有的偶数都标记为非素数
        for(i = 4; i <= n; i += 2)
        {
            vis[i] = 1;
        }

        // 标记所有的小于sqrt(n)的合数
        for(i = 3; i * i <= n; i += 2)
        {
            // vis[i]标记为0时，记录为素数
            if(!(vis[i]))
            {
                for(j = i; j * i <= n; j++)
                {
                    vis[i * j] = 1;
                }
            }
        }

        // 遍历小于n的素数
        prime[k++] = 2;
        for(i = 3; i <= n; i++)
        {
            if(!(vis[i]))
            {
                prime[k++] = i;
                len = k;
            }
        }
    }
}


int main()
{
    long long n = 0;
    while(scanf("%lld", &n) != EOF)
    {
        long long i = 0;
        sieve(n);
        for(i = 0; i < len; i++)
        {
            if(n / prime[i] == prime[i] && n % prime[i] == 0)
            {
                printf("TQL!\n");
                break;
            }
            if(n / prime[i] < prime[i])
            {
                printf("TCL!\n");
                break;
            }
        }
    }
    return 0;

}