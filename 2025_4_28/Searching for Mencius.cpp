/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <bits/stdc++.h>  
using namespace std;  
const int maxn = 1005;  
int n;  
bool good[maxn][maxn];  
void guessdalao(int n); // you should finish this  
int better(int a, int b)  
{  
    if (a <= 0 || a > n || b <= 0 || b > n) return -1;  
    return good[a][b];  
}  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 1; i <= n; i++)  
        for (int j = 1; j <= n; j++)  
        {  
            int t;  
            scanf("%d", &t);  
            good[i][j] = t;  
        }  
    guessdalao(n);  
    return 0;  
}  

void guessdalao(int n) 
{ 
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 1; i <= n; i++)
    {
        flag = 0;
        for(j = 1; j <= n; j++)
        {
            if(good[j][i] == 1)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1");
} 

  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  