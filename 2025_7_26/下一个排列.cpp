void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    // 1. 从后向前找到第一个升序位置i
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    // 2. 如果找到升序位置i
    if (i >= 0) {
        // 从后向前找到第一个大于nums[i]的位置j
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        // 交换nums[i]和nums[j]
        swap(&nums[i], &nums[j]);
    }
    
    // 3. 反转i+1到末尾的序列
    reverse(nums, i + 1, numsSize - 1);
}