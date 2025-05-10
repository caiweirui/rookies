bool canWinNim(int n) {
    if(n <= 3)
    {
        return 1;
    }
    if(n % 4 == 0)
    {
        return 0;
    }
    return 1;
}