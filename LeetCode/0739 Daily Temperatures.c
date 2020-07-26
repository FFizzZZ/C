#include <stdio.h>
#include <stdlib.h>

/* from tail to head */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    int *ret = calloc(TSize, sizeof(int));
    int *stack = malloc(sizeof(int) * TSize);
    int top = -1, val;
    for (int i = TSize - 1; i >= 0; i--) {
        while (top > -1 && T[i] >= T[stack[top]])
            top--;
        if (top > -1)
            ret[i] = stack[top] - i;
        stack[++top] = i;
    }
    return ret;
}

/* from head to tail */
int* dailyTemperatures(int* T, int TSize, int* returnSize) {
    int top = -1;
    int *stack = calloc(TSize, sizeof(int));
    int *ret = calloc(TSize, sizeof(int));
    *returnSize = TSize;
    for (int i = 0; i < TSize; i++) {
        while (top >= 0 && T[stack[top]] < T[i])
            ret[stack[top--]] = i - stack[top];
        stack[++top] = i;
    }
    return ret;
}


/* test case */
int main() {
    int T[8] = { 73, 74, 75, 71, 69, 72, 76, 73 };
    int a = 8;
    int *ans = dailyTemperatures(T, 8, &a);
    for (int i = 0; i < 8; i++)
        printf("%d\n", ans[i]);
}