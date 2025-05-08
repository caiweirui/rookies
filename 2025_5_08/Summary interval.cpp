#include <stdio.h>
#include <stdlib.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 第一次遍历统计区间数目
    int count = 0;
    int i = 0;
    while (i < numsSize) {
        count++;
        int j = i;
        while (j + 1 < numsSize && nums[j + 1] == nums[j] + 1) {
            j++;
        }
        i = j + 1;
    }

    // 分配结果数组
    char** result = (char**)malloc(count * sizeof(char*));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 第二次遍历填充区间字符串
    i = 0;
    int resultIndex = 0;
    while (i < numsSize) {
        int start = nums[i];
        int end = start;
        int j = i;
        while (j + 1 < numsSize && nums[j + 1] == nums[j] + 1) {
            j++;
            end = nums[j];
        }

        // 生成字符串
        char* s;
        if (start == end) {
            int len = snprintf(NULL, 0, "%d", start) + 1;
            s = (char*)malloc(len);
            snprintf(s, len, "%d", start);
        } else {
            int len = snprintf(NULL, 0, "%d->%d", start, end) + 1;
            s = (char*)malloc(len);
            snprintf(s, len, "%d->%d", start, end);
        }

        result[resultIndex++] = s;
        i = j + 1;
    }

    *returnSize = count;
    return result;
}