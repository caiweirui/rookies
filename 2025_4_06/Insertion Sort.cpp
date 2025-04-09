#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

//插入排序
//将arr[i]插入到arr[0]...arr[i-1]中正确的位置
//用temp存储要排序的那一个
//大于temp的都要后移一位，然后将temp插入到应该在的地方
//5 4 3 2 4
//5
//4 5    
//3 4 5
//2 3 4 5
//2 3 4 4 5

void insertion_sort(int *arr, const int n)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 1; i < n; i++)
    {
        temp = arr[i];
        flag = i;
        for(j = i - 1; j >= 0; j--)
        {
            //如果temp比这一位小，则这一位后移一位，temp占据这一位
            if(temp < arr[j])
            {
                arr[j + 1] = arr[j];
                flag = j;
            }
        }
        arr[flag] = temp;
    }
    
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    int i = 0;
    int arr[1000];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}