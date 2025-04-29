#include<bits/stdc++.h>

// 判断是否有序
int IsOrderred(int *arr, int n)
{
    int i = 0;
    int flag1 = 0;
    int flag2 = 0;
    for(i = 0; i < n - 1; i++)
    {
        if(arr[i + 1] > arr[i])
        {
            flag1 = 1;
        }
        if(arr[i + 1] < arr[i])
        {
            flag2 = 1;
        }
    }
    if(flag1 == 1 && flag2 == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int arr[100] = {0};
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ret = IsOrderred(arr, n);
    printf("%d\n", ret);

    return 0;
}