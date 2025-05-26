int isPrime(int num)
{
    int i = 2;
    if(num <= 1)
    {
        return 0;
    }
    if(num <= 3)
    {
        return 1;
    }
    for(i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int count(int num)
{
    int i = 0;
    int ret = 0;
    for(i = 0; i < 32; i++)
    {
        ret += ((num >> i) & 1);
    }
    return ret;
}

int countPrimeSetBits(int left, int right) {
    int i = 0;
    int ret = 0;
    for(i = left; i <= right; i++)
    {
        ret += isPrime(count(i));
    }
    return ret;

}