#include <stdio.h>
#include <stdlib.h>


/* 冒泡排序 */
void bubbleSort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len; i++)
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}


/* 选择排序 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}


/* 插入排序 */
void insertionSort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}



/* 希尔排序 */
void shellSort(int arr[], int len) {
    int gap, i, j;
    int val;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            val = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > val; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = val;
        }
}


/* 归并排序 递归 */
void mergeSortRecursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start;
    int mid = start + (len >> 1);
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    mergeSortRecursive(arr, reg, start1, end1);
    mergeSortRecursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void mergeSort(int arr[], const int len) {
    int reg[len];
    mergeSortRecursive(arr, reg, 0, len - 1);
}


/* 归并排序 迭代 */
int min(int x, int y) {
    return x < y? x : y;
}

void mergeSortByIter(int arr[], int len) {
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg *= 2) {
        for (start = 0; start < len; start += 2 * seg) {
            int low = start, mid = min(start + seg, len);
            int high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}


/* 快速排序 递归 */
void quickSortByRecursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int val = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < val && left < right)
            left++;
        while (arr[right] >= val && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
//    if (arr[left] >= val)
//        swap(&arr[left], &arr[end]);
//    else
//        left++;
    if (arr[left] < val)
        left++;
    swap(&arr[left], &arr[end]);
    quickSortByRecursive(arr, start, left - 1);
    quickSortByRecursive(arr, left + 1, end);
}

void quickSort(int arr[], int len) {
    quickSortByRecursive(arr, 0, len - 1);
}


/* 快速排序 迭代 */
typedef struct {
    int start, end;
} Range;

Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

void quickSortByIter(int arr[], const int len) {
    if (len <= 0)
        return;
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right) {
            while (arr[left] < mid && left < right)
                left++;
            while (arr[right] >= mid && left < right)
                right--;
            swap(&arr[left], &arr[right]);
        }
        if (arr[left] < mid)
            left++;
        swap(&arr[left], &arr[range.end]);

        if (range.start < left - 1)
            r[p++] = new_Range(range.start, left - 1);
        if (left + 1 < range.end)
            r[p++] = new_Range(left + 1, range.end);
    }
//    while (p) {
//        Range range = r[--p];
//        if (range.start >= range.end)
//            continue;
//        int mid = arr[(range.start + range.end) / 2];
//        int left = range.start, right = range.end - 1;
//        do {
//            while (arr[left] < mid)
//                left++;
//            while (arr[right] < mid)
//                right--;
//            if (left <= right) {
//                swap(&arr[left], &arr[right]);
//                left++;
//                right--;
//            }
//        } while (left <= right);
//        if (range.start < right) r[p++] = new_Range(range.start, right);
//        if (range.end > left) r[p++] = new_Range(left, range.end);
//    }
}

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubbleSort(arr, len);
//    selectionSort(arr, len);
//    insertionSort(arr, len);
//    shellSort(arr, len);
//    mergeSort(arr, len);
//    mergeSortByIter(arr, len);
//    quickSort(arr, len);
    quickSortByIter(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}