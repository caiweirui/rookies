#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(int n)
{
    int i = 0;
    int ret = 0;
    while(n)
    {
        ret += n % 10;
        n = n / 10;
    }
    return ret;
}

int cmp(const void *e1, const void *e2)
{
    return (*((int *)e2) - *((int*)e1));
}

int countLargestGroup(int n) {
    int arr[40];
    memset(arr, 0, sizeof(arr));
    int i = 0;
    for(i = 1; i <= n; i++)
    {
        arr[count(i)]++;
    }
    qsort(arr, 40, sizeof(int), cmp);
    int ret = 0;
    while(arr[i++] == arr[0])
    {
        ret++;
    }
    return ret;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = countLargestGroup(n);
    printf("%d\n", ret);
    return 0;
}