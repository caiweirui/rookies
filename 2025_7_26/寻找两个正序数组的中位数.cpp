double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 保证nums1Size <= nums2Size
    if(nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    // 二分查找，找到左边应该有的数字个数
    int left = 0;
    int right = nums1Size;
    int totalLeft = (nums1Size + nums2Size + 1) / 2;

    int i = 0;
    int j = 0;
    while(left < right)
    {
        i = left + (right - left) / 2;
        j = totalLeft - i;
        if(nums1[i] > nums2[j - 1])
        {
            right = i;
        }
        else
        {
            left = i + 1;
        }
    }

    i = left;
    j = totalLeft - i;
    
    // 处理边界情况
    int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
    int nums1RightMin = (i == nums1Size) ? INT_MAX : nums1[i];
    int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
    int nums2RightMin = (j == nums2Size) ? INT_MAX : nums2[j];
    
    // 计算左右部分极值
    int leftMax = fmax(nums1LeftMax, nums2LeftMax);
    int rightMin = fmin(nums1RightMin, nums2RightMin);
    
    // 根据总元素数量返回中位数
    if ((nums1Size + nums2Size) % 2 == 1) {
        return leftMax;  // 奇数情况
    } else {
        return (leftMax + rightMin) / 2.0;  // 偶数情况
    }
}