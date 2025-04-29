#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; 
    scanf("%d", &n);
    int arr[100][100] = {0};
    memset(arr, 0, sizeof(arr));
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else if(i >= 1 && j >= 1)
            {   
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        // for(int k = i + 1; k < n; k++)
        // {
        //     printf(" ");
        // }
        for(j = 0; j < n; j++)
        {
            if(i >= j)
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}