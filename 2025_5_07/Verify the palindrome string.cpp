bool isPalindrome(char* s) {
    int len = strlen(s);
    char *left = s;
    char *right = s + len - 1;
    if(len <= 1)
    {
        return true;
    }
    while(left < right)
    {
        while((!isalpha(*left) && !isdigit(*left)) && left < right)
        {
            left++;
        }
        while((!isalpha(*right) && !isdigit(*right)) && left < right)
        {
            right--;
        }
        if(toupper(*left) != toupper(*right))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}