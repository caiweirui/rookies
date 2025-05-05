int cmp(const void *e1, const void *e2)
{
    return ((*(int*)e1) - (*(int*)e2));
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    memmove(nums1 + m, nums2, n * sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), cmp);
} 