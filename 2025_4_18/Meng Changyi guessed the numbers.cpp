/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <bits/stdc++.h>  
using namespace std;  
int x, n;  
void guessnumber(int n); // you should finish this  
int guess(int y)  
{  
    if (y < 1 || y > n) return -1;  
    if (x >= y) return 1;  
    if (x < y) return 0;   
}  
int main()  
{  
    scanf("%d%d", &x, &n);  
    guessnumber(n);  
    return 0;  
}  

//二分查找
void guessnumber(int n) 
{ 
    int min = 0;
    int max = n;
    int mid = 0;
    while(min <= max)
    {   
        mid = (min + max) / 2;
        switch (guess(mid))
        {
        case 1: printf("%d\n", mid);
                if(x > mid)
                {
                    min = mid + 1;
                }
                else
                {
                    return;
                }
                break;
        case 0: printf("%d\n", mid);
                max = mid - 1;
        default:
            break;
        }
    }
} 

  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  