int removeDuplicates(int* nums, int numsSize) {
    int arr[20000] = {0};
    int i = 0;
    int count = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(arr[nums[i] + 10000] == 0)
        {
            arr[nums[i] + 10000]++;
        }
    }
    for(i = 0; i < numsSize; i++)
    {
        if(arr[nums[i] + 10000] >= 1)
        {
            nums[count++] = nums[i];
            arr[nums[i] + 10000] = 0;
        }
    }
    return count;
}