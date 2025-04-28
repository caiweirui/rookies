/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <bits/stdc++.h>  
using namespace std;  
int getNumberOfInfestor(); // you should finish this  
const int POPULATION = 1000000;  
bool result;

// 1. 混合检测
// 2. 概率模型，混合检测呈现阴性的概率
// 3. 多组测试
// 4. 中位数优化
bool test(int y)  
{  
    if (y < 1 || y > POPULATION) {  
        printf("error");  
        return false;  
    }  
    // result = 随机从POPULATION人中抽取y人核酸检测的结果。  
    return result;  
}  
int main()  
{  
    int n;  
    scanf("%d", &n);  
    long long seed;  
    scanf("%lld", &seed);  
    int result = getNumberOfInfestor();  
    printf("%d\n", result);  
    // 输出你的询问记录  
    return 0;  
}  

// void swap(double *x, double *y)
// {
//     double temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int getNumberOfInfestor() {  
//     const int y_value[] = {10, 100, 1000};      //不同样本量
//     const int tests_per_y = 16;                 //每个样本量的测试次数
//     double p_hat[3] = {0};
//     int i = 0;
//     int y = 0;
//     int m = 0;
//     int j = 0;
//     double p = 0.0;
//     // 进行测试并统计阳性次数
//     for(i = 0; i < 3; i++)
//     {
//         y = y_value[i];
//         m = 0;
//         for(j = 0; j < tests_per_y; j++)
//         {
//             if(test(y))
//                 m++;
//         }
//         p_hat[i] = (double)m / tests_per_y;
//     }

//     // 计算各样本量的估计值
//     double n_est[3];
//     for(i = 0; i < 3; i++)
//     {
//         y = y_value[i];
//         p = p_hat[i];
//         if(p >= 1.0)
//         {
//             n_est[i] = 500000;
//         }
//         else if(p <= 0.0)
//         {
//             n_est[i] = 10;
//         }
//         else
//         {
//             n_est[i] = POPULATION * (1 - pow(1 - p, 1.0 / y));
//         }

//         // 限制在合理范围内
//         if(n_est[i] < 10)
//         {
//             n_est[i] = 10;
//         }
//         if(n_est[i] > 500000)
//         {
//             n_est[i] = 500000;
//         }

//     }

//     // 排序取中位数
//     if(n_est[0] > n_est[1])
//     {
//         swap(&n_est[0], &n_est[1]);
//     }
//     if(n_est[1] > n_est[2])
//     {
//         swap(&n_est[1], &n_est[2]);
//     }
//     if(n_est[0] > n_est[1])
//     {
//         swap(&n_est[0], &n_est[1]);
//     }

//     // 四舍五入
//     return (int)(n_est[1] + 0.5);
// }  
  
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int getNumberOfInfestor() {
    const int y_values[] = {10, 100, 1000}; // 不同样本量
    const int tests_per_y = 16; // 每个样本量的测试次数
    double p_hat[3] = {0};
    
    // 进行测试并统计阳性次数
    for (int i = 0; i < 3; i++) {
        int y = y_values[i];
        int m = 0;
        for (int j = 0; j < tests_per_y; j++) {
            if (test(y)) m++;
        }
        p_hat[i] = (double)m / tests_per_y;
    }
    
    // 计算各样本量的估计值
    double n_est[3];
    const int N = 1000000;
    for (int i = 0; i < 3; i++) {
        int y = y_values[i];
        double p = p_hat[i];
        if (p >= 1.0) {
            n_est[i] = 500000; // 上限
        } else if (p <= 0.0) {
            n_est[i] = 10; // 下限
        } else {
            n_est[i] = N * (1 - pow(1 - p, 1.0 / y));
        }
        // 限制在合理范围内
        if (n_est[i] < 10) n_est[i] = 10;
        if (n_est[i] > 500000) n_est[i] = 500000;
    }
    
    // 排序取中位数
    if (n_est[0] > n_est[1]) swap(&n_est[0], &n_est[1]);
    if (n_est[1] > n_est[2]) swap(&n_est[1], &n_est[2]);
    if (n_est[0] > n_est[1]) swap(&n_est[0], &n_est[1]);
    
    return (int)(n_est[1] + 0.5); // 四舍五入
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  