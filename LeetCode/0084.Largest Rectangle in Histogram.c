/* Dynamic Programming */
int largestRectangleArea(int* heights, int heightsSize){
    if (heightsSize == 0)
        return 0;

    int l[heightsSize], r[heightsSize];
    l[0] = -1;
    r[heightsSize - 1] = heightsSize;

    int i, j;
    for (i = 0; i < heightsSize; i++) {
        j = i - 1;
        while (j > -1 && heights[j] >= heights[i])
            j = l[j];
        l[i] = j;
    }

    for (i = heightsSize - 1; i >= 0; i--) {
        j = i + 1;
        while (j < heightsSize && heights[j] > heights[i])
            j = r[j];
        r[i] = j;
    }

    int ans = 0, area = 0;
    for (i = 0; i < heightsSize; i++) {
        area = heights[i] * (r[i] - l[i] - 1);
        if (area > ans)
            ans = area;
    }
    return ans;
}


/* Stack */
int largestRectangleArea(int* heights, int heightsSize) {
    int *tmp = (int *)malloc(sizeof(int) * (heightsSize + 1));
    tmp[heightsSize] = 0;
    for (int i = 0; i < heightsSize; i++)
        tmp[i] = heights[i];

    int *stack = (int *)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1, ans = 0, area, idx, distance;
    for (int i = 0; i < heightsSize + 1; i++) {
        while (top >= 0 && heights[stack[top]] > heights[i])
            idx = stack[top--];
        if (top == -1) {
            distance = i;
        } else {
            distance = i - stack[top] - 1;
        }
        area = heights[idx] * distance;
        if (area > ans)
            ans = area;
        stack[++top] = i;
    }
    return ans;
}