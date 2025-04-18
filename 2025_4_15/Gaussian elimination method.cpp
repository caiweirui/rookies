#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


double det(double arr[101][101], int n)
{
}

//主元的个数
int r(double arr[101][101], int n)
{

}

int dim(double arr[101][101], int n)
{

}

int main()
{
    int T = 0;
    int n = 0;
    double arr[101][101];
    int i = 0;
    int j = 0;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%lf", &arr[i][j]);
            }
        }
    }

    // double ret1 = det(arr, n);
    int ret2 = r(arr, n);
    // int ret3 = dim(arr, n);

    printf("%d", ret2);
    // printf("%.2lf %d %d", ret1, ret2, ret3);

    return 0;
}