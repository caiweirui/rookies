#include <bits/stdc++.h>  
using namespace std;  

int arr[720][6] = {0};

// 阶乘
int fac(int n)
{
    int i = 0;
    int ret = 1;
    for(i = 1; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}

// 全排列
void Permutations(int N)
{
    int i = 0;
    int j = 0;
    int row = fac(N) + 1;
    if(N = 1)
    {
        arr[0][0] = 1;
    }
    else
    {
        for(i = 0; i < fac(N); i++)
        {
            for(j = 0; j < N; j++)
            {
                arr[row][j] = N;
            }
            for(j = 0; j <= N; j++)
            {
                if(!arr[row][j])
                {
                    arr[row][j] = j + 1;
                }
            }
            row++;
        }
        Permutations(N - 1);
    }


}


int main()
{
    int N = 0;
    int xa = 0;
    int ya = 0;
    int xb = 0;
    int yb = 0;
    int xy[6][2] = {0};
    int i = 0;
    int j = 0;
    scanf("%d", &N);
    getchar();
    // scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    // for(i = 0; i < N; i++)
    // {
    //     getchar();
    //     for(j = 0; j < 2; j++)
    //     {
    //         scanf("%d", &xy[i][j]);
    //     }
    // }

    Permutations(N);

    for(i = 0; i < fac(N); i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}