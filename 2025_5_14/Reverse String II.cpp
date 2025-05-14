void reverse(char* arr, int left, int right)
{
    char temp = 0;
    int len = strlen(arr);
    while(left < right && right < len && left >= 0)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    int i = 0;
    for(i = 0; i < len; i += 2 * k)
    {
        if(i + k - 1 >= len)
        {
            reverse(s, i, len - 1);
            break;
        }
        reverse(s, i, i + k - 1);
    }

    return s;
}