#include<stdio.h>

int mySqrt(int x) {
    int left = 0;
    int right = 46340;
    int mid = 0;
    if(right * right <= x)
    {
        return 46340;
    }
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
        {
            return mid;
        }
        else if(mid * mid > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return mid;
}

int cmp(const void *e1, const void *e2)
{
    return ((*(int*)e1) - (*(int*)e2));
}

int main()
{
    int a = 0;
    int b = 1;
    printf("%d\n", cmp(&a, &b));
    return 0;
}