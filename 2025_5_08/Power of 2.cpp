bool isPowerOfTwo(int n) {
    return (n>0)&&((n&(n-1))==0);
    
}

bool isPowerOfTwo(int n) {
    if(n <= 0)
    {
        return 0;
    }
    while(n > 1)
    {
        if(n % 2)
        {
            return false;
        }
        n = n / 2;
    }
    return true;
}