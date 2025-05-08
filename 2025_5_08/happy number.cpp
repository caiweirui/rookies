bool isHappy(int n) {
    int temp = 0;
    bool ret = false;
    int count = 0;
    do{
        temp = n;
        n = 0;
        while(temp)
        {
            n += (temp % 10) * (temp % 10);
            temp /= 10;
        }
        count++;
        if(count > 100000)
        {
            return false;
        }
    }while(n != 1);
    return true;
}