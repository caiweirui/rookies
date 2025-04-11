#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

void sort(int *arr, int len)
{
    //插入排序
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 1; i < len; i++)
    {
        int temp = arr[i];
        flag = i;
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                flag = j;
            }   
        }
        arr[flag] = temp;
    }
}

//如果kill数=龙数，则讨伐成功返回学分，不然讨伐失败
int credit(int *arrn, int *arrm, int n, int m)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int flag = 0;
    int kill = 0;
    for(i = 0; i < n; i++)
    {
        for(j = flag; j < m; j++)
        {
            if(arrm[j] >= arrn[i])
            {
                sum += arrm[j];
                flag = j + 1;
                kill++;
                break;
            }
        }
    }
    if(kill == n)
    {
        return sum;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n ,&m);
    getchar();
    if(n > m)
    {
        printf("bit is doomed!\n");
    }
    else
    {
        int i = 0;
        int j = 0;
        int arrn[101] = {0};
        int arrm[101] = {0}; 
        for(i = 0; i < n ; i++)
        {
            scanf("%d", &arrn[i]);
            getchar();
        }
        for(i = 0; i < m ; i++)
        {
            scanf("%d", &arrm[i]);
            getchar();
        }
    
        //从小到大排序
        sort(arrn, n);
        sort(arrm, m);

        int sum = credit(arrn, arrm, n, m);

        if(sum)
        {
            printf("%d\n", sum);
        }
        else
        {
            printf("bit is doomed!\n");
        }
    
    }

    return 0;
}