void X(int* arr, int* arrLen, int x)
{
    arr[*arrLen] = x;
    *arrLen = *arrLen + 1;
}

void Add(int *arr, int* arrLen)
{
    arr[*arrLen] = arr[*arrLen - 1] + arr[*arrLen - 2];
    *arrLen = *arrLen + 1;
}

void D(int *arr, int* arrLen)
{
    arr[*arrLen] = arr[*arrLen - 1] * 2;
    *arrLen = *arrLen + 1;
}

void C(int *arr, int* arrLen)
{
    *arrLen = *arrLen - 1;
}

int calPoints(char** operations, int operationsSize) {
    int i = 0;
    int* arr = (int*)calloc(1001, sizeof(int));
    int arrLen = 0;
    int temp = 0;
    int ret = 0;
    for(i = 0; i < operationsSize; i++)
    {
        if(operations[i][0] == '+')
        {
            Add(arr, &arrLen);
            continue;
        }
        if(operations[i][0] == 'C')
        {
            C(arr, &arrLen);
            continue;
        }
        if(operations[i][0] == 'D')
        {
            D(arr, &arrLen);
            continue;
        }
        temp = atoi(operations[i]);
        X(arr, &arrLen, temp);
    }
    for(i = 0; i < arrLen; i++)
    {
        ret += arr[i];
    }
    return ret;
}