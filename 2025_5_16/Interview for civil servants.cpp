#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *e1, const void *e2)
{
    return (*(int*)e1 + *(int*)e2);
}

int main()
{
    int *arr = (int*)malloc(1000 * sizeof(int));
    memset(arr, 0, 1000 * sizeof(int));
    int i = 0;
    int arrLen = 0;
    int sum = 0.0;
    do
    {
        scanf("%d", &arr[arrLen++]);
    } while (getchar() == ' ');
    
    qsort(arr, arrLen, sizeof(int), compare);

    for(i = 1 ; i < arrLen - 1; i++)
    {
        sum += arr[i];
    }
    
    float average = (float)sum / (float)(arrLen - 2);

    fprintf(stdout, "%.2f\n", average);

    free(arr);
    arr = NULL;

    return 0;
}