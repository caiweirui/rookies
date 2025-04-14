#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//得到琪露诺冰块的落点
void ice_land(int arr[21][21], int x1, int y1, int x2, int y2)
{
    int i = 0;
    int j = 0;
    //只会落在8个日子格和4个田字格
    for(i = 0; i <= x1; i++)
    {
        for(j = 0; j <= y1; j++)
        {
            if(x2 != i && y2 != j)
            {
                if(abs(x2 - i) + abs(y2 - j) == 3 || abs(x2 - i) == 2 && abs(y2 - j) == 2)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
}


// long long count(int arr[21][21], int x, int y)
// {
//     long long temp[2][21][21] = {0};



//     if(temp[0][x][y])
//     {
//         return temp[1][x][y];
//     }
//     else
//     {
//         return 
//     }

// }

int main()
{
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    scanf("%d %d", &x1, &y1);
    getchar();
    scanf("%d %d", &x2, &y2);
    int arr[21][21] = {0};
    int i = 0;
    int j = 0;

    ice_land(arr, x1, y1, x2, y2);

    // printf("%ld\n", count(arr, x1, y1));

    // for(i = 0; i < x1; i++)
    // {
    //     for(j = 0; j < y1; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // 动态规划计算路径数
    // 对于每个点，若未被阻挡则路径数等于左边和上边路径数之和。
    long long dp[21][21] = {0};
    //起点初始化为1
    dp[0][0] = (arr[0][0] == 0) ? 1 : 0;
    
    for (int i = 0; i <= x1; i++) {
        for (int j = 0; j <= y1; j++) {
            if (i == 0 && j == 0) continue; // 起点已初始化
            
            if (arr[i][j] == 1) {
                dp[i][j] = 0; // 冰块位置不可达
                continue;
            }
            
            // 累加左边和上边的路径数
            long long up = (i > 0) ? dp[i-1][j] : 0;
            long long left = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = up + left;
        }    

    }

    // printf("%ld\n", dp[x1][y1]);


    
    
    return 0;
}

// #include <stdio.h>
// #include <stdbool.h>

// int x1, y1;     // 魔理沙坐标
// int x2, y2;     // 琪露诺坐标
// int memo[21][21]; // 记忆化数组
// bool blocked[21][21]; // 冰块标记数组

// // 初始化冰块位置
// void init_blocked() {
//     for (int i = 0; i <= x1; i++) {
//         for (int j = 0; j <= y1; j++) {
//             // 计算欧氏距离平方
//             int dx = i - x2;
//             int dy = j - y2;
//             int dist_sq = dx*dx + dy*dy;
//             // 开区间 (2,3) 对应平方 (4,9)
//             blocked[i][j] = (dist_sq > 4 && dist_sq < 9);
//         }
//     }
// }

// // 递归+记忆化搜索函数
// long long dfs(int x, int y) {
//     // 边界检查
//     if (x > x1 || y > y1) return 0;
    
//     // 检查冰块
//     if (blocked[x][y]) return 0;
    
//     // 到达终点
//     if (x == x1 && y == y1) return 1;
    
//     // 检查记忆化结果
//     if (memo[x][y] != -1) return memo[x][y];
    
//     // 递归计算向右和向上的路径数
//     int right = dfs(x + 1, y);
//     int up = dfs(x, y + 1);
    
//     // 记忆化并返回结果
//     return memo[x][y] = right + up;
// }

// int main() {
//     // 读取输入
//     scanf("%d %d", &x1, &y1);
//     scanf("%d %d", &x2, &y2);
    
//     // 初始化冰块位置
//     init_blocked();
    
//     // 初始化记忆化数组
//     for (int i = 0; i <= x1; i++)
//         for (int j = 0; j <= y1; j++)
//             memo[i][j] = -1;
    
//     // 计算并输出结果
//     printf("%ld\n", dfs(0, 0));
//     return 0;
// }