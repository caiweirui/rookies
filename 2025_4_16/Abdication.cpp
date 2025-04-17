#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// 1.每一轮投票，可以选择“+”或者“-”这两种信仰。
// 2.每一轮投票中，投票多的信仰的支持者留下，其余全部淘汰。
// 3.每一轮投票中，如果出现平票的现象，全部离场。意味着这一次竞选将没有获胜者。
// 4.投票轮数固定，最后一轮投票结束后，不论场上多少人将会直接诞生该职位的人选

//把和尧信仰不相同的，都干掉就行
int kill(char (*arr)[1000], int n, int turn)
{
    char temp[1000] = {'0'};
    strncpy(temp, arr[0], turn);
    int i = 0;
    int j = 0;
    int ret = 0;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < turn; j++)
        {
            if(arr[i][j] != temp[j])
            {
                ret++;
                break;
            }
        }
    }
    return ret;

}

int main()
{
    int n = 0;
    int turn = 0;
    scanf("%d %d", &n, &turn);
    getchar();
    int i = 0;
    int j = 0;
    char arr[1000][1000] = {'0'};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < turn; j++)
        {
            scanf("%c", (*(arr + i) + j));
        }
        getchar();
    }
    int ret = n - kill(arr, n, turn);

    printf("%d\n", ret);

    return 0;
}
