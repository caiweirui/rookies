char* convertToBase7(int num) {
    char* ret = (char*)calloc(20, sizeof(char));
    int retLen = 0;
    int sf = 0;
    if(num == 0)
    {
        *ret = '0';
        return ret;
    }
    if(num < 0)
    {
        sf = 1;
        num = -num;
    }
    int i = 0;
    while(num)
    {
        ret[retLen++] = num % 7 + '0';
        num = num / 7;
    }
    if(sf)
    {
        ret[retLen++] = '-';
    }
    int left = 0;
    int right = retLen - 1;
    char temp = 0;
    while(left < right)
    {
        temp = ret[left];
        ret[left] = ret[right];
        ret[right] = temp;
        left++;
        right--;
    }
    return ret;
}