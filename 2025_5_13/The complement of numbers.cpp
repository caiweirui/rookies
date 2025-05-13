#include<stdio.h>
#include<stdlib.h>

int* ToBinary(int num, int *numLen)
{
    int* ret = (int*)calloc(32, sizeof(int));
    int i = 0;
    *numLen = 32;
    for(i = 0; i < 32; i++)
    {
        ret[i] = ((num >> i) & 1);
    }
    int left = 0;
    int right = 31;
    int temp = 0;
    while(left < right)
    {
        temp = ret[left];
        ret[left] = ret[right];
        ret[right] = temp;
        left++;
        right--;
    }
    while(*ret == 0)
    {
        ret++;
        *numLen = *numLen - 1;
    }
    return ret;
}

int findComplement(int num) {
    int arrLen = 0;
    int* arr = ToBinary(num, &arrLen);
    int i = 0;
    int ret = 0;
    for(i = 0; i < arrLen; i++)
    {
        ret = ret * 2 + !(arr[i]);
    }
    return ret;
}

int main()
{
    int num = 0;
    fscanf(stdin, "%d", &num);
    int ret = findComplement(num);
    return 0;
}