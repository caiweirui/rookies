#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 每一次操作 
// 1 X代表对于每一个当前算筹数量为奇数的堆，再加入X根算筹。
// 2 X代表对于每一个当前算筹数量为偶数的堆，再加入X根算筹。
// 你现在要回答的是，在q次操作后，这n堆算筹中一共含有多少根算筹。
int main()
{
    int n = 0;
    int q = 0;
    int arr[1000] = {0};
    int i = 0;
    int flag = 0;
    int add = 0;
    int oddnum = 0;
    int evennum = 0;
    int sum = 0;
    scanf("%d %d", &n, &q);
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            evennum++;
        }
        else
        {
            oddnum++;
        }
        sum += arr[i];
    }
    while(q--)
    {
        scanf("%d %d", &flag, &add);
        if(1 == flag)
        {
            sum += oddnum * add;
            // 奇数会改变奇偶数的数量
            if(add % 2 == 1)
            {
                evennum = oddnum + evennum;
                oddnum = 0;
            }
        }
        else
        {
            sum += evennum * add;
            if(add % 2 == 1)
            {
                oddnum = oddnum + evennum;
                evennum = 0;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}