void moveZeroes(int* nums, int numsSize) {
    int *p1 = nums;
    int *p2 = nums;
    int count = 0;
    while(p1 - nums < numsSize)
    {
        if(*p1 != 0)
        {
            *p2++ = *p1++; 
            count++;
        }
        else
        {
            p1++;
        }
    }
    memset(nums + count, 0, sizeof(int) * (numsSize - count));
}