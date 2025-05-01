bool isPalindrome(int x) {
    if(x < 0)
    {
        return false;
    }
    else
    {
        int i = 0;
        char arr[40] = {0};
        while(x)
        {
            arr[i++] = x % 10;
            x = x / 10;
        }
        int j = 0;
        for(j = 0; j < i; j++)
        {
            if(arr[j] != arr[i - j - 1])
            {
                return false;
            }
        }
        return true;
    }

}