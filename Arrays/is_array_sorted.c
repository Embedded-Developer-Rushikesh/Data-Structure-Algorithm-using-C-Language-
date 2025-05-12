#include<stdio.h>
#include<stdbool.h>
bool check(int* nums, int numsSize)
{
    int pivot=0;
    int n=numsSize;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]>nums[i+1])
        {
            pivot=i+1;
            break;
        }
    }
    if(pivot==0)
    {
        return true;
    }
    for(int i=pivot;i<n-1;i++)
    {
        if(nums[pivot]>nums[pivot+1])
        {
            return false;
        }
    }
    return nums[n-1]<=nums[0];
}
int main() {
    int nums1[] = {3, 4, 5, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %s\n", check(nums1, size1) ? "true" : "false");
    return 0;
}