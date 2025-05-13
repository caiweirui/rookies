/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ret = (int*)calloc(nums1Size, sizeof(int));
    int i = 0;
    int j = 0;
    int temp = 0;
    int *arr = (int*)calloc(10001, sizeof(int));
    for(i = 0; i < nums2Size; i++)
    {
        temp = nums2[i];
        for(j = i + 1; j < nums2Size; j++)
        {
            if(nums2[j] > temp)
            {
                temp = nums2[j];
                arr[nums2[i]] = nums2[j];
                break;
            }
        }
        if(temp == nums2[i])
        {
            arr[nums2[i]] = -1;
        }
    }
    for(i = 0; i < nums1Size; i++)
    {
        ret[i] = arr[nums1[i]];
    }
    *returnSize = nums1Size;
    return ret;
}