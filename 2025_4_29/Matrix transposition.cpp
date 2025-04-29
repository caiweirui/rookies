#include<bits/stdc++.h>

// 矩阵转置
void MatrixTransposition(int arr[100][100])
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < 100; i++)
    {
        for(j = i; j < 100; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

int main()
{
    int arr[100][100] = {0};
    int row = 0;
    int col = 0;
    scanf("%d %d", &row, &col);
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    MatrixTransposition(arr);

    for(i = 0; i < col; i++)
    {
        for(j = 0; j < row; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}