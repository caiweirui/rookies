int arrangeCoins(int n) {
    int ret = 0;
    if(n == 1)
    {
        return 1;
    }
    while(n > 0)
    {
        n = n - ret - 1;
        ret++;
    }
    return ret - (n != 0);
}