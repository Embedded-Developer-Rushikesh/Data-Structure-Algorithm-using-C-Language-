#include<stdio.h>
int getPivot(int* nums, int start, int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
        {
            return mid;
        }else if(nums[mid]<nums[mid+1])
        {
            start=mid+1;
        }else{
            end=mid;
        }

    }
    return -1;
}
int peakIndexInMountainArray(int* arr, int arrSize) {
    return getPivot(arr,1,arrSize-2);
}

int main() {
    int arr1[] = {0,2,1,0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = peakIndexInMountainArray(arr1, size1);
    printf("Example 1:\nInput: arr = [0,2,1,0]\nOutput: %d\n\n", result1);

    return 0;
}