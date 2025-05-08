#include<bits/stdc++.h>

// int cmp(const void *e1, const void *e2)
// {
//     return (*(int*)e1 - *(int*)e2);
// }

// bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
//     int *num = (int *)calloc(numsSize, sizeof(int));
//     memcpy(num, nums, numsSize * sizeof(int));
//     qsort(num, numsSize, sizeof(int), cmp);
//     int temp = 0;
//     int i = 0;
//     int j = 0;
//     int flag = 0;
//     int left = -1;
//     int right = -1;
//     if(numsSize == 1)
//     {
//         return false;
//     }

//     for(j = 0; j < numsSize - 1; j++)
//     {
//         if(num[j] == num[j + 1])
//         {
//             temp = num[j];
//             flag = 1;
//         }
//         if(flag)
//         {
//             flag = 0;
//             for(i = 0; i < numsSize; i++)
//             {
//                 if(temp == nums[i] && !flag)
//                 {
//                     left = i;
//                     flag = 1;
//                     continue;
//                 }
//                 if(temp == nums[i] && flag)
//                 {
//                     right = i;
//                 }
//                 if(left != -1 && right != -1)
//                 {
//                     if(k >= right - left)
//                     {
//                         return true;
//                     }
//                     else
//                     {
//                         left = right;
//                         right = -1;
//                     }
//                 }
//             }
//             flag = 0;
//         }
//     }
//     return false;
// }

int main()
{
    int nums[] = {1,0,1,1};
    int k = 1;
    int len = sizeof(nums) / sizeof(nums[0]);
    // if(containsNearbyDuplicate(nums, len, k))
    // {
    //     printf("1\n");
    // }
    // else
    // {
    //     printf("0\n");
    // }

    snprintf(NULL, 0,"%d", len);
    return 0;
}
