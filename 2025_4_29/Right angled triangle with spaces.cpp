#include <bits/stdc++.h>
using namespace std;

// 输出带空格的三角形
// 5
//         *
//       * *
//     * * *
//   * * * *
// * * * * *
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i + j >= n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}