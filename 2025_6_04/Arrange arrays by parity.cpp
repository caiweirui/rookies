/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int *p1 = nums;
    int *p2 = nums + numsSize - 1;
    int temp = 0;
    *returnSize = numsSize;
    while(1)
    {
        while(p1 < p2 && *p1 % 2 == 0)
        {
            p1++;
        }
        while(p1 < p2 && *p2 % 2 == 1)
        {
            p2--;
        }
        if(p1 < p2)
        {
            temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
        else
        {
            break;
        }
    }
    return nums;
}