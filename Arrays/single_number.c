#include<stdio.h>
int singleNumber(int* nums, int numsSize)
{
    int ans=0;
    for(int i=0;i<numsSize;i++)
    {
        ans^=nums[i];
    }
    return ans;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = singleNumber(nums, numsSize);
    printf("The single number is: %d\n", result);

    return 0;
}