#include <stdio.h>
#include <string.h>
#define N 1000

// 交换函数：通过指针修改原数组
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char input[N];
    int num[N];
    int len = 0;

    // 输入处理：逐字符读取符号和数字
    printf("输入带符号的数字序列（如 -1 2 -3）: ");
    fgets(input, N, stdin);

    char *token = strtok(input, " \n");
    while (token != NULL && len < N) {
        int val;
        if (sscanf(token, "%d", &val) == 1 && val >= -9 && val <= 9) {
            num[len++] = val;
        }
        token = strtok(NULL, " \n");
    }

    // 排序：按数值从小到大排列
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swap(&num[j], &num[j + 1]);
            }
        }
    }

    // 处理前导零：找到第一个非零元素交换
    if (len > 0 && num[0] == 0) {
        int first_non_zero = -1;
        for (int i = 1; i < len; i++) {
            if (num[i] != 0) {
                first_non_zero = i;
                break;
            }
        }
        if (first_non_zero != -1) {
            swap(&num[0], &num[first_non_zero]);
        }
    }

    // 输出结果
    for (int i = 0; i < len; i++) {
        printf("%d", num[i]);
    }
    printf("\n");

    return 0;
}