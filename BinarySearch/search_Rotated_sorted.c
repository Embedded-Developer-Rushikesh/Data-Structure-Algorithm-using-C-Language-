#include<stdio.h>

int getPivot(int* nums, int start, int end)
{
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]>=nums[0])
        {
            start=mid+1;
        }else{
            end=mid;
        }
    }
    return start;
}

int BinarySearch(int* nums, int start, int end, int target) 
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]<target)
        {
            start=mid+1;
        }else if(nums[mid]>target)
        {
            end=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target)
{
    int n=numsSize-1;
    if(numsSize==0)
    {
        return -1;
    }
    int piot=getPivot(nums,0,n);
    if(piot==0)
    {
        return BinarySearch(nums,0,n,target);
    }
    if(nums[piot]<=target && nums[n]>=target)
    {
        return BinarySearch(nums,piot,n,target);
    }else{
        return BinarySearch(nums,0,piot-1,target);
    }
}
int main() {
    int nums1[] = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = search(nums1, size1, target1);
    printf("Example 1:\nInput: nums = [4,5,6,7,0,1,2], target = 0\nOutput: %d\n\n", result1);
    return 0;
}