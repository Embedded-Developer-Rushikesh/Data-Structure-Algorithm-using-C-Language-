#include<stdio.h>
int singleNonDuplicate(int* nums, int numsSize)
{
    int n=numsSize;
    if(n==1)
    {
        return nums[0];
    }
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid==0 && nums[0]!=nums[1]) return nums[mid]; 
        if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[mid];
      if(nums[mid]!=nums[mid+1]&& nums[mid]!=nums[mid-1]) return nums[mid];
        if(mid%2==0)
        {
            if(nums[mid]==nums[mid-1]) end=mid;
            else start=mid+1;
        }else{
            if(nums[mid]==nums[mid-1]) start=mid+1;
            else  end=mid;
        }

    }
    return -1;
}
int main() {
    int nums1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = singleNonDuplicate(nums1, size1);
    printf("Input: nums = [1,1,2,3,3,4,4,8,8]\nOutput: %d\n\n", result1);

    return 0;
}