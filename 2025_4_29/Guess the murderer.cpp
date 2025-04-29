#include <bits/stdc++.h>
using namespace std;

// A 0
// C 1
// D 1
// D 0
// 3真1假
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for(a = 0; a < 2; a++)
    {
        for(b = 0; b < 2; b++)
        {
            for(c = 0; c < 2; c++)
            {
                for(d = 0; d < 2; d++)
                {
                    if(((a == 0) + (c == 1) + (d == 1) + (d == 0)) == 3)
                    {
                        if(a + b + c + d == 1)
                        {
                            printf("%d %d %d %d\n", a, b, c, d);
                        }
                    }
                }
            }
        }
    }
    return 0;
}