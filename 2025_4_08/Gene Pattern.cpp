// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <math.h>
// #include <assert.h>

// //Description
// // 转座子指一段可以从原位上单独复制或断裂下来，环化后插入另一位点，并对其后的基因起调控作用的DNA序列，即转座子在基因序列中没有特定位置。已知某原核生物的某段基因中含有一个转座子。现给出多个个体相关基因序列（用连续正整数编号基因片段），设计程序找出转座子。
// // Input
// // 第一行，一个数字n，表示相关基因序列所含有基因片段的个数。
// // 第i（100>=i>=2）行，每行n个数字，表示第(i-1)个个体相关基因序列。

// // Output
// // 一个数字，即转座子对应编号。若无法确定转座子，输出“-1”.

// // Sample Input 1
// // 6
// // 1 2 3 4 5 6
// // 1 3 2 4 5 6
// // 1 3 4 5 2 6
// // 2 1 3 4 5 6

// // Sample Output 1
// // 2

// // Sample Input 2
// // 5
// // 1 2 3 4 5
// // 1 3 2 4 5
 
// // Sample Output 2
// // -1

// // Hint
// // 对于样例1，基因片段1、3、4、5、6位置不变，2位置不确定，则转座子为2.
// // 对于样例2，基因片段1、4、5位置不变，2、3位置不确定，则无法确定转座子为2或3.
// // 对于100%的数据：n<=50，且基因片段编号均属于区间[1,n]且不重复.

// 处理思路
// 输入处理：读取基因序列长度 n 和所有个体序列，存储到二维数组 sequences 中。
// 候选收集：遍历第一个序列的所有元素，筛选出存在于所有序列中的候选元素。
// 转座子验证：对每个候选元素，检查移除该元素后所有序列的剩余元素是否顺序一致。
// 结果判断：若存在唯一的有效候选，输出其值；否则输出 -1。

// int findTransposon(int arr[4][6], int row, int col) {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int count = 0;
//     int flag = 0;
//     int number = 0;

//     //编号
//     for(i = 1; i < row; i++)
//     {
//         for(j = 0; j < col; j++)
//         {
//             for(k = 0;k < row; k++)
//             {
//                 if(arr[i][j] == arr[0][k])
//                 {
//                     arr[i][j] = k;
//                 }
//             }
//         }
//     }

//     //如果同时没有按照顺序，就是有问题的
//     for(i = 1; i < row; i++)
//     {
//         for(j = 0; j < col; j++)
//         {
//             if(arr[i][j] < arr[i][j - 1] && arr[i][j] > arr[i][j + 1])
//             {
//                 flag++;
//                 number = arr[i][j];
//             }
//         }
//     }
//     if(flag > row - 1)
//     {
//         return -1;
//     }
//     else
//     {
//         return arr[0][number];
//     }
// }

// int main()
// {
//     int arr[4][6] = {{1, 2, 3, 4, 5, 6}, 
//         {1, 3, 2, 4, 5, 6}, 
//         {1, 2, 4, 5, 3, 6}, 
//         {2, 1, 3, 4, 5, 6}};
//     printf("%d\n",findTransposon(arr, 4, 6));
//     return 0;
// }

// // 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ 100  // 最大序列数
#define MAX_N 1000   // 最大基因片段数

static int sequences[MAX_SEQ][MAX_N];
static int m; // 实际序列数目

// 检查x是否为转座子
int is_transposon(int x, int n) {
    // 生成基准subseq
    int base[MAX_N];
    int base_len = 0;
    for (int i = 0; i < n; i++) {
        if (sequences[0][i] != x) {
            base[base_len++] = sequences[0][i];
        }
    }

    // 检查其他序列
    for (int s = 1; s < m; s++) {
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (sequences[s][i] != x) {
                if (pos >= base_len || sequences[s][i] != base[pos]) {
                    return 0;
                }
                pos++;
            }
        }
        if (pos != base_len) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 读取换行符

    m = 0;
    char line[100000];
    while (fgets(line, sizeof(line), stdin)) {
        // 解析该行的n个数字
        int *seq = sequences[m];
        int count = 0;
        char *token = strtok(line, " \n");
        while (token != NULL && count < n) {
            seq[count++] = atoi(token);
            token = strtok(NULL, " \n");
        }
        if (count == n) {
            m++;
        } else {
            break; // 行格式错误，停止读取
        }
    }

    if (m < 2) {
        printf("-1\n");
        return 0;
    }

    // 收集候选x：出现在所有序列中的元素
    int candidates[MAX_N];
    int candidate_count = 0;

    // 检查第一个序列中的每个元素是否存在于所有其他序列
    for (int i = 0; i < n; i++) {
        int x = sequences[0][i];
        int present_all = 1;
        for (int s = 1; s < m; s++) {
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (sequences[s][j] == x) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                present_all = 0;
                break;
            }
        }
        if (present_all) {
            candidates[candidate_count++] = x;
        }
    }

    // 检查每个候选x
    int result = -1;
    int result_count = 0;

    for (int i = 0; i < candidate_count; i++) {
        int x = candidates[i];
        if (is_transposon(x, n)) {
            if (result_count == 0) {
                result = x;
                result_count = 1;
            } else {
                // 多个候选，输出-1
                result_count++;
                break;
            }
        }
    }

    if (result_count == 1) {
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}