#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ret = malloc(numsSize * sizeof(int));
    int *stack = malloc(numsSize * sizeof(int));
    if (numsSize == 0)
        return ret;
    int tmp[2 * numsSize], i, top = -1;
    for (i = 0; i < numsSize; i++)
        tmp[i] = nums[i];
    for (i = numsSize; i < 2 * numsSize; i++)
        tmp[i] = nums[i - numsSize];
    for (i = 0; i < numsSize; i++)
        ret[i] = -1;
    for (i = 0; i < 2 * numsSize; i++) {
        while (top > -1 && nums[stack[top]] < tmp[i])
            ret[stack[top--]] = tmp[i];
        if (i < numsSize)
            stack[++top] = i;
    }
    return ret;
}