#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    int *ret = (int *)malloc(sizeof(int) * TSize);
    int *stack = (int *)malloc(sizeof(int) * TSize);
    int top = -1, val;
    for (int i = TSize - 1; i >= 0; i--) {
        while (top > -1 && T[i] >= T[stack[top]])
            top--;
        if (top > -1)
            ret[i] = stack[top] - i;
        else
            ret[i] = 0;
        stack[++top] = i;
    }
    return ret;
}

int* dailyTemperatures(int* T, int TSize, int* returnSize) {
    int top = -1;
    int *stack = calloc(TSize, sizeof(int));
    int *ret = calloc(TSize, sizeof(int));
    *returnSize = TSize;
    for (int i = 0; i < TSize - 1; i++) {
        if (T[i] < T[i + 1]) {
            ret[i] = 1;
            while (top >= 0 && T[stack[top]] < T[i + 1])
                ret[stack[top--]] = i + 1 - stack[top];
        } else {
            stack[++top] = i;
        }
    }
    return ret;
}


/* 测试用例 */
int main() {
    int T[8] = { 73, 74, 75, 71, 69, 72, 76, 73 };
    int a = 8;
    int *ans = dailyTemperatures(T, 8, &a);
    for (int i = 0; i < 8; i++)
        printf("%d\n", ans[i]);
}