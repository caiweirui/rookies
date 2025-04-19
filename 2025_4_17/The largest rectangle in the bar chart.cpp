#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// int largestRectangleArea(int* heights, int heightsSize) {
//     int i = 0;
//     int j = 0;
//     int max = heights[0];
//     int min = heights[0];
//     int s = 0;
//     int len = 0;
//     int temp = 0;
//     for(i = 0; i < heightsSize; i++)
//     {
//         if(max < heights[i])
//         {
//             max = heights[i];
//         }
//         if(min > heights[i])
//         {
//             min = heights[i];
//         }
//     }

//     if(min == 0)
//     {
//         min = 1;
//     }

//     for(i = max; i >= min; i--)
//     {
//         temp = 0;
//         len = 0;
//         for(j = 0; j < heightsSize; j++)
//         {
//             if(heights[j] >= i)
//             {
//                 temp++;
//             }
//             if(heights[j] < i || j == heightsSize - 1)
//             {
//                 if(len < temp)
//                 {
//                     len = temp;
//                 }
//                 temp = 0;
//             }
//         }
//         if(i * len > s)
//         {
//             s = i * len;
//         }
//     }

//     return s;
// }

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[100000];    // 辅助栈存储柱子的索引
    int top = -1;         // 栈顶指针初始化
    int max_area = 0;     // 记录最大面积
    
    // 遍历所有柱子（包含虚拟的末尾哨兵）
    for (int i = 0; i <= heightsSize; ++i) {
        // 处理虚拟哨兵节点（当i达到数组长度时）
        int curr_height;
        if (i == heightsSize) {
            curr_height = 0;  // 虚拟哨兵高度设为0
        } else {
            curr_height = heights[i]; // 实际柱子高度
        }

        // 当遇到下降趋势时触发面积计算
        while (top != -1 && curr_height < heights[stack[top]]) {
            // 弹出栈顶元素作为计算基准高度
            int popped_index = stack[top];
            top--;  // 更新栈顶指针
            int h = heights[popped_index]; // 基准高度

            // 计算有效宽度
            int w;
            if (top == -1) { // 栈空时左边界到起点
                w = i; 
            } else { 
                // 有效范围为前一个更矮柱子的右侧到当前位置
                w = i - stack[top] - 1; 
            }

            // 更新最大面积记录
            int current_area = h * w;
            if (current_area > max_area) {
                max_area = current_area;
            }
        }

        // 将当前柱子索引入栈（维护递增特性）
        top++;
        stack[top] = i;
    }

    return max_area;
}

int main()
{
    int arr[] = {1,0,1,0,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = largestRectangleArea(arr, len);
    printf("%d\n", ret);
}