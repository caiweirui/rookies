/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <bits/stdc++.h>  
using namespace std;  
const int maxn = 200005;  
int n;  
int a[maxn];  
void findminandmax(int n); // you should finish this  
int cmp(int i, int j)  
{  
    if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n) return -2;  
    if (a[i] > a[j]) return 1;  
    if (a[i] == a[j]) return 0;  
    if (a[i] < a[j]) return -1;  
}  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 1; i <= 2 * n; i++)  
        scanf("%d", &a[i]);  
    findminandmax(n);  
    return 0;  
}  
// typedef int(* pf)(const void*, const void*);
void findminandmax(int n) 
{ 
    // qsort(a, 2 * n, sizeof(a[0]),(pf)cmp);
    int arrMin[maxn] = {0};
    int arrMax[maxn] = {0};
    int i = 0;
    int len = 1;
    for(i = 1; i <= 2 * n; i += 2)
    {
        switch(cmp(i, i + 1))
        {
            case -2:break;
            case -1:arrMin[len] = a[i];
                    arrMax[len++] = a[i + 1];
                    break;
            case 0:
            case 1: arrMin[len] = a[i + 1];
                    arrMax[len++] = a[i];
                    break;
            default:break;
        }
    }
    int temp = 0;
    for(i = 1; i <= n; i++)
    {
        if(cmp(1, i) == 1)
        {
            temp = arrMin[1];
            arrMin[1] = arrMin[i];
            arrMin[i] = temp;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(cmp(1, i) == -1)
        {
            temp = arrMax[1];
            arrMax[1] = arrMax[i];
            arrMax[i] = temp;
        }
    }

    printf("%d %d\n", arrMin[1], arrMax[1]);
} 

  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  