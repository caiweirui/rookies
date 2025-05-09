// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long left = 1;
    long long right = n;
    long long mid = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(isBadVersion(mid) == 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return (int)mid + !isBadVersion(mid);
}