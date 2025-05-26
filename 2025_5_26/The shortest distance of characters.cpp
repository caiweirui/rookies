/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    int i = 0;
    int left = 0;
    int right = 0;
    int sLen = strlen(s);
    int *ret = (int*)calloc(sLen, sizeof(int));
    *returnSize = sLen;
    for(i = 0; i < sLen; i++)
    {
        left = i;
        right = i;
        while(left > 0 && s[left] != c)
        {
            left--;
        }
        if(s[left] != c)
        {
            left = -10000;
        }
        while(right < sLen - 1 && s[right] != c)
        {
            right++;
        }
        if(s[right] != c)
        {
            right = 10000;
        }
        ret[i] = (right - i) > (i - left) ? (i - left) : (right - i);
    }
    return ret;
}