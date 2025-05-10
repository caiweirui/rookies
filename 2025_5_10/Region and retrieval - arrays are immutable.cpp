


typedef struct {
    int *preSum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->preSum = (int *)calloc(numsSize + 1, sizeof(int));
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        obj->preSum[i + 1] = obj->preSum[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->preSum[right + 1] - obj->preSum[left]; // 利用前缀和快速计算区间和
}

void numArrayFree(NumArray* obj) {
    if(obj == NULL)
    {
        return;
    }
    else
    {
        free(obj->preSum);
        free(obj);
        obj = NULL;
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/