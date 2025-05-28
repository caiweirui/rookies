int binaryGap(int n) {
    int arr[33] = {0};
    int i = 0;
    int j = 0;
    int count = 0;
    int ret = 0;
    for(i = 0; i < 32; i++)
    {
        arr[i] = ((n >> i) & 1);
    }
    for(i = 0; i < 32; i++)
    {
        if(arr[i])
        {
            count++;
        }
    }
    if(count <= 1)
    {
        return 0;
    }

    for(i = 0; i < 32; i++)
    {
        if(arr[i])
        {
            count = 1;
            for(j = i + 1; j < 32; j++)
            {
                if(arr[j] == 0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(arr[j] == 1 && count > ret)
            {
                ret = count;
            }
        }
    }
    return ret;
}