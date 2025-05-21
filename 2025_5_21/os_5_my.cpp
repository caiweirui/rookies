#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SEQUENCE 100000
enum
{
    __FIFS__ = 1,
    __SSTF__,
    __SCAN__,
    __CSCAN__
};

void strToInt(char* sequence, int* arr, int* arrLen)
{
    int i = 0;
    int sequenceLen = strlen(sequence);
    for(i = 0; i < sequenceLen; i++)
    {
        while(1)
        {
            if(sequence[i] == ',' || i == sequenceLen)
            {
                break;
            }
            arr[*arrLen] = arr[*arrLen] * 10 + (sequence[i++] - '0');
        }
        *arrLen = *arrLen + 1;
    }
}


void FIFS(int begin, char* sequence, char* retArr, int* retNum)
{
    int temp = 0;
    int sequenceLen = strlen(sequence);
    int arr[10000] = {0};
    int arrLen = 0;
    int i = 0;
    memcpy(retArr + 1, sequence, sequenceLen);
    strToInt(sequence, arr, &arrLen);
    for(i = 0; i < arrLen; i++)
    {
        
    }
}


int main()
{
    int option = 0;
    int begin = 0;
    int direction = 0;
    char *sequence = (char*)calloc(MAX_SEQUENCE, sizeof(char));
    char *retArr = (char*)calloc(MAX_SEQUENCE + 1, sizeof(char));
    int retNum = 0;
    fscanf(stdin, "%d", &option);
    getchar();
    fscanf(stdin, "%d", &begin);
    getchar();
    fscanf(stdin, "%d", &direction);
    getchar();
    sequence = fgets(sequence, MAX_SEQUENCE, stdin);
    retArr[0] = begin;
    switch (option)
    {
    case __FIFS__:
        FIFS(begin, sequence, retArr, &retNum);
        break;
    // case __SSTF__:
    //     SSTF();
    //     break;
    // case __SCAN__:
    //     SCAN();
    //     break;
    // case __CSCAN__:
    //     CSCAN();
    //     break;
    // default:
    //     break;
    }

    fprintf(stdout, "%s\n", retArr);
    fprintf(stdout, "%d\n", retNum);

    free(sequence);
    sequence = NULL;
    free(retArr);
    retArr = NULL;

    return 0;
}