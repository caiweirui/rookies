#include<bits/stdc++.h>

// 判断上三角矩阵
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
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(i > j && arr[i][j])
            {
                printf("NO!\n");
                return 0;
            }
        }
    }

    printf("YES\n");

    return 0;
}