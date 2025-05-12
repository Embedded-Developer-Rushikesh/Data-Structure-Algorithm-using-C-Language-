#include <stdio.h>
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int ArraySum = (numsSize * (numsSize + 1)) / 2;
    return ArraySum - sum;
}

int main() {
    int nums1[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: Missing number is %d\n", missingNumber(nums1, size1));
    return 0;
}