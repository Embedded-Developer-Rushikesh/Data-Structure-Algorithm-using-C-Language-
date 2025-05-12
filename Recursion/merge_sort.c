#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = (int*)malloc(n1 * sizeof(int));
    int* right = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        left[i] = nums[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        nums[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        nums[k] = right[j];
        j++;
        k++;
    }
    free(left);
    free(right);
}

void mergeSort(int* nums, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {12, 11, 13, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    printf("Original array: ");
    printArray(nums, numsSize);

    int* sorted = sortArray(nums, numsSize, &returnSize);

    printf("Sorted array: ");
    printArray(sorted, returnSize);

    return 0;
}