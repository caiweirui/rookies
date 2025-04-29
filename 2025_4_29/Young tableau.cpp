#include<bits/stdc++.h>

// 杨氏矩阵
// 有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
// 请编写程序在这样的矩阵中查找某个数字是否存在。
// 要求：时间复杂度小于O(N)

// 返回坐标的方法：使用结构体
// 将需要输出的x、y用指针的形式赋值给函数

void FindNumber(int arr[3][3], int n)
{
    int i = 0;
    int j = 0;

    //比所有的数字都大或都小，输出没有
    if(arr[2][2] < n || arr[0][0] > n)
    {
        printf("没有\n");
        return;
    }
    else
    {
        // 如果比每一行的最后一个数字大，则不需要比较这一行，直接比较下一行
        while(i < 3)
        {
            if(n > arr[i][2])
            {
                i++;
            }
            else
            {
                break;
            }
        }

        for(j = 0; j < 3; j++)
        {
            if(arr[i][j] == n)
            {
                printf("%d %d\n", i, j);
                return;
            }
        }
    }
}

int main()
{
    int arr[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int n = 0;
    scanf("%d", &n);
    FindNumber(arr, n);
    return 0;
}