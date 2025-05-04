int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    if(target <= nums[0])
    {
        return 0;
    }
    if(target > nums[numsSize - 1])
    {
        return numsSize;
    }
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(target > nums[mid])
        {
            left = mid + 1;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}