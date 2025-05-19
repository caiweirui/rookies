bool hasAlternatingBits(int n) {
    int i = 0;
    int temp = n;
    while(temp > 2)
    {
        temp = temp >> 1;
        if(((n >> i) & 1) == ((n >> (i + 1)) & 1))
            return 0;
        i++;
    }
    return 1;
}