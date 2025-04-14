#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//内积
double inner_product(double* arr1, double* arr2, int len)
{
    int i = 0;
    double sum = 0.0;
    for(i = 0; i < len; i++)
    {
        sum += *(arr1 + i) * *(arr2 + i);
    }
    return sum;
}

//向量相减
void arrsub(double* arr1, double* arr2, double *arrret, int len, double k)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        *(arrret + i) = *(arr1 + i) - k * *(arr2 + i);
    }
}

//单位化
void unitization(double *arr, int len)
{
    int i = 0;
    double sum = 0.0;
    for(i = 0; i < len; i++)
    {
        sum += *(arr + i) * *(arr + i);
    }
    for(i = 0; i < len; i++)
    {
        *(arr + i) /= sqrt(sum);
    } 
}

// 正交规范化
void orthogonal_normalization(double arr[11][11], int n, int d, double beta[11][11])
{
    int i = 0;
    int j = 0;
    double k = 0.0;
    double temp[11] = {0.0};
    int t = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i; j > 0; j--)
        {
            k = inner_product(arr[i], beta[j - 1], d) / inner_product(beta[j - 1], beta[j - 1], d); 
            if(j == i)
            {
                arrsub(arr[i], beta[j - 1], beta[i], d, k);
            }
            else
            {
                arrsub(beta[i], beta[j - 1], temp, d, k);

                for(t = 0; t < d; t++)
                {
                    beta[i][t] = temp[t];
                    temp[t] = 0.0;
                }
            }
        }
        unitization(beta[i], d);
    }
}

int main()
{
    int n = 0;
    int d = 0;
    scanf("%d %d", &n, &d);
    int i = 0;
    int j = 0;
    double arr[11][11] = {0.0};
    double beta[11][11] = {0.0};
    getchar();

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < d; j++)
        {
            scanf("%lf", &arr[i][j]);
        }
        getchar();
    }

    for(j = 0; j < d; j++)
    {
        beta[0][j] = arr[0][j];
    }

    orthogonal_normalization(arr, n, d, beta);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < d; j++)
        {
            printf("%.2lf ", beta[i][j]);
        }
        printf("\n");
    }

    return 0;
}