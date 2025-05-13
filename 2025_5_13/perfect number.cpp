bool checkPerfectNumber(int num) {
    if(num == 1)
    {
        return 0;
    }
    int* arr = (int*)calloc(num, sizeof(int));
    int arrLen = 0;
    int i = 0;
    int sum = 0;
    for(i = 1; i < (int)sqrt(num) + 1; i++)
    {
        if(num % i == 0)
        {
            arr[arrLen++] = i;
            if(i != num / i && i != 1)
            {
                arr[arrLen++] = num / i;
            }
        }
    }
    for(i = 0; i < arrLen; i++)
    {
        sum += arr[i];
    }
    return (sum == num);
}