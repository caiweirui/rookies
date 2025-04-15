#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>



// 为淘宝送一份快递收入18.3元，为一号店送一份外卖收入11.2元，为亚马逊送一份外卖收入9.8元。
// 双11这天张小元一共送了n份快递，共收入m元，问n份外卖中淘宝，一号店和亚马逊各几份。
// 如无解，输出Error！
// 输入：总收入m，快递份数n
// 输出：依次输出淘宝,一号店和亚马逊的快递份数。
// 如果有多组结果满足条件，则依次按照淘宝的份数，一号店的份数和亚马逊的份数升序输出。

int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);


    int i = 0; 
    int j = 0;
    int k = 0;

    int arr[100][3] = {0};
    int a = 0;

    for(i = 0; i <= n; i++)
    {
        for(j = n - i; j >= 0; j--)
        {
            for(k = n - i - j; k >= 0; k--)
            {
                int intmoney = 18 * i + 11 * j + 9 * k;
                int floatmoney = 3 * i + 2 * j + 8 * k;
                if(floatmoney % 10 == 0)
                {
                    intmoney += floatmoney / 10;
                    if(i + j + k == n && intmoney == m)
                    {
                        arr[a][0] = i;
                        arr[a][1] = j;
                        arr[a++][2] = k; 
                    }
                }
                
            }
        }
    }

    int temp = 0;
    
    if(a)
    {
        for(i = 0; i < a - 1; i++)
        {
            for(j = 0; j < a - 1 - i; j++)
            {
                if(arr[j][0] > arr[j + 1][0])
                {
                    for(k = 0; k < 3; k++)
                    {
                        temp = arr[j][k];
                        arr[j][k] = arr[j + 1][k];
                        arr[j + 1][k] = temp;                    
                    }
                }
            }
        }
        for(i = 0; i < a - 1; i++)
        {
            for(j = 0; j < a - 1 - i; j++)
            {
                if(arr[j][1] > arr[j + 1][1] && arr[j][0] == arr[j + 1][0])
                {
                    for(k = 0; k < 3; k++)
                    {
                        temp = arr[j][k];
                        arr[j][k] = arr[j + 1][k];
                        arr[j + 1][k] = temp;                    
                    }
                }
            }
        }
        for(i = 0; i < a - 1; i++)
        {
            for(j = 0; j < a - 1 - i; j++)
            {
                if(arr[j][2] > arr[j + 1][2] && arr[j][0] == arr[j + 1][0] && arr[j][1] == arr[j + 1][1])
                {
                    for(k = 0; k < 3; k++)
                    {
                        temp = arr[j][k];
                        arr[j][k] = arr[j + 1][k];
                        arr[j + 1][k] = temp;                    
                    }
                }
            }
        }
        for(i = 0; i < a; i++)
        {
            for(j = 0; j < 3; j++)
            {
                printf("%d ", (int)arr[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Error!\n");
    }


    return 0;
}

