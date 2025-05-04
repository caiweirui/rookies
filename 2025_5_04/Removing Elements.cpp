int removeElement(int* nums, int numsSize, int val) {
    int *p1 = nums;
    int *p2 = nums;
    int ret = 0;
    while((p2 - nums) < numsSize)
    {
        if(*p2 != val)
        {
            *p1++ = *p2++;
            ret++;
        }
        else
        {
            p2++;
        }
    }
    return ret;

}