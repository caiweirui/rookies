#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_SEQUENCE 100000
enum
{
    __FIFS__ = 1,
    __SSTF__,
    __SCAN__,
    __CSCAN__
};

void strToInt(const char* sequence, int* arr, int* arrLen)
{
    int i = 0;
    int sequenceLen = strlen(sequence);
    for(i = 0; i < sequenceLen; i++)
    {
        while(1)
        {
            if(sequence[i] == ',' || sequence[i] == '\0')
            {
                break;
            }
            arr[*arrLen] = arr[*arrLen] * 10 + (sequence[i++] - '0');
        }
        *arrLen = *arrLen + 1;
    }
}

void FIFS(int begin, const char* sequence, char* retArr, int* retNum)
{
    int sequenceLen = strlen(sequence);
    int arr[10000] = {begin};
    int arrLen = 1;
    int i = 0;
    int retLen = strlen(retArr);
    memcpy(retArr + retLen, sequence, sequenceLen);
    strToInt(sequence, arr, &arrLen);
    for(i = 1; i < arrLen; i++)
    {
        *retNum += (int)abs(arr[i] - arr[i - 1]);
    }
}

void SSTF(int begin, const char* sequence, char* retArr, int* retNum)
{
    int arr[10000] = {0};
    int arrLen = 1;
    int i = 0;
    int temp = 0;
    int min = 0;
    int flag = 0;
    strToInt(sequence, arr, &arrLen);
    while(flag != -1)
    {
        min = MAX_SEQUENCE;
        flag = -1;
        for(i = 0; i < arrLen; i++)
        {
            temp = (int)abs(arr[i] - begin);
            if(temp < min && arr[i] != 0)
            {
                min = temp;
                flag = i;
            }
        }
        if(flag != -1)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[flag]);
            retArr[strlen(retArr)] = ',';
            begin = arr[flag];
            arr[flag] = 0;
            *retNum += min;
        }
    }
    retArr[strlen(retArr) - 1] = '\0';
}

int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1 - *(int*)e2);
}

void SCAN(int begin, const char* sequence, char* retArr, int* retNum, int direction)
{
    int arr[10000] = {begin};
    int arrLen = 1;
    int i = 0;
    int flag = 0;
    strToInt(sequence, arr, &arrLen);
    qsort(arr, arrLen, sizeof(int), cmp);
    while(arr[flag] != begin)
    {
        flag++;
    }
    if(direction == 1)
    {
        for(i = flag + 1; i < arrLen; i++)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[i]);
            retArr[strlen(retArr)] = ',';
            *retNum += (int)abs(arr[i] - arr[i - 1]);
        }
        for(i = flag - 1; i >= 0; i--)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[i]);
            retArr[strlen(retArr)] = ',';
            if(i == flag - 1)
            {
                *retNum += (int)abs(arr[arrLen - 1] - arr[i]);
            }
            else
            {
                *retNum += (int)abs(arr[i + 1] - arr[i]);
            }
        }
    }
    else
    {
        for(i = flag - 1; i >= 0; i--)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[i]);
            retArr[strlen(retArr)] = ',';
            *retNum += (int)abs(arr[i + 1] - arr[i]);
        }
        for(i = flag + 1; i < arrLen; i++)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[i]);
            retArr[strlen(retArr)] = ',';
            if(i == flag + 1)
            {
                *retNum += (int)abs(arr[0] - arr[i]);
            }
            else
            {
                *retNum += (int)abs(arr[i - 1] - arr[i]);
            }
        }
    }
    retArr[strlen(retArr) - 1] = '\0';
}

void CSCAN(int begin, const char* sequence, char* retArr, int* retNum, int direction)
{
    int arr[10000] = {begin};
    int arrLen = 1;
    int flag = 0;
    strToInt(sequence, arr, &arrLen);
    qsort(arr, arrLen, sizeof(int), cmp);
    memmove(arr + arrLen, arr, arrLen * sizeof(int));
    while(arr[flag] != begin)
    {
        flag++;
    }
    if(direction == 1)
    {
        while(arr[++flag] != begin)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[flag]);
            retArr[strlen(retArr)] = ',';
            *retNum += (int)abs(arr[flag] - arr[flag - 1]);
        }
    }
    else
    {
        flag++;
        while(arr[flag] != begin)
        {
            flag++;
        }
        while(arr[--flag] != begin)
        {
            sprintf(retArr + strlen(retArr), "%d", arr[flag]);
            retArr[strlen(retArr)] = ',';
            *retNum += (int)abs(arr[flag + 1] - arr[flag]);
        }
    }
    retArr[strlen(retArr) - 1] = '\0';
}

int main()
{
    int option = 0;
    int begin = 0;
    int direction = 0;
    char *sequence = (char*)calloc(MAX_SEQUENCE, sizeof(char));
    char *retArr = (char*)calloc(MAX_SEQUENCE, sizeof(char));
    int retNum = 0;
    fscanf(stdin, "%d", &option);
    getchar();
    fscanf(stdin, "%d", &begin);
    getchar();
    fscanf(stdin, "%d", &direction);
    getchar();
    sequence = fgets(sequence, MAX_SEQUENCE, stdin);
    sequence[strlen(sequence) - 1] = '\0';

    sprintf(retArr, "%d", begin);
    retArr[strlen(retArr)] = ',';

    switch (option)
    {
    case __FIFS__:
        FIFS(begin, sequence, retArr, &retNum);
        break;
    case __SSTF__:
        SSTF(begin, sequence, retArr, &retNum);
        break;
    case __SCAN__:
        SCAN(begin, sequence, retArr, &retNum, direction);
        break;
    case __CSCAN__:
        CSCAN(begin, sequence, retArr, &retNum, direction);
        break;
    default:
        break;
    }

    fprintf(stdout, "%s\n", retArr);
    fprintf(stdout, "%d\n", retNum);

    free(sequence);
    sequence = NULL;
    free(retArr);
    retArr = NULL;

    return 0;
}