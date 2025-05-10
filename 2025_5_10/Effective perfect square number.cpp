bool isPerfectSquare(int num) {
    if(num == 1)
    {
        return 1;
    }
    int left = 0;
    int right = 46340;
    int mid = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(mid * mid == num)
        {
            return mid;
        }
        else if(mid * mid > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}