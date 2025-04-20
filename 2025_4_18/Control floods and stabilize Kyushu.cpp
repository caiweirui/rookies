#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

//这两个堤坝都是有n个单位的长度，每个单位长度泥土原来的高度是ai和bi。而两个堤坝的相似度是将所有（ai-bi）^2求和。
// 你可以随意提高或降低一个位置的堤坝高度（一个单位），但不能低于0，这个操作大禹要求你使用R次。
// 请问你能做到的最小相似度是多少。

int cmp(const void *e1, const void *e2)
{
    return (*((int*)e2) - *((int*)e1));
}

int main()
{
    int n = 0;
    int r = 0;
    int arra[1000] = {0};
    int arrb[1000] = {0};
    int i = 0;
    scanf("%d %d", &n, &r);
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arra[i]);
    }
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arrb[i]);
        //两个堤坝的绝对值的差
        arra[i] = arrb[i] - arra[i];
        if(arra[i] < 0)
        {
            arra[i] = -arra[i];
        }
    }

    //降序排列
    qsort(arra, n, sizeof(arra[0]), cmp);


    i = 0;

    //按照顺序逐渐-1
    while(r--)
    {
        if(arra[i] > 0)
        {
            arra[i]--;
        }
        i++;
        i = i % n;
    }

    int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += arra[i] * arra[i];
    }

    printf("%d\n", sum);

    return 0;
}