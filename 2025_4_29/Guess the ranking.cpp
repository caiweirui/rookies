#include<bits/stdc++.h>
using namespace std;

// B 2 A 3
// B 2 E 4
// C 1 D 2
// C 5 D 3
// E 4 A 1
// 穷举
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int flag = 0;
    for(a = 1; a <= 5; a++)
    {
        for(b = 1; b <= 5; b++)
        {
            for(c = 1; c <= 5; c++)
            {
                for(d = 1; d <= 5; d++)
                {
                    for(e = 1; e <= 5; e++)
                    {
                        if(!((b == 2) ^ (a == 3)))
                        {
                            continue;
                        }
                        if(!((b == 2) ^ (e == 4)))
                        {
                            continue;
                        }
                        if(!((c == 1) ^ (d == 2)))
                        {
                            continue;
                        }
                        if(!((c == 5) ^ (d == 3)))
                        {
                            continue;
                        }
                        if(!((e == 4) ^ (a == 1)))
                        {
                            continue;
                        }
                        // 过滤不需要的情况
                        if(a * b * c * d * e == 120)
                            printf("%d %d %d %d %d\n", a, b, c, d, e);
                    }
                }
            }
        }
    }
    return 0;   
}