#include<stdio.h>
int subarraySum(int* nums, int numsSize, int k)
{
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        int sum=0;
        for(int j=i;j<numsSize;j++)
        {
            sum+=nums[j];
            if(sum==k)
            {
                count++;
            }
        }
    }
}
int main() {
    int nums[] = {1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    int result = subarraySum(nums, numsSize, k);
    printf("Output: %d\n", result); 
    return 0;
}