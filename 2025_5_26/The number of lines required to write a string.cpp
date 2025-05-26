/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    *returnSize = 2;
    int* ret = (int*)calloc(*returnSize, sizeof(int));
    ret[0] = 1;
    int sLen = strlen(s);
    int page = 100;
    int i = 0;
    for(i = 0; i < sLen; i++)
    {
        while(page >= 0 && i < sLen)
        {
            page -= widths[s[i++] - 'a'];
        }
        if(i == sLen)
        {
            if(page >= 0)
            {
                ret[1] = 100 - page;
            }
            else
            {
                ret[0]++;
                ret[1] = widths[s[sLen - 1] - 'a'];
            }
            break;
        }
        i -= 2;
        page = 100;
        ret[0]++;
    }
    return ret;
}