int cmp(const void* e1, const void* e2) { return (*(int*)e1 - *(int*)e2); }

int majorityElement(int* nums, int numsSize) {
    int half = numsSize / 2;
    int i = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    int left = 0;
    int right = 0;
    int flag = 0;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1] || i == numsSize - 1) {
            right = i;
            flag = 1;
        }
        if (right - left + 1 > half) {
            return nums[left];
        }
        if (flag) {
            left = i + 1;
            flag = 0;
        }
    }
    return nums[i];
}