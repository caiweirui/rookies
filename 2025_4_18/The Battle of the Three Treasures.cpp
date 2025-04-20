/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <bits/stdc++.h>  
using namespace std;  
#define N 1000000  
#define MaxNum 1000000000  
  
int S1[N],S2[N],S3[N];  
  
int DiffWeight(int i, int j, int k){  
    return abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);  
}  
// 返回S1[i],S2[j],S3[k]中最小的序号  
// 返回i表示Si对应的数最小  
int xls_min(int i, int j, int k){  
    if(S1[i] <= S2[j]){  
        if(S1[i] <= S3[k]){  
            return 1;  
        }  
        return 3;  
    }  
    else{  
        if(S2[j] <= S3[k]){  
            return 2;  
        }  
        return 3;  
    }  
}  
  
// n -> 集合的大小  
int findMinDiffWeight(int n);  
  
int main()  
{  
    int n;  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S1[i]);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S2[i]);  
    for (int i = 0; i < n; i++)  
        scanf("%d", &S3[i]);  
    printf("%d\n", findMinDiffWeight(n));  
    return 0;  
}  

// 找到最小D
// 三个下标，最小数往后找一个数
// 一共遍历3n次
int findMinDiffWeight(int n) 
{
    int i = 0;
    int j = 0;
    int k = 0;
    int min = S1[n - 1] + S2[n - 1] + S3[n - 1];
    int temp = 0;
    for(int t = 0; t < 3 * n; t++)
    {
        temp = DiffWeight(i, j, k);
        if(min > temp)
        {
            min = temp;
        }
        switch(xls_min(i, j, k))
        {
            // 判断越界
            case 1: 
                if(i < n - 1)
                {
                    i++;    
                }
                break;
            case 2: 
                if(j < n - 1)
                {
                    j++;    
                }
                break;
            case 3: 
                if(k < n - 1)
                {
                    k++;    
                }
                break;

            default:        
                break;
        }
    }
    return min;
} 

  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  