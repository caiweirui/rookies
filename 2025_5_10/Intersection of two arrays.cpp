#include<bits/stdc++.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *e1, const void *e2)
{
    return (*(int*)e1 - *(int*)e2);
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

void duplicateRemoval(int *arr, int* sz)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < *sz - 1; i++)
    {   
        if(arr[i] == arr[i + 1])
        {
            for(j = i + 1; j < *sz - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            *sz = *sz - 1;
            i--;
        }
    }
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    duplicateRemoval(nums1, &nums1Size);
    duplicateRemoval(nums2, &nums2Size);

    int len1 = 0;
    int len2 = 0;
    int count = 0;
    int *ret = (int*)malloc(min(nums1Size, nums2Size) * sizeof(int));

    while(len1 < nums1Size && len2 < nums2Size)
    {
        if(len1 < nums1Size && len2 < nums2Size && nums1[len1] < nums2[len2])
        {
            len1++;
        }
        if(len1 < nums1Size && len2 < nums2Size && nums1[len1] > nums2[len2])
        {
            len2++;
        }
        if(len1 < nums1Size && len2 < nums2Size && nums1[len1] == nums2[len2])
        {
            ret[count++] = nums1[len1];
            len1++;
            len2++;
        }

    }

    *returnSize = count;

    return ret;
}

// hash表法
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//     int minsize = nums1Size > nums2Size ? nums2Size : nums1Size;
//     int temp[1001] = {0};
//     int i = 0;
//     int count = 0;
//     int *ret = (int*)malloc(minsize * sizeof(int));
//     for(i = 0; i < nums1Size; i++)
//     {
//         temp[nums1[i]]++;
//     }
//     for(i = 0; i < nums2Size; i++)
//     {
//         if(temp[nums2[i]] > 0)
//         {
//             ret[count++] = nums2[i];
//             temp[nums2[i]]--;
//         }
//     }
//     *returnSize = count;
//     return ret;
// }

int main()
{
    int nums1[] = {4,9,5};
    int nums2[] = {9,4,9,8,4};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnsize = 0;
    int* ret = intersection(nums1, len1, nums2, len2, &returnsize);
    int i = 0;
    for(i = 0; i < returnsize; i++)
    {
        fprintf(stdout, "%d ", ret[i]);
    }
    fprintf(stdout, "\n");
    return 0;
}