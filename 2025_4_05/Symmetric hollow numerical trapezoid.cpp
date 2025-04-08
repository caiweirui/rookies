#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

// 打印对称的空心数字梯形
// 5678901098765
//  6         6
//   7       7
//    8     8
//     90109
void print_trapezoid(int n, int num)
{
    int i = 0;
    int j = 0;
    int arr[100][100] = {0};
    //标记所有应该打印的位置
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3 * n - 2; j++)
        {
            if((i == 0) || (i == j) || (j == 3 * n - 2 - i - 1) || (i == n - 1 && j >= n && (j < 2 * n - 1)))
            {
                arr[i][j] = -1;
            }
        }

    }
    //观察规律，分为左右两个部分，左边从左向右递增，右边从右向左递增
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3 * n - 2; j++)
        {
            if((j < (3 * n - 2) / 2) && arr[i][j] == -1)
            {
                printf("%d", (num + j) % 10);
            }
            else if((j >= (3 * n - 2) / 2) && arr[i][j] == -1)
            {
                printf("%d", (num + 3 * n - 2 - j - 1) % 10);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}

int main()
{
    int n = 0;
    int num = 0;
    scanf("%d %d", &n, &num);
    print_trapezoid(n, num);
    return 0;
}